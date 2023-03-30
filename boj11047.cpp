//boj11047번_동전 0_그리디 알고리즘

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int x, int y) {
	return y < x;
}

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), compare);
	
	int coin = 0;
	int i = 0;

	while (K > 0) {
		if (K < v[i]) {
			i++;
		}
		else {
			coin += K / v[i];
			K -= (K / v[i]) * v[i];
			i++;
		}
	}

	cout << coin;
}
//그리디 알고리즘을 사용해서 풀 수 있는 문제. 동전의 종류를 큰수부터 정렬해서
//K원보다 큰 동전은 넘기고 K원 보다 작은 동전 중 가장 큰 동전부터 골라 풀었다.