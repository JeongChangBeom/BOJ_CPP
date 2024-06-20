//boj12904번_A와 B_구현

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string S, T;
	cin >> S;
	cin >> T;

	bool check = false;

	for (int i = T.size() - 1; i >= 0; i--) {
		if (T[i] == 'A') {
			T.erase(T.begin() + i);
		}
		else if (T[i] == 'B') {
			T.erase(T.begin() + i);
			reverse(T.begin(), T.end());
		}

		if (S == T) {
			check = true;
		}
	}

	if (check) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}