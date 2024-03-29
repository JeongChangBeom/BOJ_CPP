//boj17615번_볼 모으기_그리디 알고리즘

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	string str;
	cin >> str;

	vector<char> v;
	vector<int> result;
	int red = 0;
	int blue = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'R') {
			red++;
		}
		if (str[i] == 'B') {
			blue++;
		}
		v.push_back(str[i]);
	}

	int i = 0;
	int count = 0;
	while (v[i] == 'R') {
		count++;
		i++;
	}
	int red_left_result = red - count;

	i = N - 1;
	count = 0;
	while (v[i] == 'R') {
		count++;
		i--;
	}
	int red_right_result = red - count;

	i = 0;
	count = 0;
	while (v[i] == 'B') {
		count++;
		i++;
	}
	int blue_left_result = blue - count;

	i = N - 1;
	count = 0;
	while (v[i] == 'B') {
		count++;
		i--;
	}
	int blue_right_result = blue - count;

	result.push_back(red_left_result);
	result.push_back(red_right_result);
	result.push_back(blue_left_result);
	result.push_back(blue_right_result);

	cout << *min_element(result.begin(), result.end());
}
//그리디 알고리즘 문제.
//빨간색 공을 왼쪽에 전부 모을 때, 빨간색 공을 오른쪽에 전부 모을 때, 파란색 공을 왼쪽에 전부 모을 때, 파란색 공을 오른쪽에 전부 모을 때를 구해서
//가장 적게 움직이는 경우의 수를 찾는 식으로 해결했다.