//boj14425번_문자열 집합_이진 탐색

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<string> v1;
	vector<string> v2;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		v1.push_back(s);
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		v2.push_back(s);
	}

	sort(v1.begin(), v1.end());

	int count = 0;

	for (int i = 0; i < M; i++) {
		if (binary_search(v1.begin(), v1.end(), v2[i])) {
			count++;
		}
	}
	cout << count;
}
//문제의 태그는 자료구조이며 해시를 이용한 집합과 맵으로 나와있지만 이진탐색으로 풀수도 있을것
//같아 이진탐색으로 풀었더니 해결됐다. 이진탐색은 정렬이 된 배열이나 벡터에만 사용할 수 있는 점이 중요하다