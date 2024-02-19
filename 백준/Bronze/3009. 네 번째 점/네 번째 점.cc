//boj3009번_네 번째 점_구현

#include<iostream>

using namespace std;

int x[1001];
int y[1001];

int main() {
	for (int i = 0; i < 3; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		x[v1]++;
		y[v2]++;
	}

	for (int i = 0; i < 1001; i++) {
		if (x[i] == 1) {
			cout << i;
		}
	}
	cout << ' ';

	for (int i = 0; i < 1001; i++) {
		if (y[i] == 1) {
			cout << i;
		}
	}
	
}