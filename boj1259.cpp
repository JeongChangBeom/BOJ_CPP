//boj1259번_펠린드롬수_구현

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	string x;

	while (true) {
		string y;
		cin >> x;

		if (x == "0") {
			break;
		}
		y = x;
		reverse(x.begin(), x.end());

		if (y.compare(x) == 0) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
}
//수를 int 형이 아닌 string으로 받아 reverse함수를 사용해 풀 수 있는 문제