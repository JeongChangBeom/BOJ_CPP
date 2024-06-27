//boj2212번_센서_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int x, int y) {
	return x > y;
}

int main() {
	int N, K;
	cin >> N;
	cin >> K;

	vector<int> sensor;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (find(sensor.begin(), sensor.end(), num) == sensor.end()) {
			sensor.push_back(num);
		}
	}

	sort(sensor.begin(), sensor.end());

	vector<int> dis;

	for (int i = 0; i < sensor.size() - 1; i++) {
		dis.push_back(sensor[i + 1] - sensor[i]);
	}

	sort(dis.begin(), dis.end(), compare);

	int result = 0;

	for (int i = K - 1; i < dis.size(); i++) {
		result += dis[i];
	}

	cout << result;

	return 0;
}