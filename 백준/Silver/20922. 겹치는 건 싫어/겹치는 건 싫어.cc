//boj20922번_겹치는 건 싫어_두 포인터

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int check[100001];

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int result = -999;
	int i = 0;
	int j = 0;

	while (i <= j && j < N) {
		if (check[v[j]] < K) {
			check[v[j]]++;
			j++;
			result = max(result, j - i);
		}
		else {
			check[v[i]]--;
			i++;
		}
	}
	cout << result;
}
//처음에 이중 for문으로 해결했는데 시간초과가 나서 두포인터로 바꾼 문제.
//i와 j라는 두개의 포인터를 두고 i가 j보다 커지거나 j가 vector의 끝까지 갈때까지 while문을 통해 루프를 돌리면서
//check배열을 통해 숫자가 몇개 나왔었는지 세어주면서 최장 연속 부분 수열의 길이를 구했다.