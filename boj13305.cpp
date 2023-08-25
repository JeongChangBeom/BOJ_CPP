//boj13305번_주유소_그리디 알고리즘

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> dis;
	vector<int> cost;

	for (int i = 1; i < N; i++) {
		int num;
		cin >> num;
		dis.push_back(num);
	}

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		cost.push_back(num);
	}

	long long min_cost = cost[0];
	long long result = 0;

	for (int i = 0; i < N - 1; i++) {
		min_cost = min(min_cost, (long long)cost[i]);
		result += dis[i] * min_cost;
	}

	cout << result;
}
//도시를 들릴때마다 지금까지 지나온 도시중 최소비용과 비교해가며 가장 최선의 수를 찾는 문제.
//처음에 최소값과 결과값을 int로 풀어서 58점이 나왔는데, long long타입으로 바꿔서 100점을 받았다.