//boj1316번_그룹 단어 체커_구현

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	int result = 0;

	for (int n = 0; n < N; n++) {
		string str;
		cin >> str;

		vector<char> v;

		char cur = ' ';

		for (int i = 0; i < str.size(); i++) {
			if (cur != str[i]) {
				if (find(v.begin(), v.end(), str[i]) != v.end()) {
					result++;
					break;
				}
				v.push_back(cur);
				cur = str[i];
			}
		}
	}

	cout << N - result;
}