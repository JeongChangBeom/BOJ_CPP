//boj10972번_다음 순열_구현

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

	if (next_permutation(v.begin(), v.end())) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
	}
	else {
		cout << "-1";
	}
}
//벡터안의 요소들의 다음 순열을 구해서 bool타입으로 반환해주는 next_permutation을 사용해서 풀었다.