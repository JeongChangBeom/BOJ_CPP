//boj11931번_수 정렬하기 4_정렬

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(int x, int y) {
	if (x > y) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}
//algorithm헤더 파일에 있는 sort함수에 compare함수를 적용시켜주면 쉽게 풀 수 있는 문제.