//boj16953번_A->B_그리디 알고리즘

#include<iostream>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	int result = 1;

	while (A != B) {
		result++;

		if (B % 2 == 0) {
			B /= 2;
		}
		else if (B % 10 == 1) {
			B /= 10;
		}
		else {
			result = -1;
			break;
		}
		if (B < A) {
			result = -1;
			break;
		}
	}

	cout << result;

	return 0;
}