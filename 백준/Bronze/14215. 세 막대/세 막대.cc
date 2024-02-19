//boj14215번_세 막대_수학

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	vector<int> v;

	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	sort(v.begin(), v.end());

	if (v[0] + v[1] > v[2]) {
		cout << a + b + c;
	}
	else {
		cout << (v[0] + v[1]) * 2 - 1;
	}
}