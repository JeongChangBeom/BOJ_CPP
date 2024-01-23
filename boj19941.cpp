//boj19941번_햄버거 분배_그리디 알고리즘

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<char> v;
	int result = 0;

	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		v.push_back(c);
	}

	for (int i = 0; i < N; i++) {
		if (v[i] == 'P') {
			for (int j = i - K; j <= i + K; j++) {
				if (j<0 || j>N - 1) {
					continue;
				}
				else if (v[j] == 'H') {
					v[j] = 'X';
					result++;
					break;
				}
			}
		 }
	}
	cout << result;
}
//그리디 알고리즘 문제.
//입력받은 값을 vector에 넣어 vector의 처음부터 돌며 사람(P)를 만났을때 vector의 범위를 벗어나지 않는 선에서
//양쪽 K범위 만큼을 탐색하며 가장 왼쪽에 있는 H를 찾으면 된다. 이미 먹은 햄버거를 또 탐색할 수 있으므로
//이미 먹은 햄버거는 X로 바꿔해결했다.