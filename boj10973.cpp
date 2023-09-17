#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int  N;
	cin >> N;
	
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	if (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
	}
	else {
		cout << "-1";
	}
}
//주어진 순열보다 사전순으로 이전인 수열을 구하는 문제.
//라이브러리에 prev_permutation이라는 이전 순열이 존재하면 true를 반환하며 배열의 값이 이전 순열로 바뀌는 함수가 있다.
//이 함수를 사용하면 쉽게 해결할 수 있다.