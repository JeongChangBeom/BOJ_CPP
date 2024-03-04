//boj4779번_칸토어 집합_재귀

#include<iostream>
#include<cmath>

using namespace std;

void canto(int x) {
	if (x == 0) {
		cout << "-";
		return;
	}

	canto(x - 1);
	for (int i = 0; i < pow(3, x - 1); i++) {
		cout << " ";
	}
	canto(x - 1);

}

int main() {
	while (true) {
		int N;
		cin >> N;

		if (cin.eof()) {
			break;
		}

		canto(N);
		cout << '\n';
	}
}