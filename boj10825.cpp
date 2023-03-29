//boj10825번_국영수_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Student {
	string name;
	int K, E, M;
};

bool compare(Student x, Student y) {
	if (y.K < x.K) {
		return true;
	}
	else if (y.K == x.K) {
		if (y.E < x.E) {
			return false;
		}
		else if (y.E == x.E) {
			if (y.M < x.M) {
				return true;
			}
			else if (y.M == x.M) {
				if (y.name < x.name) {
					return false;
				}
				else {
					return true;
				}
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

int main() {
	int N;
	cin >> N;

	vector<Student> v;

	for (int i = 0; i < N; i++) {
		Student s;
		cin >> s.name;
		cin >> s.K;
		cin >> s.E;
		cin >> s.M;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].name << "\n";
	}
}