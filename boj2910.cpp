//boj2910번_빈도 정렬_자료구조(맵),정렬

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

map<int, int> index;

bool compare(pair<int, int> x, pair<int, int> y) {
	if (x.second == y.second) {
		return index[x.first] < index[y.first];
	}

	return x.second > y.second;
}

int main() {
	int N, C;
	cin >> N >> C;

	map<int, int> m;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		m[num]++;

		if (index[num] == 0) {
			index[num] = i + 1;
		}
	}

	vector<pair<int, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].second; j++)
		{
			cout << v[i].first << " ";
		}
	}
}

//맵과 정렬을 사용한 문제. 맵을 정렬하려면 맵을 벡터로 옮긴 후 sort함수를 사용해서 정렬해야된다.