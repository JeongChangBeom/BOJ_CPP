//boj11729번_하노이 탑 이동 순서_재귀

#include<iostream>
#include<cmath>

using namespace std;

void hanoi(int N, int one, int two, int three) {
	if (N == 1) {
		cout << one << " " << three << '\n';
	}
	else {
		hanoi(N - 1, one, three, two);
		cout << one << " " << three << '\n';
		hanoi(N - 1, two, one, three);
	}
}

int main() {
	int N;
	cin >> N;

	cout << (int)pow(2, N) - 1 << '\n';
	hanoi(N, 1, 2, 3);
}