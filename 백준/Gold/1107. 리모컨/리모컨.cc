//boj1107번_리모컨_브루트포스

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

bool arr[10];

bool check(int x) {
	for (int i = 0; i < to_string(x).size(); i++) {
		if (arr[to_string(x)[i] - '0']) {
			return false;
		}
	}
	return true;
}

int main() {
	string N;
	cin >> N;

	int M;
	cin >> M;


	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		arr[num] = true;
	}

	if (N == "100") {
		cout << "0";
		return 0;
	}

	int result = abs(100 - stoi(N));

	int result_two = 0;

	for (int i = 0; i < 1000001; i++) {
		if (check(i)) {
			result_two = abs(stoi(N) - i) + to_string(i).size();
			result = min(result, result_two);
		}
	}

	cout << result;

}