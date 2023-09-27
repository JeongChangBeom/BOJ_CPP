//boj21921번_블로그_누적 합

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, X;
	cin >> N >> X;

	vector<int> v;
	v.push_back(0);

	int sum = 0;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		sum += num;

		v.push_back(sum);
	}

	int max = v[X];
	int count = 1;

	for (int i = 1; i <= v.size() - X; i++) {
		int Asum = v[i + X] - v[i];
	
		if (Asum > max) {
			max = Asum;
			count = 1;
		}
		else if (Asum == max) {
			count++;
		}
	}

	if (max == 0) {
		cout << "SAD";
	}
	else {
		cout << max << '\n' << count;
	}
}
//누적합을 사용하지 않고 이중for문을 이용하면 시간초과가 나는문제
//누적합을 통해 기간내 방문자수를 구해 최대값을 갱신해가며 해결했다.