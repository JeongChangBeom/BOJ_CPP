//boj1449번_수리공 항승_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, L;
	cin >> N >> L;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int result = 1;

	int index = v[0];

	for (int i = 1; i < v.size(); i++) {
		if((v[i] - index) >= L) {
			result++;
			index = v[i];
		}
	}
	cout << result;
}
//정렬을 사용해서 풀 수 있는 문제.
//위의 for문에서 마지막 테이프는 제외되어 있으므로 result를 1로 시작하여 해결했다.