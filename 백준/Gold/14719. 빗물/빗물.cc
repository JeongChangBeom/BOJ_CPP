//boj14719번_빗물_구현

#include<iostream>

using namespace std;

int width[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, w;
	cin >> h >> w;

	for (int i = 0; i < w; i++) {
		cin >> width[i];
	}

	int result = 0;

	for (int i = 1; i < w - 1; i++) {
		int left = width[i];
		int right = width[i];

		for (int j = 0; j < i; j++) {
			left = max(left, width[j]);
		}
		for (int j = i; j < w; j++) {
			right = max(right, width[j]);
		}

		result += min(left, right) - width[i];
	}

	cout << result;
}