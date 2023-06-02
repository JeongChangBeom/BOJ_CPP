//boj7785번_회사에 있는 사람_자료구조(맵)

/* 시간초과
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(string s1, string s2) {
	return s2 < s1;
}

int main() {
	int N;
	cin >> N;

	vector<string> v;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		string cmd;
		cin >> cmd;

		if (cmd == "enter") {
			v.push_back(s);
		}
		else if (cmd == "leave") {
			sort(v.begin(), v.end());
			v.erase(v.begin() + (lower_bound(v.begin(), v.end(), s) - v.begin()));
		}
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

bool compare(string s1, string s2) {
	return s2 < s1;
}

int main() {
	int N;
	cin >> N;

	map<string, string> m;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		string cmd;
		cin >> cmd;

		if (cmd == "enter") {
			m.insert({ s,cmd });
		}
		else if (cmd == "leave") {
			m.erase(s);
		}
	}

	vector<string> v;

	for (auto it = m.begin(); it != m.end(); it++)
	{
		v.push_back(it->first);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}
//처음엔 vector를 이용해서 있는 그대로 구현해봤는데 시간초과가 나서 맵을 이용해서 다시 구현해서 해결했다.