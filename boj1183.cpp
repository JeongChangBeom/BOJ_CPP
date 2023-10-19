//boj1183번_약속_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		v.push_back(A - B);
	}

	sort(v.begin(), v.end());

	if (N % 2 == 0) {
		cout << v[N / 2] - v[N / 2 - 1] + 1;
	}
	else {
		cout << 1;
	}
}
//수학적 이론이 들어간 정렬문제.
//짝수 일때 n/2이하 n/2-1이상의 모든 정수가 T의 값이 되고, 홀수 일때는 중간값이 1개가 된다.