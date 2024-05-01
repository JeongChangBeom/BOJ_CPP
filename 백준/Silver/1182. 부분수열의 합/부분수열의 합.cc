//boj1182번_부분수열의 합_백트래킹

#include<iostream>
#include<vector>

using namespace std;

int N, S;
int result = 0;
vector<int> v;

void DFS(int index, int sum) {
	if (index == N) {
		if (sum == S) {
			result++;
		}
		return;
	}
	DFS(index + 1, sum);
	DFS(index + 1, sum + v[index]);
}

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	DFS(0, 0);

	if (S == 0) {
		result--;
	}

	cout << result;
	
	return 0;
}