//boj2941번_크로아티아 알파벳_구현

#include<iostream>

using namespace std;

int main() {
	string str;
	cin >> str;

	int result = 0;

	for (int i = 0; i < str.size(); i++) {
		result++;
		if (str[i] == 'c') {
			if (str[i + 1] == '=') {
				result--;
			}
			if (str[i + 1] == '-') {
				result--;
			}
		}

		if (str[i] == 'd') {
			if (str[i + 1] == 'z') {
				if (str[i + 2] == '=') {
					result--;
				}
			}
			if (str[i + 1] == '-') {
				result--;
			}
		}

		if (str[i] == 'l') {
			if (str[i + 1] == 'j') {
				result--;
			}
		}

		if (str[i] == 'n') {
			if (str[i + 1] == 'j') {
				result--;
			}
		}

		if (str[i] == 's') {
			if (str[i + 1] == '=') {
				result--;
			}
		}

		if (str[i] == 'z') {
			if (str[i + 1] == '=') {
				result--;
			}
		}
	}

	cout << result;
}