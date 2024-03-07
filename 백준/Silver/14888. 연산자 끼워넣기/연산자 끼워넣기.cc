//boj14888번_연산자 끼워넣기_백트래킹

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> v;
	vector<int> oper;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < 4; i++) {
		int op;
		cin >> op;
		for (int j = 0; j < op; j++) {
			oper.push_back(i);
		}
	}

	vector<int> result;

	do {

		int ans = v[0];

		for (int i = 0; i < oper.size(); i++) {
			if (oper[i] == 0) {
				ans += v[i + 1];
			}
			else if (oper[i] == 1) {
				ans -= v[i + 1];
			}
			else if (oper[i] == 2) {
				ans *= v[i + 1];
			}
			else if (oper[i] == 3) {
				ans /= v[i + 1];
			}
		}
		result.push_back(ans);

	} while (next_permutation(oper.begin(), oper.end()));

	sort(result.begin(), result.end());

	cout << result[result.size() - 1] << '\n' << result[0];
}