//boj20291번_파일 정리_문자열,파싱,정렬

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, int> m;
	vector<string> v;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		string extension;

		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '.') {
				extension = str.substr(j + 1);
				if (m.find(extension) == m.end()) {
					m.insert({ extension, 1 });
					v.push_back(extension);
				}
				else {
					m[extension]++;
				}
			}
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ' << m.at(v[i]) << '\n';
	}
}
//문자열 파싱과 정렬을 사용한 문제. 첫번째 조건인 확장자 별 파일 개수는 문자열 파싱과 map을 이용해 해결했고
//두번째 조건은 정렬을 통해 해결했다.