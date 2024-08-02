//boj1713번_후보 추천하기_구현

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct student {
	int num;
	int count;
};

bool compare(student x, student y) {
	if (x.num < y.num) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int N;
	cin >> N;

	int M;
	cin >> M;

	vector<student> v;

	int student_num;

	for (int i = 0; i < M; i++) {
		cin >> student_num;

		bool check = false;

		for (int j = 0; j < v.size(); j++) {
			if (student_num == v[j].num) {
				v[j].count++;
				check = true;

				break;
			}
		}

		if (!check) {
			if (v.size() < N) {
				student s;
				s.num = student_num;
				s.count = 1;

				v.push_back(s);
			}
			else {
				int min = v[0].count;

				for (int j = 0; j < v.size(); j++) {
					min = std::min(v[j].count, min);
				}

				for (int j = 0; j < v.size(); j++) {
					if (min == v[j].count) {
						v.erase(v.begin() + j);
						break;
					}
				}
				student s;
				s.num = student_num;
				s.count = 1;

				v.push_back(s);
			}
		}
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].num << " ";
	}

	return 0;
}