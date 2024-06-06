//boj30802번_웰컴 키트_구현

#include<iostream>

using namespace std;

int main() {
	int N;
	int size[6];
	int T, P;

	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> size[i];
	}
	cin >> T >> P;

	int t_shirt = 0;
	int pen_bundle = 0;
	int pen_piece = 0;

	for (int i = 0; i < 6; i++) {
		t_shirt += size[i] / T;
		if (size[i] % T != 0) {
			t_shirt++;
		}
	}

	pen_bundle = N / P;
	pen_piece = N % P;

	cout << t_shirt << '\n';
	cout << pen_bundle << " " << pen_piece;
}