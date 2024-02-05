//boj12919번_A와 B 2_브루트포스

#include<iostream>
#include<algorithm>

using namespace std;

int result = 0;

void conversion(string x, string y) {
	if (x == y) {
		result = 1;
		return;
	}
	if (x.size() >= y.size()) {
		return;
	}

	if (y[0] == 'B') {
		string T_temp = y;
		reverse(T_temp.begin(), T_temp.end());
		T_temp.erase(T_temp.begin() + T_temp.size() - 1);
		conversion(x, T_temp);
	}

	if (y[y.size() - 1] == 'A') {
		y.erase(y.begin() + y.size() - 1);
		conversion(x, y);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string S, T;
	cin >> S;

	cin >> T;

	conversion(S, T);

	cout << result;
}
//브루트포스문제.
//처음엔 브루트포스 알고리즘 태그길래 S문자열을 T문자열으로 만드는 식으로 풀려고 했는데 시간초과가 났다.
//그래서 재귀함수를 이용해서 T문자열을 조건의 반대로 지우면서 S문자열로 만드는 식으로 해결했다.