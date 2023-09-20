//boj13414번_수강신청_자료구조(해시를 사용한 집합과 맵)

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int K, L;
	cin >> K >> L;

	map<string, int> m;

	for (int i = 1; i <= L; i++) {
		string num;
		cin >> num;
		m[num] = i;
	}

	vector<pair<int, string>> v;
	
	for (auto i = m.begin(); i != m.end(); i++) {
		string num = i->first;
		int seq = i->second;
		v.push_back({ seq,num });
	}

	sort(v.begin(), v.end());

	int size = min((int)v.size(), K);

	for (int i = 0; i < size; i++) {
		cout << v[i].second << '\n';
	}
}
//맵으로 해결할 수 있는 문제. vector를 생성할 때 순번을 first로 두어 sort하는 것이 핵심이다.