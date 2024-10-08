//boj1747번 소수&팰린드롬_수학

#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

bool isPrime(int x) {
	if (x == 1) {
		return false;
	}
	else {
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
}

bool isPalin(int x) {
	string temp = to_string(x);

	string str1 = temp;
	reverse(temp.begin(), temp.end());
	string str2 = temp;
	
	if (str1 == str2) {
		return true;
	}
	else {
		return false;
	}
}

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = N; i <= 2000000; i++) {
		if (isPrime(i) && isPalin(i)) {
			cout << i;
			return 0;
		}
	}

	return 0;
}
