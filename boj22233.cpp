//boj22233번_가희와 키워드_자료구조(맵)

/*시간초과
#include<iostream>
#include<map>
#include<vector>
#include<sstream>


using  namespace std;

vector<string> split(string s, char c) {
	istringstream iss(s);
	string buffer;

	vector<string> result;

	while (getline(iss, buffer, c)) {
		result.push_back(buffer);
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> m;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		if (m.find("s") == m.end()) {
			m.insert({ s, 1 });
		}
		else {
			m.find("s")->second++;
		}
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;

		vector<string> v = split(str, ',');

		for (int j = 0; j < v.size(); j++) {
			if (m.find(v[j]) != m.end()) {
				if (m.find(v[j])->second == 1) {
					m.erase(m.find(v[j]));
				}
				else {
					m.find(v[j])->second--;
				}
			}
		}

		cout << m.size() << '\n';
	}

}
*/

#include<iostream>
#include<unordered_set>
#include<vector>

using  namespace std;

unordered_set<string> s;
unordered_set<string>::iterator it;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		s.insert(str);
	}

	for (int i = 0; i < M; i++) {
		string str;
		string word = "";
		cin >> str;

		vector<string> v;

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == ',') {
				v.push_back(word);
				word = "";
			}
			else {
				word += str[j];
			}
		}
		v.push_back(word);

		for (int j = 0; j < v.size(); j++) {
			it = s.find(v[j]);

			if (it != s.end()) {
				s.erase(it);
			}
		}

		cout << s.size() << '\n';
	}
}
//자료구조 unordered_set문제. 이 문제를 통해 unordered_set에 대해 알게 되었다.
//unordered_set이란 set인데 삽입할때 정렬이 되지않고 삽입한 순서대로 순서를 유지시키는 set을 말한다.
//시간이 진짜 중요한 문제라 unordered_set을 사용하지 않으면 거의 무조건 시간초과가난다...
