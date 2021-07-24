#include<iostream>
#include<vector>
#include<map>

using namespace std;

#define MAX 5000

int queue[MAX + 1];
int front = 0;
int rear = 0;
int s = 0;

void enqueue(int item) {
	rear = (rear + 1) % MAX;
	queue[rear] = item;
	s++;
}

// ¿øÇü Å¥ pop
int dequeue() {
	front = (front + 1) % MAX;
	s--;
	return queue[front];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		enqueue(i); 
	}
	int i = 0; 
	cout << "<" << endl;
	while (s != 0) {
		for (int i = 1; i <= k; i++) {
			if (i == k) {
				++i;
				if (i == n) cout << dequeue() << endl;
				else cout << dequeue() << endl;
			}
			else enqueue(dequeue());
		}
	}
	cout << ">" << endl;
	return 0;
}