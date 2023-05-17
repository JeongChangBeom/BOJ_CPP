//boj2776번_암기왕_이분탐색

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool binary_search(vector<int>& v, int length, int key) {
	int start = 0;
	int end = length - 1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (key == v[mid]) {
			return true;
		}
		if (key < v[mid]) {
			end = mid - 1;
		}
		else if (key > v[mid]) {
			start = mid + 1;
		}
	}
	return false;
}

int main() {
	int T;
	cin >> T;

	for (int k = 0; k < T; k++) {
		int N;
		cin >> N;

		vector<int> v1;
		vector<int> v2;

		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			v1.push_back(num);
		}

		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			v2.push_back(num);
		}

		sort(v1.begin(),v1.end());

		for (int i = 0; i < v2.size(); i++) {
			if (binary_search(v1, v1.size(), v2[i])) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
	}
}
//이분탐색을 이용해 해결할 수 있는 간단한 문제, 이분탐색의 원리를 되새기기 위해 STL을 사용하지 않고 구현해봤다.