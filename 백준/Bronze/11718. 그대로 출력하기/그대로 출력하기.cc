//boj11718번_그대로 출력하기_구현

#include<iostream>
#include<string>

using namespace std;

int main() {
	while (true) {
		string str;
		getline(cin, str);

		if (cin.eof()) {
			break;
		}

		cout << str << '\n';
	}
}