//boj2529번_부등호_백트래킹

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int K;
vector<char> oper;
vector<string> result;
bool num_check[10];

bool check(int x, int y, char op) {
	if (op == '<') {
		if (x < y) {
			return true;
		}
	}
	else if (op == '>') {
		if (x > y) {
			return true;
		}
	}
	return false;
}

void solve(int index, string num) {
	if (index == K + 1) {
		result.push_back(num);
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!num_check[i]) {
			if (index == 0 || check(num[index - 1] - '0', i, oper[index - 1])) {
				num_check[i] = true;
				solve(index + 1, num + to_string(i));
				num_check[i] = false;
			}
		}
	}
}

int main() {
	cin >> K;

	for (int i = 0; i < K; i++) {
		char op;
		cin >> op;
		oper.push_back(op);
	}

	solve(0, "");

	sort(result.begin(), result.end());

	cout << result[result.size() - 1] << '\n' << result[0];

}