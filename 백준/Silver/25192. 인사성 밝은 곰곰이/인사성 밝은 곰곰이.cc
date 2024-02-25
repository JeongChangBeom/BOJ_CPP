//boj25192번_인사성 밝은 곰곰이_자료구조(맵)

#include<iostream>
#include<map>

using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, bool> m;

	int result = 0;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "ENTER") {
			m.clear();
		}
		else {
			if (m.find(str) != m.end()) {
				continue;
			}
			else {
				m.insert({ str,true });
				result++;
			}
		}
	}

	cout << result;
}