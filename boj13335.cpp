//boj13335번_트럭_자료구조(큐)

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, w, L;
	cin >> n >> w >> L;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	queue<int> q;

	int sum = 0;
	int result = 0;

	for (int i = 0; i < n; i++) {
		while (sum + v[i] > L) {
			if (q.size() == w) {
				sum -= q.front();
				q.pop();
			}
			q.push(0);
			result++;
		}
		q.push(v[i]);
		sum += v[i];
		result++;
	}
	cout << result + w;
}
//큐를 이용해서 풀 수 있는 문제.
//출력할 때 마지막 트럭이 건너가는 시간을 더해주는 것을 까먹고 실수 하지 말자.