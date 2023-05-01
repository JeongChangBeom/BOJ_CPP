//boj10867번_중복 빼고 정렬하기_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v;

	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());


	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}
//v.erase(unique(v.begin(), v.end()), v.end());를 통해 벡터의 원소 중복만 제거하면 쉽게 풀 수 있는 문제