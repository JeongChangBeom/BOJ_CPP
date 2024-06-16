//boj9935번_문자열 폭발_문자열

#include<iostream>
#include<string>

using namespace std;

int main() {
	string str, explosion;
	cin >> str;
	cin >> explosion;

	string result = "";

	for (int i = 0; i < str.size(); i++) {
		result += str[i];

		if (str[i] == explosion[explosion.size() - 1]) {
			string temp = "";
			for (int j = explosion.size() - 1; j >= 0; j--) {
				temp += result[result.size() - 1 - j];
			}

			if (temp == explosion) {
				result.erase(result.size() - explosion.size(), explosion.size());
			}
		}
	}

	if (result == "") {
		cout << "FRULA";
	}
	else {
		cout << result;
	}

	return 0;
}