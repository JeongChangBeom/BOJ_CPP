//boj20310번_타노스_문자열

#include<iostream>
#include<vector>

using namespace std;

bool arr[501];

int main() {
	string str;
	cin >> str;

	vector<char> v;

	int count_zero = 0;
	int count_one = 0;

	for (int i = 0; i < str.size(); i++) {
		v.push_back(str[i]);
		if (str[i] == '0') {
			count_zero++;
		}
		else {
			count_one++;
		}
	}

	count_zero /= 2;
	count_one /= 2;


	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] == '0') {
			if (count_zero > 0) {
				arr[i] = true;
				count_zero--;
			}
			else {
				break;
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == '1') {
			if (count_one > 0) {
				arr[i] = true;
				count_one--;
			}
			else {
				break;
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (!arr[i]) {
			cout << v[i];
		}
	}
}
//문자열을 이용한 구현문제 처음에 vector에 입력값을 저장하고 0은 뒤에서 1은 앞에서 부터 절반을 제거하면 되겠다고 생각해서
//vector의 erase함수를 사용해 풀려고하다 25점을 받았다. vector의 erase 함수는 vector의 원소를 제거하면서 size도 줄어드는데 이 점을 간과했기 때문이다.