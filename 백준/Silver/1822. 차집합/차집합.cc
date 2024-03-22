//boj1822번_차집합_맵

#include<iostream>
#include<set>

using namespace std;

int main() {
	int n_A, n_B;
	cin >> n_A >> n_B;

	set<int> s;

	for (int i = 0; i < n_A; i++) {
		int num;
		cin >> num;

		s.insert(num);
	}

	int result = 0;

	for (int i = 0; i < n_B; i++) {
		int num;
		cin >> num;

		if (s.find(num) == s.end()) {
			continue;
		}
		else {
			s.erase(s.find(num));
			result++;
		}
	}

	cout << s.size() << '\n';

	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
}