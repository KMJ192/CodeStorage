#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char input;
	cin >> input;

	cout << static_cast<int>(input) << "\n";

	return 0;
}