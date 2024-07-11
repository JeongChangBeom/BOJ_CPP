//boj16165번_걸그룹 마스터 준석이_자료구조(맵)

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	map<string, string> m;

	for (int i = 0; i < N; i++) {
		string group;
		cin >> group;

		int num;
		cin >> num;

		for (int j = 0; j < num; j++) {
			string member;
			cin >> member;

			m.insert({ member,group });
		}
	}


	for (int i = 0; i < M; i++) {
		string quiz;
		cin >> quiz;

		int type;
		cin >> type;

		if (type == 0) {
			for (auto it = m.begin(); it != m.end(); it++) {
				if (it->second == quiz) {
					cout << it->first << '\n';
				}
			}
		}
		else if (type == 1) {
			cout << m[quiz] << '\n';
		}
	}
}