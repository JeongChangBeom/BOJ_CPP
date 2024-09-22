//boj2477번_참외밭_구현

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int K;
	cin >> K;

	vector<pair<int, int>> v;

	for (int i = 0; i < 6; i++) {
		int dir;
		int leng;

		cin >> dir >> leng;

		v.push_back({ dir,leng });
	}

	int maxWidth = 0;
	int maxHeight = 0;

	int maxWidth_index = 0;
	int maxHeight_index = 0;

	for (int i = 0; i < 6; i++) {
		if (v[i].first == 1 || v[i].first == 2) {
			if (v[i].second > maxWidth) {
				maxWidth = v[i].second;
				maxWidth_index = i;
			}

		}
		else if (v[i].first == 3 || v[i].first == 4) {
			if (v[i].second > maxHeight) {
				maxHeight = v[i].second;
				maxHeight_index = i;
			}
		}
	}

	int minWidth = v[(maxWidth_index + 3) % 6].second;
	int minHeight = v[(maxHeight_index + 3) % 6].second;


	cout << ((maxWidth * maxHeight) - (minWidth * minHeight)) * K;

	return 0;
}