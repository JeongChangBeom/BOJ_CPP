//boj1522번_문자열 교환_슬라이딩 윈도우

#include<iostream>
#include<vector>

using namespace std;

int main() {
	string str;
	cin >> str;

	vector<char> v;

	int a_num = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a') {
			a_num++;
		}
		v.push_back(str[i]);
	}

	int result = 99999;

	for (int i = 0; i < v.size(); i++) {
		int min = 0;
		int count = 0;

		for (int j = i; j < i + a_num; j++) {
			if (a_num == count) {
				break;
			}
			if (v[j % v.size()] == 'b') {
				min++;
				count++;
			}
			else {
				count++;
			}
		}
		result = std::min(result, min);
	}
	cout << result;
}
//슬라이딩 윈도우 문제.
//전체 문자열에서 a의 개수를 윈도우로 정하고 그 윈도우 안에 있는 b를 윈도우 밖에 있는 a랑 교환하는 식으로 해결했다.
//문자열은 원형이므로 문자열을 탐색할때 나머지연산을 통해 배열의 범위 밖으로 넘어가면 다시 처음으로 돌아오도록 만들었다.