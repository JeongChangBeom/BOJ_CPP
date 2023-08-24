//boj8958번_OX퀴즈_구현,문자열

#include <iostream>
using namespace std;

int main() {
	int x;
	string s;
	cin >> x;

	for (int i = 0; i < x; i++) {
		cin >> s;
		int sum = 0;
		int count = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'O') {
				count += 1;
			}
			else {
				count = 0;
			}
			sum += count;
		}
		cout << sum << endl;
	}
}
//간단한 문자열 문제. 0이 연속으로 나오면 count에 점수를 누적시키면서 점수를 합쳐주는 식으로 해결했다.