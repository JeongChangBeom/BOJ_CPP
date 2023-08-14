//boj1037번_약수_수학, 정수론

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	int result = 0;

	result = *min_element(v.begin(), v.end()) * *max_element(v.begin(), v.end());

	cout << result;
}
//간단한 수학문제.
//주어진 수의 약수를 가진 수를 찾으려면 약수중 가장 작은 수와 가장 큰수를 곱해주면 된다.