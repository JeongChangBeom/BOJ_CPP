#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int a,b;
	a = x < (w - x) ? x : (w - x);
	b = y < (h - y) ? y : (h - y);

	int result;
	result = a < b ? a : b;

	cout << result << endl;

	return 0;
}