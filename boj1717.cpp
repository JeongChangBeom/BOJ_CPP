//boj1717번_집합의표현_분리집합

#include<iostream>

using namespace std;

int p[1000001];

void Make_Set(int x) { //
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

	int n, m;
	int x, a, b;

	cin >> n >> m;

	for (int i = 0; i <= n; i++) { //0~n까지 각각의 집합생성
		Make_Set(i);
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> a >> b;
		if (x == 0) {
			Union(a, b);
		}
		else if (x == 1) {
			if (Find_Set(a) == Find_Set(b)) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}
}
//트리를 이용한 집합처리로 풀 수 있는 문제