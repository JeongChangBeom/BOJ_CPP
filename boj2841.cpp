//boj2841번_외계인의 기타 연주_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

int main() {
	int N, P;
	cin >> N >> P;

	stack<int> s[8];
	int result = 0;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		if (s[x].empty()) {
			s[x].push(y);
			result++;
		}
		else {
			if (s[x].top() < y) {
				s[x].push(y);
				result++;
			}

			else if (s[x].top() > y) {
				while (!s[x].empty() && s[x].top() > y) {
					s[x].pop();
					result++;
				}
				if (s[x].empty() || s[x].top() < y) {
					s[x].push(y);
					result++;
				}
			}
		}
	}
	cout << result;
}
//자료구조 스택문제.
//문제의 핵심은 총 3가지이다. 1. 아무 프렛도 누르지 않고 있을 때 바로 누르기(+1) 2. 누르려는 프렛이 현재 누르고 있는 프렛보다 높을 경우 바로 누르기(+1)
//3. 누르려는 프렛이 현재 누르고 있는 프렛보다 낮을 경우 높은 프렛부터 하나씩 떼면서 +1씩 해주고, 떼다가 낮은 프렛이 나오거나, 전부 뗐을 시 누르기(+1)