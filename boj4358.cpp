//boj4358번_생태학_자료구조(map)

#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	map<string, float>m;
	string s;
	float cnt = 0;

	while (getline(cin, s)) {
		cnt++;

		if (m.find(s) != m.end()) {
			m[s] += 1;
		}
		else {
			m[s] = 1;
		}
	}

	cout << fixed;
	cout.precision(4);

	for (auto it = m.begin(); it != m.end(); it++) {
		float rate = (it->second / cnt) * 100;
		cout << it->first << " ";
		cout << rate << '\n';
	}
	return 0;
}
//map을 이용해서 풀 수 있는 문제 while문의 종료를 eof를 받아서 처리하는 것이 핵심이다.