//boj19583번_싸이버개강총회_자료구조

#include<iostream>
#include<map>
#include<string>

using namespace std;

int time_change(string s) {
	return (60 * stoi(s.substr(0, 2))) + stoi(s.substr(3, 2));
}

int main() {
	string S, E, Q;
	cin >> S >> E >> Q;

	int s_time = time_change(S);
	int e_time = time_change(E);
	int q_time = time_change(Q);

	map<string, int> m;

	int result = 0;

	string time, name;

	while (cin >> time >> name) {
		if (time_change(time) <= s_time) {
			m.insert({ name, time_change(time) });
		}

		if (time_change(time) >= e_time && time_change(time) <= q_time) {
			if (m.find(name) != m.end()) {
				result++;
				m.erase(name);
			}
		}
	}

	cout << result;
}