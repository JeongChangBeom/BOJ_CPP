//boj11652번_카드_정렬, 맵

#include<iostream>
#include<map>

using namespace std;

int main() {
	int N;
	cin >> N;

	map<long long, int> m;

	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;

		if (m.find(num) == m.end()) {
			m.insert(make_pair(num, 1));
		}
		else {
			m[num]++;
		}
	}

	int max = -999;
	long long result = -999;

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second > max) {
			max = it->second;
			result = it->first;
		}
	}

	cout << result;
}
//맵을 사용해서 풀 수 있는 문제. 입력값이 -2^62 <= num <= 2^62이므로 long long 타입을 써야된다.