//boj1269번_대칭 차집합_자료구조<맵>

#include<iostream>
#include<map>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	map<int, bool> m;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		m.insert({ x,true });
	}

	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		if (m.count(x) != 0) {
			m.erase(x);
		}
		else {
			m.insert({ x,true });
		}
	}

	cout << m.size();
}
//map을 사용해서 풀 수 있는 문제. 처음에 집합A를 입력 받고 집합 B의 값을 입력 받으면서 집합A에 존재하는 값이면
//집합 A에서 삭제하고 없으면 집합A에 추가한후에 집합A에 몇개의 원소가 있는지 출력하여 해결했다.