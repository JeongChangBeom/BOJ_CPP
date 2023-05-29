//boj1806번_부분합_투포인터


#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[100001];
vector <int> result;

int main() {
	int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int sum = 0;
	int num = 0;

	while (end <= N && start <= end) {
		if (sum >= S) {
			result.push_back(num);
			sum -= arr[start];
			start++;
			num--;
		}
		else {
			sum += arr[end];
			end++;
			num++;
		}
	}

	sort(result.begin(), result.end());

	if (result.size() == 0) {
		cout << "0";
	}
	else {
		cout << result.front();
	}
	return 0;
}
//start와 end 두개의 포인터를 만들어 두 포인터 사이의 값들의 합을 부분합이라고 생각하고 풀면 해결할 수 있는 문제