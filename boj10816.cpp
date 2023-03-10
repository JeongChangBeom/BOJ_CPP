//boj10816번_숫자 카드2_정렬, 이분 탐색

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> sang;
vector<int> card;
vector<int> result;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		sang.push_back(x);
	}

	sort(sang.begin(),sang.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int y;
		cin >> y;
		card.push_back(y);
	}

	for (int i = 0; i < M; i++) {
		if (binary_search(sang.begin(), sang.end(), card[i])) {
			result.push_back(upper_bound(sang.begin(), sang.end(), card[i]) - lower_bound(sang.begin(), sang.end(), card[i]));
		}
		else {
			result.push_back(0);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}
//이분탐색(logN)으로 빠른 탐색을 하여 시간초과를 피하는 문제.
//upper_bound는 배열이나 벡터에서 세번째 인자값이 마지막으로 나오는 인덱스+1
//lower_bound는 세번째 인자값이 처음 나오는 인덱스값을 반환해주기 때문에
//정렬되어 있는 배열이나 벡터에서 upper_bound - lower_bound를 하면 배열에 
//세번째 인자값이 몇개 있는지 알 수 있다.