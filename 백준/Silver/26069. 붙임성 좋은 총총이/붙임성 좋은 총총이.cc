//boj26069번_붙임성 좋은 총총이_자료구조(맵)

#include<iostream>
#include<map>

using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, bool> m;

	for (int i = 0; i < N; i++) {
		string A, B;
		cin >> A >> B;

		if (A == "ChongChong") {
			m.insert({ A,true });
		}
		else if (B == "ChongChong") {
			m.insert({ B,true });
		}

		if (m[A]) {
			m[B] = true;
		}
		else if (m[B]) {
			m[A] = true;
		}
	}

	int result = 0;

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second) {
			result++;
		}
	}
	cout << result;
}
//맵을 사용한문제.
//2명을 입력받을때, 총총이면 map의 value를 true로 해주고, value가 true인 사람과 만난 상대도 value로 true로 바꿔주고
//맵을 반복문을 통해 순회하면서 value가 true인 개수를 세어주는 식으로 해결했다.