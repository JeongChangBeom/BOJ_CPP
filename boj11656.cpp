//boj11656번_접미사 배열_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> v;

int main() {
	string S;
	cin >> S;

	int length = S.size();

	v.push_back(S);

	for (int i = 1; i < length; i++) {
		S.erase(S.begin());
		v.push_back(S);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < length; i++) {
		cout << v[i] << "\n";
	}
}
//정렬을 하는 것보다 문자열 S의 모든 접미사를 구해 벡터에 저장하는 것이 관건인 문제