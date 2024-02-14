//boj10798번_세로읽기_구현

#include<iostream>

using namespace std;

char arr[16][16];

int main() {
	int max_size = 0;

	for (int i = 0; i < 5; i++) {
		string str;
		cin >> str;

		if (max_size < str.size()) {
			max_size = str.size();
		}

		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
		}
	}

	for (int i = 0; i < max_size; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] != NULL) {
				cout << arr[j][i];
			}
		}
	}

}