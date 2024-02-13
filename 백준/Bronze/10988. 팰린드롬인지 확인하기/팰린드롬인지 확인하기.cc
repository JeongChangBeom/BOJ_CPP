//boj10988번_팰린드롬인지 확인하기_구현

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	string str;
	cin >> str;

	string str_R = str;
	reverse(str_R.begin(), str_R.end());

	if (str == str_R) {
		cout << "1";
	}
	else {
		cout << "0";
	}
}