//boj1253번_좋다_두 포인터

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int result = 0;

	for (int i = 0; i < v.size(); i++) {
		int x = v[i];

		int start = 0;
		int end = v.size() - 1;

		while (start < end) {
			int sum = v[start] + v[end];

			if (sum == x && (start != i && end != i)) {
				result++;
				break;
			}

			if (x < sum || end == i) {
				end--;
			}
			else if (x > sum || start == i) {
				start++;
			}
		}
	}

	cout << result;

	return 0;
}