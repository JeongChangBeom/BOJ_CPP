//boj8979번_올림픽_정렬

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct country {
	int number;
	int gold;
	int silver;
	int bronze;

	int rank;
};
bool compare(country x, country y) {
	if (x.gold > y.gold) {
		return true;
	}
	else if (x.gold == y.gold) {
		if (x.silver > y.silver) {
			return true;
		}
		else if (x.silver == y.silver) {
			if (x.bronze > y.bronze) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	int N,K;
	cin >> N >> K;

	vector<country> v;

	for (int i = 0; i < N; i++) {
		country coun;
		cin >> coun.number >> coun.gold >> coun.silver >> coun.bronze;
		coun.rank = 1;
		v.push_back(coun);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 1; i < N; i++) {
		if (v[i].gold == v[i - 1].gold &&
			v[i].silver == v[i - 1].silver &&
			v[i].bronze == v[i - 1].bronze) {
			v[i].rank = v[i - 1].rank;
		}
		else {
			v[i].rank = i + 1;
		}
	}

	
	for (int i = 0; i < N; i++) {
		if (v[i].number == K) {
			cout << v[i].rank;
			break;
		}
	}
}

//구조체를 활용해서 풀 수 있는 정렬 문제. 금은동 개수가 같으면 같은 등수로 만드는 부분을 간과해서 틀렸었다.