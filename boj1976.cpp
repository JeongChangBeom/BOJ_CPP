//boj1976번_여행 가자_분리집합

#include<iostream>

using namespace std;

int p[1001];

void Make_Set(int x) { 
	p[x] = x;
}

int Find_Set(int x) {
	if (p[x] == x) {
		return x;
	}
	else {
		return p[x] = Find_Set(p[x]);
	}
}

void Union(int x, int y) {
	p[Find_Set(y)] = Find_Set(x);
}

int main() {
	ios::sync_with_stdio(false); //입출력 가속
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; i++) { //도시의 수만큼 도시의 집합 생성
		Make_Set(i);
	}

	int x;
	for (int i = 1; i <= N; i++) { // 연결된 도시를 서로 Union
		for (int j = 1; j <= N; j++) {
			cin >> x;
			if (x == 1) {
				Union(i,j);
			}
		}
	}

	int a,b;
	cin >> a;
	for (int i = 2; i <= M; i++) { // 여행경로대로 여행가능한지 Find_Set을 통해 확인
		cin >> b;
		if (Find_Set(a) != Find_Set(b)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
// 분리집합을 통해 풀 수 있었던 문제. 알고리즘 분류를 보니 그래프로도 풀 수 있는 것 같다.
// 40~41번째줄에서 N과 M을 헷갈려서 괜히 엄청 시간쓴 문제... 다음부턴 변수 확인을 잘하자...