//boj1417번_국회의원 선거_자료구조(우선순위 큐)

#include<iostream>
#include<queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	priority_queue<int> q;

	int dasom;
	cin >> dasom;

	for (int i = 0; i < N - 1; i++) {
		int num;
		cin >> num;
		q.push(num);
	}

	int result = 0;

	while (!q.empty() && q.top() >= dasom) {
		int top = q.top();
		q.pop();
		dasom++;
		top--;
		result++;
		q.push(top);
	}

	cout << result;
}
//우선 순위 큐 문제. 
//우선 순위 큐에 다솜이를 제외한 후보들의 득표수를 저장해두고
//득표수가 다솜이보다 높은사람(우선순위 큐의 top)의 득표수를 1 내리고 다솜이의 득표수를 1 올린 후
//다시 우선순위 큐에 넣는 과정을 다솜이보다 득표수가 높은 후보가 없을 때까지 반복해주면 된다.