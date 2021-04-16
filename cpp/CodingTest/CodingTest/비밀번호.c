#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<stdint.h>
#include<stdbool.h>

#define MAX_NAME 21
#define TABLE_SIZE 100001

//address�� password ������ site ����ü ����. �׸��� external chaining���� collision �ذ��ϱ� ���� next �����ͱ���!
typedef struct site {
    char ad[MAX_NAME];
    char pw[MAX_NAME];
    struct site* next;
}site;

//hash table ����
site* hash_table[TABLE_SIZE];

//hash �Լ�
unsigned int hash(char* ad) {
    int length = strnlen(ad, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += ad[i];
        hash_value = hash_value % TABLE_SIZE; //random

    }
    return hash_value;
}

//hash table�� �ִ� �Լ�
bool hash_table_insert(site* s) {
    if (s == NULL) return false;
    int index = hash(s->ad);
    s->next = hash_table[index];
    hash_table[index] = s;
    return true;
}

//���� ã�ƺ� ��, password�� ����ϴ� �Լ�
void hash_table_lookup(char* ad) {
    int index = hash(ad);
    site* tmp = hash_table[index];
    while (tmp != NULL && strncmp(tmp->ad, ad, MAX_NAME) != 0) {
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    else
        printf("%s\n", tmp->pw);
}


//main�Լ�!
int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    //insert�� site ����ü �迭 ����
    site inserted[N];

    //������ scanf�� hash_table_insert�� �־��ش�
    for (int i = 0; i < N; i++) {
        scanf("%s %s", inserted[i].ad, inserted[i].pw);
        hash_table_insert(&inserted[i]);
    }

    //lookup�Լ��� ���
    for (int j = 0; j < M; j++) {
        char find[MAX_NAME];
        scanf("%s", find);
        hash_table_lookup(find);
    }

    return 0;
}
