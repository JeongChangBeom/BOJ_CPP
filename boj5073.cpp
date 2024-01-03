//boj5073번_삼각형과 세 변_구현

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	while (1) {
		int x, y, z;
		vector<int> v;
		cin >> x >> y >> z;

		if (x == 0 && y == 0 && z == 0) {
			return 0;
		}

		if (x == y && y == z && z == x) {
			cout << "Equilateral" << '\n';
		}

		v.push_back(x);
		v.push_back(y);
		v.push_back(z);
		
		sort(v.begin(), v.end());

		if (v[0] + v[1] > v[2]) {
			if ((x == y && y != z) || (y == z && z != x) || (z == x && x != y)) {
				cout << "Isosceles" << '\n';
			}
			if (x != y && y != z && z != x) {
				cout << "Scalene" << '\n';
			}
		}
		else {
			cout << "Invalid" << '\n';
		}

	}
}

//구현 문제.
//삼각형이 될 수 있는 조건인 작은 두변의 길이의 합이 가장 긴 변의 길이보다 커야된다는 점을 유의하면 쉽게 해결할 수 있다.
//세 변의 길이를 vector에 넣고 정렬 후 가장 작은 두변의 합과 가장 긴 변의 길이를 비교해서 해결했다.