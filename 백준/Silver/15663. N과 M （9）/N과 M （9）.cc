//boj15663번_N과 M (9)_백트래킹

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> v;
int result[9];
bool check[9];

void DFS(int index) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
		return;
	}

	int pre_num = 0;
	for (int i = 0; i < N; i++) {
		if (!check[i] && pre_num != v[i]) {
			result[index] = v[i];
			pre_num = result[index];
			check[i] = true;
			DFS(index + 1);
			check[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	DFS(0);

	return 0;
}