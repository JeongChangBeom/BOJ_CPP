//boj2661번_좋은수열_백트래킹

#include<iostream>
#include<string>

using namespace std;

int N;

void Solve(string str, int count) {
	for (int i = 1; i <= str.size() / 2; i++) {
		string a = str.substr(str.size() - i, i);
		string b = str.substr(str.size() - i * 2, i);

		if (a == b) {
			return;
		}
	}

	if (N == count) {
		cout << str;
		exit(0);
	}

	for (int i = 0; i < N; i++) {
		Solve(str + "1", count + 1);
		Solve(str + "2", count + 1);
		Solve(str + "3", count + 1);

	}
}

int main() {
	cin >> N;
	Solve("", 0);

	return 0;
}