//boj25556번_포스택_스택

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<stack<int>> v(4);
	bool check = true;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		bool pushCheck = false;

		for (int j = 0; j < 4; j++) {
			if (v[j].empty()) {
				v[j].push(num);
				pushCheck = true;
				break;
			}
			else {
				if (v[j].top() < num) {
					v[j].push(num);
					pushCheck = true;
					break;
				}
			}
		}
		if (!pushCheck) {
			check = false;
			break;
		}
	}


	if (check) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}