//boj13335번_트럭_자료구조(큐)

#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n, w, L;
	cin >> n >> w >> L;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int car;
		cin >> car;
		v.push_back(car);
	}

	queue<int> q;
	int weight = 0;
	int result = 0;

	for (int i = 0; i < n; i++) {
		while (true) {
			if (q.size() == w) {
				weight -= q.front();
				q.pop();
			}

			if (v[i] + weight <= L) {
				break;
			}

			q.push(0);
			result++;
		}
		q.push(v[i]);
		result++;
		weight += v[i];
	}

	cout << result + w;
}
//자료구조 큐 문제.
//입력 받은 트럭을 전부 vector에 저장해놨다가 queue로 하나씩 최대하중과 다리의 길이를 잘생각해서 옮기면 되는 문제이다.
//핵심은 마지막 트럭이 혼자 지나 갈때 걸리는 시간인 다리길이(w)를 결과값(result)에 더해주는 것이다.
//이전에 풀었었는데 백준에서 메모리 초과가 나서 다시 푼 문제이다. (풀었을 당시에는 통과가 됐었나보다...)