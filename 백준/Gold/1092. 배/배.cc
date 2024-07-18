//boj1092번_배_그리디 알고리즘

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int x, int y) {
	return x > y;
}

int main() {
	int N;
	cin >> N;

	vector<int> crane;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		crane.push_back(num);
	}

	sort(crane.begin(), crane.end(), compare);

	int M;
	cin >> M;

	vector<int> box;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		box.push_back(num);
	}

	sort(box.begin(), box.end(), compare);

	if (crane[0] < box[0]) {
		cout << -1;
		return 0;
	}

	int result = 0;

	while (true) {
		if (box.empty()) {
			break;
		}
		else {
			result++;

			for (int i = 0; i < crane.size(); i++) {
				for (int j = 0; j < box.size(); j++) {
					if (!box.empty() && crane[i] >= box[j]) {
						box.erase(box.begin() + j);
						break;
					}
				}
			}
		}
	}

	cout << result;

	return 0;
}