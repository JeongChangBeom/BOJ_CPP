//boj2609번_최대공약수와 최소공배수_수학

#include<iostream>

using namespace std;

int GCD(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return GCD(y, x % y); 
	}
}

int main()
{
	int x, y;
	cin >> x >> y;

	cout << GCD(x, y) << "\n";
	cout << (x * y) / GCD(x, y) << "\n";
}
//최대공약수를 구하는 유클리드 호제법과
//최대공약수로 최소 공배수를 구하는 법을 알면 쉽게 풀 수 있는 문제.