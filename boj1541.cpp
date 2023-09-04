//boj1541번_잃어버린 괄호_그리디 알고리즘

#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;

	string num;
	int result = 0;

	bool minus = false;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			if (!minus) {
				result += stoi(num);
				num.clear();
			}
			else {
				result -= stoi(num);
				num.clear();
			}
			if (str[i] == '-') {
				minus = true;
			}
		}
		else {
			num += str[i];
		}
	}

	if (!minus) {
		result += stoi(num);
	}
	else {
		result -= stoi(num);
	}

	cout << result;
}
//그리디 알고리즘을 이용해서 풀 수 있는 문제.
//처음 -가 나온 시점부터 뒤에 나오는 모든 수를 빼면 최소값인 점을 이용해서 풀었다.