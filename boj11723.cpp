//boj11723번_집합_구현

#include<iostream>
#include<vector>

using namespace std;

int arr[21] = { 0 };

int main() {
	ios_base::sync_with_stdio(false); //입축력 가속 없으면 시간초과
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		int x;
		if (s == "add") {
			cin >> x;
			if (arr[x] == 0) {
				arr[x] = 1;
			}
		}
		else if (s == "remove") {
			cin >> x;
			if (arr[x] == 1) {
				arr[x] = 0;
			}
		}
		else if (s == "check") {
			cin >> x;
			if (arr[x] == 0) {
				cout << "0" << "\n";
			}
			else {
				cout << "1" << "\n";
			}
		}
		else if (s == "toggle") {
			cin >> x;
			if (arr[x] == 1) {
				arr[x] = 0;
			}
			else {
				arr[x] = 1;
			}
		}
		else if (s == "all") {
			for (int j = 0; j < 21; j++) {
				arr[j] = 1;
			}
		}
		else if (s == "empty") {
			for (int j = 0; j < 21; j++) {
				arr[j] = 0;
			}
		}
	}
}
//단순 구현 문제인 줄 알고 문제 그대로 구현 했다가 시간초과가 나와서 입출력가속을 해보니 통과했다.
//찾아보니 원래 단순 구현 문제가 아닌 비스마스크를 이용해 푸는 문제인 것 같아 다음에 다시 도전해보려 한다.