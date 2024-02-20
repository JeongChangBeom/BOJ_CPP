//boj2587번_대표값2_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	vector<int> v;
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		sum += num;
	}

	sort(v.begin(), v.end());



	cout << sum / 5 << '\n' << v[2];
}