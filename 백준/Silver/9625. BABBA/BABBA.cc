//boj9625번_BABBA_dp

#include<iostream>

using namespace std;

int A[45];
int B[45];

int main() {
	int K;
	cin >> K;

	A[0] = 0;
	B[0] = 1;
	A[1] = 1;
	B[1] = 1;

	for (int i = 2; i < K; i++) {
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}

	cout << A[K - 1] << " " << B[K - 1];
}
//dp문제.
//x번 버튼을 누르면 A,B의 개수는 (x-1)번 누른 개수 + (x-2)번 누른 개수가 된다.