//boj1105번_팔_그리디 알고리즘

#include<iostream>
#include<vector>

using namespace std;

int main() {
	string L, R;
	cin >> L >> R;

	vector<char> v;

	if (L.size() != R.size()) {
		cout << 0;
		return 0;
	}
	else {
		for (int i = 0; i < L.size(); i++) {
			if (L[i] == R[i]) {
				v.push_back(L[i]);
			}
			else {
				break;
			}
		}
	}
	
	int result = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == '8') {
			result++;
		}
	}

	cout << result;

	return 0;
}