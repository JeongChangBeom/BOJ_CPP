//boj9375번_패션왕 신해빈_자료구조, 조합론

#include<iostream>
#include<map>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		map<string, int> m;

		for (int i = 0; i < N; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			
			if (m.find(s2) == m.end()) {
				m.insert(make_pair(s2, 1));
			}
			else {
				m[s2]++;
			}

		}

		int result = 1;
		
		for (auto it = m.begin(); it != m.end(); it++) {
			result *= it->second + 1;
		}

		cout << result - 1 << "\n";
	}
}
//map을 이용해서 풀 수 있는 문제.
//문제를 자세히 보면 사실상 옷의 종류에 대한 조합을 이용해 푸는 문제이므로 옷의 이름은 필요없다.