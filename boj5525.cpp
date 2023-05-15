//boj5525번_IOIOI_문자열

#include<iostream>

using namespace std;

int main() {
	int N, M;
	string S;
	cin >> N >> M >> S;

	int result = 0;

	for (int i = 0; i < S.size(); i++) {
		int count = 0;

		if (S[i] == 'O') {
			continue;
		}
		if (S[i] == 'I') {
			while (S[i + 1] == 'O' && S[i + 2] == 'I') {
				count++;

				if (count == N) {
					result++;
					count--;
				}
				i += 2;
			}
		}
	}
	cout << result;
}

//string헤더에 있는 find 함수로 풀면 시간초과가 나는 문제.
//'O'가 나올땐 넘기고 'I'가 나올때 다음 문자가 'O'이고 다다음 문자가 'I'일 경우를 검사해서 해결했다.