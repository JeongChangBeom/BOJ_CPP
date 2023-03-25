//boj1427번_소트인사이드_정렬

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<char> v;

bool compare(int x, int y) {
	return y < x;
}

int main() {
	string N;
	cin >> N;

	for (int i = 0; i < N.length(); i++) {
		v.push_back(N[i]);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}
//문자열과 정렬을 사용해서 풀 수 있는 간단한 문제.