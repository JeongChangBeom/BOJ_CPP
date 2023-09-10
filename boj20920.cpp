//boj20920번_영단어 암기는 괴로워_자료구조(해시를 사용한 집합과 맵)

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

map<string, int> m;

bool compare(string x, string y) {
	if (x.size() == y.size() && m[x] == m[y]) {
		return x < y;
	}
	if (x.size() != y.size() && m[x] == m[y]) {
		return x.size() > y.size();
	}
	return m[x] > m[y];
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<string> v;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		if (s.size() < M) {
			continue;
		}
		if (m.find(s) == m.end()) {
			m[s] = 0;
			v.push_back(s);
		}
		m[s]++;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++){
		cout << v[i] << '\n';
	}
}
//아래 3가지 조건을 만족시키면 되는 문제
//1. 자주 나오는 단어일수록 앞에 배치한다. (맵을 통해 갯수를 세어준다)
//2. 해당 단어의 길이가 길수록 앞에 배치한다. (size()를 통해 길이를 비교)
//3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다. (sort()를 사용해서 사전순으로 정렬)