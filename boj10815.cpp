//boj10815_숫자카드_이분탐색

#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<int> sang;
vector<int> card;
int result[500001];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		sang.push_back(num);
	}

	sort(sang.begin(), sang.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		card.push_back(num);
	}

	for (int i = 0; i < M; i++) {
		if (binary_search(sang.begin(), sang.end(), card[i])) {
			result[i] = 1;
		}
		else {
			result[i] = 0;
		}
	}

	for (int i = 0; i < M; i++) {
		cout << result[i] << " ";
	}

	return 0;
}
//이분탐색을 사용해서 풀 수 있는 문제. STL을 사용해서 해결했다.
//예전에 풀었던 문제가 재채점으로 오답처리가 되어 오답수정을 했다.