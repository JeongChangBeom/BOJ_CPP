//boj1475번_방 번호_구현

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
int main() {
	int result[9] = { 0, };
	string N;
	cin >> N;

	for (int i = 0; i < N.length(); i++) {
		if (N[i] == '9') {
			result[6]++;
		}
		else {
			result[N[i] - 48]++;
		}
	}

	result[6] = ceil((double)result[6] / 2);
	cout << *max_element(result, result + 9);

}
//조건대로 구현하면 되는문제, 6과 9를 뒤집어서 사용할 수 있다는 조건만 신경쓰면 쉽게 풀 수 있는 문제.
//9를 입력받았을때 6을 증가시키고 뒤에서 6을 반으로 나눈후 올림해서 계산해서 해결했다.