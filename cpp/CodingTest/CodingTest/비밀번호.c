#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<stdint.h>
#include<stdbool.h>

#define MAX_NAME 21
#define TABLE_SIZE 100001

//address와 password 포함한 site 구조체 선언. 그리고 external chaining으로 collision 해결하기 위해 next 포인터까지!
typedef struct site {
    char ad[MAX_NAME];
    char pw[MAX_NAME];
    struct site* next;
}site;

//hash table 선언
site* hash_table[TABLE_SIZE];

//hash 함수
unsigned int hash(char* ad) {
    int length = strnlen(ad, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += ad[i];
        hash_value = hash_value % TABLE_SIZE; //random

    }
    return hash_value;
}

//hash table에 넣는 함수
bool hash_table_insert(site* s) {
    if (s == NULL) return false;
    int index = hash(s->ad);
    s->next = hash_table[index];
    hash_table[index] = s;
    return true;
}

//값을 찾아본 후, password를 출력하는 함수
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


//main함수!
int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    //insert될 site 구조체 배열 선언
    site inserted[N];

    //값들을 scanf와 hash_table_insert로 넣어준다
    for (int i = 0; i < N; i++) {
        scanf("%s %s", inserted[i].ad, inserted[i].pw);
        hash_table_insert(&inserted[i]);
    }

    //lookup함수로 출력
    for (int j = 0; j < M; j++) {
        char find[MAX_NAME];
        scanf("%s", find);
        hash_table_lookup(find);
    }

    return 0;
}
