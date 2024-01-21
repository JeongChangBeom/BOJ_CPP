//boj1515번 수 이어 쓰기_문자열

#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int pointer = 0;

	for (int N = 1; N < 30000; N++) {
		string num = to_string(N);
		for (int j = 0; j < num.size(); j++) {
			if (str[pointer] == num[j]) {
				pointer++;
			}
			if (str.size() == pointer) {
				cout << N;
				return 0;
			}
		}
	}
}
//문자열문제.
//처음 문제를 봤을때 입력값의 길이가 최대 3000자리 인 것을 보고 문자열로 풀어야겠다는 생각을 했다.
//포인터로 문자열의 첫번째 수부터 N(구하려는값)을 증가시키면서 비교하며 N의 값을 찾는 식으로 해결했다.
//포인터가 가리키는 문자에 N값의 자리수를 하나씩 비교하며 맞을 때까지 N을 늘리면서 찾았다.