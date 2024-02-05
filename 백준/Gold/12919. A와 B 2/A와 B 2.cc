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