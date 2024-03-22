//boj12891번_DNA 비밀번호_슬라이딩 윈도우

#include<iostream>
#include<algorithm>

using namespace std;

int arr[4];
int check[4];

int main() {
	int S, P;
	cin >> S >> P;

	string s;
	cin >> s;

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = start + P - 1;
	int result = 0;

	for (int i = start; i <= end; i++) {
		if (s[i] == 'A') {
			check[0]++;
		}
		else if (s[i] == 'C') {
			check[1]++;
		}
		else if (s[i] == 'G') {
			check[2]++;
		}
		else if (s[i] == 'T') {
			check[3]++;
		}
	}

	while (end < S) {
		if (arr[0] <= check[0] && arr[1] <= check[1] && arr[2] <= check[2] && arr[3] <= check[3]) {
			result++;
		}

		if (s[start] == 'A') {
			check[0]--;
		}
		else if (s[start] == 'C') {
			check[1]--;
		}
		else if (s[start] == 'G') {
			check[2]--;
		}
		else if (s[start] == 'T') {
			check[3]--;
		}
		start++;
		end++;

		if (s[end] == 'A') {
			check[0]++;
		}
		else if (s[end] == 'C') {
			check[1]++;
		}
		else if (s[end] == 'G') {
			check[2]++;
		}
		else if (s[end] == 'T') {
			check[3]++;
		}
	}

	cout << result;

}