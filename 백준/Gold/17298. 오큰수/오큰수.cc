//boj17298번_오큰수_자료구조(스택)

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}

	stack<int> s;

	for (int i = 0; i < N; i++) {
		while (true) {
			if (s.empty() || A[s.top()] >= A[i]) {
				s.push(i);
				break;
			}

			if (A[s.top()] < A[i]) {
				A[s.top()] = A[i];
				s.pop();
			}
		}

	}

	while (!s.empty()) {
		A[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}

	return 0;
}