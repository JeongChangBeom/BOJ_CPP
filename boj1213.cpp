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

//돌은 1개 or 3개 가져올 수 있고 두사람이 완벽하게 게임을 진행하기 때문에
//규칙을 생각해보면 2의 배수인 경우 창영이가 2의 배수가 아닌 경우 상근이가 승리한다.
//그리고 N의 범위가 1000000000000까지므로 long long타입을 사용해야한다.