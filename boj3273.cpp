//boj3273번_두 수의 합_정렬, 두 포인터

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int x;
	cin >> x;

	sort(v.begin(), v.end());

	int result = 0;

	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] + v[j] == x) {
				result++;
			}
			if (v[i] + v[j] > x) {
				break;
			}
		}
	}
	cout << result;
}
//두 포인터를 이용한 문제. 입력받은 값을 정렬해서 두개의 포인터로 수열을 순회하며 조건을 만족하는 두수의 쌍의 개수를 찾는 문제이다.