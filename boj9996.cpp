//boj9996번_한국이 그리울 땐 서버에 접속하지_문자열

#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	string pat;
	cin >> pat;

	int star = pat.find('*');

	string first = pat.substr(0, star);
	string last = pat.substr(star + 1);


	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str.length() < first.length() + last.length()) {
			cout << "NE" << "\n";
			continue;
		}

		string strfirst = str.substr(0, first.size());
		string strlast = str.substr(str.size() - last.size());

		if (strfirst == first && strlast == last) {
			cout << "DA" << '\n';
		}
		else {
			cout << "NE" << '\n';
		}
	}
}
//문자열의 일부를 리턴하는 substr을 사용해서 패턴을 구해 해결한 문제.
//입력을 받은 문자열이 패턴의 길이 보다 짧으면 out of range가 나오는 점을 간과해서 틀렸었다.