//boj4195번_친구 네트워크_분리집합

#include<iostream>
#include<map>

using namespace std;

int p[200001];
int result[200001];

void Make_Set(int x) { //집합 생성
	p[x] = x;
}

int Find_Set(int x) { //집합에서 부모 찾기
	if (p[x] == x) {
		return x;
	}
	else {
		return p[x] = Find_Set(p[x]);
	}
}

void Union(int x, int y) { //집합 합치면서 집합내 원소 개수 세기
	if (Find_Set(x) != Find_Set(y)) {
		result[Find_Set(x)] += result[Find_Set(y)];
		result[Find_Set(y)] = result[Find_Set(x)];

		p[Find_Set(y)] = Find_Set(x);
	}

	cout << result[Find_Set(x)] << "\n";
}

int main() {
	ios::sync_with_stdio(false); //입출력 가속
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		map<string, int> m;
		int F;
		cin >> F;

		for (int j = 0; j < F * 2; j++) { //초기화
			Make_Set(j);
			result[j] = 1;
		}

		int num = 1;
		for (int j = 0; j < F; j++) { //문자열로 이름을 받아 고유 번호 매기기
			string name1, name2;
			cin >> name1 >> name2;

			if (m[name1] == 0) {
				m[name1] = num++;
			}

			if (m[name2] == 0) {
				m[name2] = num++;
			}

			Union(m[name1], m[name2]);
		}
	}
}
//딱보면 다른 문제들과 별다를게 없어 보이지만, 입력값이 문자열이라 map을 사용해야 되는 문제