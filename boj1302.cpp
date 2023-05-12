//boj1302번_베스트셀러_자료구조

#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	map<string,int> best;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		best[s]++;
	}

	int max = -1;
	for (auto i = best.begin(); i != best.end(); i++) {
		max = std::max(max,i->second); // <- max함수를 쓰려면 std::max를 해야된다.
	}
	for (auto i = best.begin(); i != best.end(); i++) {
		if (i->second == max) {
			cout << i->first;
			return 0;
		}
	}
}
//맵을 사용해서 풀 수 있는 문제 for문으로 맵을 순회하는 법을 알아야 쉽게 풀 수 있다.
//max함수를 사용하려 했는데 namespace가 없으면 사용이 안되던데 이유를 모르겠다.