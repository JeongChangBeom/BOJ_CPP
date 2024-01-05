//boj25757번_임스와 함께하는 미니게임_자료구조(연관 컨테이너(set))

#include<iostream>
#include<set>

using namespace std;

int main() {
	int N;
	cin >> N;

	char game;
	cin >> game;

	set<string> s;

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;

		s.insert(name);
	}

	if (game == 'Y') {
		cout << s.size() << '\n';
	}
	if (game == 'F') {
		cout << s.size() / 2 << '\n';
	}
	if (game == 'O') {
		cout << s.size() / 3 << '\n';
	}

	return 0;
}
//자료구조 문제.
//vector를 사용해서 풀려다 시간초과가 났다.
//중복된 key를 insert하지않는 set을 사용하면 간단하게 해결할 수 있다.
//핵심은 2명이서 하는 게임은 1명, 3명이서 하는 게임은 2명, 4명이서 하는 게임은 3명만 구하면 임스랑 게임할 수 있다는 점이다.