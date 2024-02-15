//boj2720번_세탁소 사장 동혁_그리디 알고리즘

#include<iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int coin;
		cin >> coin;

		int quarter = coin / 25;
		int dime = (coin - quarter * 25) / 10;
		int nickel = (coin - quarter * 25 - dime * 10) / 5;
		int penny = (coin - quarter * 25 - dime * 10 - nickel * 5) / 1;

		cout << quarter << ' ' << dime << ' ' << nickel << ' ' << penny << '\n';
	}
}