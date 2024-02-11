//boj5597번_과제 안 내신 분..?_구현

#include<iostream>

using namespace std;

bool arr[31];

int main() {
	for (int i = 0; i < 28; i++) {
		int num;
		cin >> num;

		arr[num] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (!arr[i]) {
			cout << i << '\n';
		}
	}
}
//구현 문제.
//과제를 낸 학생의 번호를 입력받아서 bool타입배열을 통해 체크해주면 과제를 안낸 학생은 fasle가 되므로,
//for문을 통해 찾아주면 된다.