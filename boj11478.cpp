//boj11478번_서로 다른 부분 문자열의 개수_문자열, 해시를 사용한 맵

#include<iostream>
#include<map>

using namespace std;

int main() {
	string str;
	cin >> str;

	map<string, int> m;

	for (int i = 0; i < str.size(); i++) {
		for (int j = 1; j < str.size() - i + 1; j++) {
			string s = str.substr(i, j);
			m.emplace(s, 1);
		}
	}
	cout << m.size();
}
//맵을 사용해서 해결한 문제. 문자열을 자르는 substr함수를 사용해서 부분 문자열을 구한 후
//emplace함수를 사용하여 맵에 중복없이 삽입한후 맵의 크기를 출력하는 식으로 풀었다.