//boj17219번_비밀번호 찾기_자료 구조(맵)

#include<iostream>
#include<map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	map<string, string> site;

	for (int i = 0; i < N; i++) {
		string name;
		string password;

		cin >> name;
		cin >> password;

		site.insert(make_pair(name, password));
	}
	

	for (int i = 0; i < M; i++) {
		string key;
		cin >> key;

		cout << site[key] << "\n";
	}
}
//맵의 기초를 다루는 문제. 맵이라는 자료구조를 사용할 수 있고,
//맵의 특성에 따라 key값을 통해 value값을 찾을 수 있으면 쉽게 풀 수 있는 문제.