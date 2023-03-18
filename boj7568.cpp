//boj7568번_덩치_브루트포스

#include<iostream>
#include<vector>

using namespace std;

struct People {
	int kg;
	int cm;
};

bool compare(People x, People y) {
	if (x.cm < y.cm && x.kg < y.kg) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int N;
	cin >> N;

	vector<People> v;

	for (int i = 0; i < N; i++) {
		People p;
		cin >> p.kg >> p.cm;
		v.push_back(p);
	}

	for (int i = 0; i < N; i++) {
		int count = 1;
		for (int j = 0; j < N; j++) {
			if (compare(v[i], v[j])) {
				count++;
			}
		}
		cout << count << " ";
	}
}
//구조체를 이용하여 몸무게와 키를 받아 하나씩 전부 비교해보면 되는 문제.