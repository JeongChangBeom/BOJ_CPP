//boj1181_단어 정렬_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> s;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string x;
		cin >> x;
		if (find(s.begin(), s.end(), x) == s.end()) {
			s.push_back(x);
		}
	}

	sort(s.begin(), s.end(),compare);

	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << "\n";
	}
}
//algorithm의 sort를 이용해서 풀 수 있는 문제.
//sort의 세번째 인자로 정렬 기준 함수를 넣을 수 있는 점을 알고 있다면 쉽게 풀 수 있는 문제.