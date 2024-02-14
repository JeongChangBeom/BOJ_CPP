//boj2745번_진법 변환_구현

#include<iostream>
#include<cmath>

using namespace std;

int main() {
	string N;
	int B;
	cin >> N >> B;

	int result = 0;

	for (unsigned int i = 0; i < N.size(); i++) {
		if ('A' <= N[i] && N[i] <= 'Z') {
			result += ((int)N[i] - 'A' + 10) * ((int)pow(B, N.size() - 1 - i));
		}
		else {
			result += ((int)N[i] - '0') * ((int)pow(B, N.size()-1-i));
		}
	}

	cout << result;
}