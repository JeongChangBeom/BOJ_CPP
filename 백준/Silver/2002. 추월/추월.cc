//boj2002번_추월_자료구조(맵)

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, int> m;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		m.insert({ s,i });
	}

	vector<string> v;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (m[v[i]] > m[v[j]]) {
				result++;
				break;
			}
		}
	}

	cout << result << '\n';
}