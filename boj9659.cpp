//boj9659번_돌 게임 5_게임 이론

#include<iostream>
#include<vector>

using namespace std;


int main() {
	long long N;
	cin >> N;

	if ((N % 2) == 0) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}
}
//전에 풀었었던 돌 게임 문제와 입력값의 범위만 다른 문제.
//입력받는 N의 최대값이 상당히 커서 long long 타입을 사용해야된다.
//솔직히 이 문제가 왜 실버3인지 모르겠다.