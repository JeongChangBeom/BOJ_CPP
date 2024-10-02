//boj5648번_역원소 정렬_문자열

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

long long reverseNum(string s) {
	string temp = "";
	bool check = false;

	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '0' && !check) {
			continue;
		}

		if (s[i] == '0' && check) {
			temp += s[i];
		}
		else if (s[i] != '0') {
			temp += s[i];
			check = true;
		}
	}

	return stoll(temp);
}

int main() {
	int N;
	cin >> N;

	vector<long long> v;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		v.push_back(reverseNum(str));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}