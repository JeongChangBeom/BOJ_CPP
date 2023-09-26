//boj7795번_먹을 것인가 먹힐 것인가_두 포인터

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int N, M;

		cin >> N >> M;

		vector<int> A;
		vector<int> B;

		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			A.push_back(num);
		}

		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			B.push_back(num);
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int result = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (A[i] <= B[j]) {
					break;
				}
				result++;
			}
		}
		cout << result << '\n';
	}
}
//A의 값들과 B의 값들을 저장한 벡터에 각각의 i,j라는 두개의 포인터를 두고 해결한 문제.
//A벡터와 B벡터를 정렬한 후 A의 값과 B의 값을 비교해가며 A의 값이 B의 값보다 작거나 같을 경우
//다음 포인터로 넘기는 식으로 구현했다.