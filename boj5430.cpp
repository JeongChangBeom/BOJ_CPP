//boj5430번_AC_구현,자료구조

#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int k = 0; k < T; k++) {
		string p;
		int n;
		string s;
		deque<int> d;
		bool reverse = false;
		bool error = false;
		
		cin >> p;
		cin >> n;
		cin >> s;

		string num = "";

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[') {
				continue;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				num += s[i];
			}
			else if (s[i] == ',' || s[i] == ']') {
				if (!num.empty()) {
					d.push_back(stoi(num));
					num = "";
				}
			}
		}

		for (int i = 0; i < p.size(); i++) {
			switch (p[i])
			{
			case 'R':
				if (reverse) {
					reverse = false;
				}
				else {
					reverse = true;
				}
				break;
			case 'D':
				if (d.empty()) {
					error = true;
					break;
				}
				else if(reverse){
					d.pop_back();
				}
				else if (!reverse) {
					d.pop_front();
				}
				break;
			default:
				break;
			}
		}

		if (d.empty() && error) {
			cout << "error" << '\n';
		}
		else if(reverse) {
			cout << '[';
			for (int i = d.size()-1; i >= 0; i--) {
				cout << d[i];
				if (!(i == 0)) {
					cout << ',';
				}
			}
			cout << ']' << '\n';
		}
		else if (!reverse) {
			cout << '[';
			for (int i = 0; i < d.size(); i++) {
				cout << d[i];
				if (!(i == d.size() - 1)) {
					cout << ',';
				}
			}
			cout << ']' << '\n';
		}
	}
}

//자료구조 deque를 사용해서 풀 수 있는 문제. 'R'을 algorithm헤더 파일에 reverse함수로 구현 했더니 시간초과가 났었고
//배열을 입력받은후 [ , ]를 처리하는 부분에 있어서 많은 신경을 써줘야했다. 