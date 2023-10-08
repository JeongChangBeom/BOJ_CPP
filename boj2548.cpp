//boj2548번_대표 자연수_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	if (N % 2 == 0) {
		cout << v[N / 2 - 1];
	}
	else {
		cout << v[N / 2];
	}
}
//정렬을 이용한 문제.
//오름차순으로 정렬해서 가운데 값을 구하면 되는 쉬운 문제이다.
//입력받은 수의 개수가 홀수인지 짝수인지에 따라 가운데값이 다르므로 주의하자.