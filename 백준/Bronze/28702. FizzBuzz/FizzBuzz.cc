//boj28702번_FizzBuzz_구현

#include<iostream>
#include<string>

using namespace std;

int main() {
	int num = 0;

	for (int i = 0; i < 3; i++) {
		string str;
		cin >> str;

		if (str[0] == 'F' || str[0] == 'B') {
			if (num == 0) {
				continue;
			}
			else {
				num++;
			}
		}
		else {
			num = stoi(str);
		}
	}

	num++;

	if (num % 3 == 0 && num % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (num % 3 == 0) {
		cout << "Fizz";
	}
	else if (num % 5 == 0) {
		cout << "Buzz";
	}
	else {
		cout << num;
	}

	return 0;
}