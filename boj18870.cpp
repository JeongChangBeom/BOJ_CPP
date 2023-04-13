//boj18870번_좌표 압축_정렬, 값/좌표 압축

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v1;
vector<int> v2;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v1.push_back(x);
		v2.push_back(x);
	}
	sort(v1.begin(), v1.end());

	v1.erase(unique(v1.begin(), v1.end()), v1.end());

	for (int i = 0; i < v2.size(); i++) {
		int index = lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin();
		cout << index << " ";
	}
}
//좌표압축 = 입력받은 값의 범위가 입력 개수 보다 훨씬 적을 때 배열의 값에 새로운 인덱스를 부여하는 것
//벡터 정렬 -> 벡터 중복값 제거 -> 압축된 벡터에서 이분탐색으로 원소 위치 찾기