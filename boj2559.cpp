//boj2559번_수열_두 포인터

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int arr[100001];
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	int start = 0;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		sum += arr[i];
		if (i >= (M - 1)) {
			v.push_back(sum);
			sum -= arr[start];
			start++;
		}
	}

	sort(v.begin(), v.end());

	cout << v.back();
}
//배열을 돌며 연속되는 M일 동안의 온도의 합을 구하며 벡터에 저장하고, 벡터를 정렬한 후 맨뒤 원소를 출력하면 최대값이 된다.