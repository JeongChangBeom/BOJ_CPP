#include<iostream>

using namespace std;

bool arr[1000001];

void Eratos() {
	for (int i = 2; i * i < 1000001; i++) {
		if (!arr[i]) {
			for (int j = i * i; j < 1000001; j += i) {
				arr[j] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	arr[0] = true;
	arr[1] = true;
	Eratos();

	while (true) {
		int num;
		cin >> num;

		if (num == 0) {
			break;
		}

		bool check = false;

		for (int i = 2; i <= num; i++) {
			if (!arr[i] && !arr[num - i]) {
				cout << num << " = " << i << " + " << num - i << '\n';
				check = true;
				break;
			}
		}
		if (!check) {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}
	}
	return 0;
}