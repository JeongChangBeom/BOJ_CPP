//boj10610번_30_정렬,문자열

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(char x, char y) {
	return x > y;
}

int main() {
	string N;
	string result;
	int sum = 0;

	cin >> N;

	vector<int> v;

	for (int i = 0; i < N.size(); i++) {
		v.push_back(N[i]);
		sum += N[i] - '0';
	}

	sort(v.begin(), v.end(), compare);

	if (sum % 3 == 0 && (v[v.size() - 1] - '0') == 0) {
		for (int i = 0; i < v.size(); i++) {
			result += v[i];
		}
		cout << result;
	}
	else {
		cout << -1;
	}
}
//내림차순으로 정렬한 수가 3으로 나눠지면서 끝자리수가 0이면, 만들수 있는 30의 배수중 가장 큰수 임을 이용해 해결했다.