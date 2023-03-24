//boj1620번_나는야 포켓몬 마스터 이다솜_자료구조

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

/*struct Poketmon {
	int num;
	string name;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<Poketmon> book;

	for (int i = 1; i <= N; i++) {
		Poketmon p;
		p.num = i;
		cin >> p.name;
		book.push_back(p);
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		if (s[0] >= 65 && s[0] <= 90) {
			cout << book[find_if(book.begin(), book.end(), [&s](Poketmon p) { return p.name == s; }) - book.begin()].num << "\n";
		}
		else {
			cout << book[find_if(book.begin(), book.end(), [&s](Poketmon p) { return p.num == stoi(s); }) - book.begin()].name << "\n";
		}
	}
}*/

string poketmon[999999];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	map<string, int> book;
	string name;
	
	for (int i = 1; i <= N; i++) {
		cin >> name;
		poketmon[i] = name;
		book.insert(make_pair(name, i));
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (s[0] >= 65 && s[0] <= 90) {
			cout << book[s] << "\n";
		}
		else {
			cout << poketmon[stoi(s)] << "\n";
		}
	}
}
//자료구조 맵을 사용해야되는 문제. 처음에는 구조체를 이용한 벡터를 사용해서 풀이 했는데
//시간 초과가 나서 생각을 바꿔 맵을 이용해서 풀었다.