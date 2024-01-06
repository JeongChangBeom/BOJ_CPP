//boj10431번_줄세우기_구현

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int P;
	cin >> P;

	for (int p = 0; p < P; p++) {
		int T;
		cin >> T;

		vector<int> v;
		int sum = 0;

		for (int i = 0; i < 20; i++) {
			int height;
			cin >> height;

			if (v.empty() || *max_element(v.begin(), v.end()) == height) {
				v.push_back(height);
			}
			else {
				v.push_back(height);
				sort(v.begin(), v.end());
				sum += v.size() - (lower_bound(v.begin(), v.end(), height) - v.begin() + 1);
			}
		}

		cout << T << " " << sum << "\n";
	}
}
//구현문제.
//좀 더 쉽게 풀 수 있었을 것 같은데 풀다 보니 엄청 꼬인것 같다.
//벡터를 이용해서 풀었고, 풀이 방법은 줄이 없거나 입력받은 키가 제일 크면 맨뒤에 줄을 서게 하고
//나보다 큰사람이 있을 시 오름차순으로 줄을 세우고(sort를 사용) 이후 (줄의 길이 - 내 앞에 있는 사람 수 + 나(1))를 해서
//내 뒤에 있는 사람 수를 구했다.(내 뒤에 있는 사람은 전부 한 발짝식 뒤로 가야되기 때문)