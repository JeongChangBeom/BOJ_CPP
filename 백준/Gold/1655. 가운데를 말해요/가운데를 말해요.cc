//boj1655번_가운데를 말해요_자료구조

#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int> max;
	priority_queue<int, vector<int>, greater<int>> min;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (max.empty()) {
			max.push(num);
		}
		else {
			if (max.size() == min.size()) {
				max.push(num);
			}
			else {
				min.push(num);
			}

			if (max.top() > min.top()) {
				max.push(min.top());
				min.pop();
				min.push(max.top());
				max.pop();
			}
		}
		cout << max.top() << '\n';
	}
}