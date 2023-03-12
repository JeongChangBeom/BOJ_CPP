//boj11866번_요세푸스 문제0_자료구조(큐)

#include<iostream>
#include<queue>

using namespace std;


vector<int> v;

int main() {
	int N, K;
	cin >> N >> K;

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.empty() == false) {
		for (int i = 0; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
	}

	cout << "<";
	int i;
	for (i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ", ";
	}
	cout << v[i] <<">";
}
//큐를 사용해서 풀 수 있는 문제.