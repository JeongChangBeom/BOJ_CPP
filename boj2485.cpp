//boj2485번_가로수_수학, 유클리드 호제법

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int GCD(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return GCD(y, x % y);
	}
}

int main() {
	int N;
	cin >> N;

	vector<int> v;
	vector<int> dis;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i < N; i++) {
		int distance = v[i] - v[i - 1];
		dis.push_back(distance);
	}

	int gcd = dis[0];

	for (int i = 1; i < N - 1; i++) {
		gcd = GCD(gcd, dis[i]);
	}

	int result = 0;

	for (int i = 0; i < N - 1; i++) {
		result += dis[i] / gcd - 1;
	}

	cout << result;
}
//유클리드 호제법을 이용한 수학문제. 나무들 사이의 간격의 최대공약수를 구해서 dis[i] / gcd - 1을 통해 답을 구할 수 있다.
//나무의 양쪽 맨끝은 이미 나무가 심어져 있으므로 둘중 하나를 빼야 되므로 -1을 꼭 해줘야된다.