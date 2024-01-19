//boj2607번_비슷한 단어_구현

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int first_alpha[26];
int next_alpha[26];
string arr[101];

int main() {
	int N;
	cin >> N;

	int result = 0;
	int first_length = 0;
	int next_length = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			for (int j = 0; j < arr[i].size(); j++) {
				first_alpha[arr[i][j] - 'A']++;
			}
			first_length = arr[i].size();
		}
		else {
			for (int j = 0; j < 26; j++) {
				next_alpha[j] = 0;
			}
			next_length = arr[i].size();

			for (int j = 0; j < arr[i].size(); j++) {
				next_alpha[arr[i][j] - 'A']++;
			}

			int same = 0;
			for (int j = 0; j < arr[i].size(); j++) {
				if (next_alpha[arr[i][j] - 'A'] > 0) {
					next_alpha[arr[i][j] - 'A']--;
					same++;
				}
			}
			if (equal(first_alpha, first_alpha + 26, next_alpha)) {
				result++;
			}
			else if (first_length == next_length) {
				if (first_length - 1 == same) {
					result++;
				}
			}
			else if (first_length - 1 == next_length && first_length - 1 == same) {
				cout << "1";
				result++;
			}
			else if (first_length + 1 == next_length && first_length == same) {
				result++;
				cout << "2";
			}
		}
	}

	cout << result;
}