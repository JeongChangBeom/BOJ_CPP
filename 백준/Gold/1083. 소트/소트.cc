//boj1083번_소트_그리디 알고리즘

#include<iostream>
#include<vector>

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

	int S;
	cin >> S;

	for (int i = 0; i < N - 1; i++) {
		if (S == 0) {
			break;
		}

		int max = v[i];
		int max_index = i;

		for (int j = i+1; j < min(N,i+1+S); j++) {
			if (max < v[j]) {
				max = v[j];
				max_index = j;
			}
		}

		S -= max_index - i;

		for (int k = max_index; k > i; k--) {
			v[k] = v[k - 1];
		}

		v[i] = max;
	}

	for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}

	return 0;
}