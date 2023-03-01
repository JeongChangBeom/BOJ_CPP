//boj1764번_듣보잡_정렬? 탐색?

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector <string> d;
vector <string> db;

int main() {
	int N, M;
	cin >> N >> M;

	int num = 0;

	for (int i = 0; i < N; i++) {
		string x;
		cin >> x;
		d.push_back(x);
	}

	sort(d.begin(), d.end());


	/*for (int i = 0; i < N; i++) { <- 2중 for문으로 인해 시간초과
		for (int j = 0; j < M; j++) {
			if (d[i].compare(b[j]) == 0) {
				db.push_back(d[i]);
				num++;
			}
		}
	}*/

	for (int i = 0; i < M; i++) { // <- 이진탐색을 이용해 시간초과 해결
		string x;
		cin >> x;

		if (binary_search(d.begin(), d.end(), x)) {
			db.push_back(x);
			num++;
		}
	}

	sort(db.begin(), db.end());

	cout << num << "\n";

	for (int i = 0; i < db.size(); i++) {
		cout << db[i] << "\n";
	}
}
//시간 제한이 2초인데 N과 M의 크기가 500000이므로 2중 for문을 사용하면 시간초과가 되는 문제.
//이진탐색(logN)을 사용하여 해결할 수 있었던 문제. 