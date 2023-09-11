//boj24060번_알고리즘 수업 - 병합 정렬 1_정렬

#include<iostream>
#include<vector>

using namespace std;

int N;
int K;
int cnt = 0;
int* tmp;


void merge(vector<int> &A, int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 1;

	while (i <= q && j <= r) {
		if (A[i] <= A[j]) {
			tmp[t++] = A[i++];
		}
		else {
			tmp[t++] = A[j++];
		}
	}

	while (i <= q) {
		tmp[t++] = A[i++];
	}

	while (j <= r) {
		tmp[t++] = A[j++];
	}

	i = p;
	t = 1;

	while (i <= r) {
		A[i++] = tmp[t++];
		if (++cnt == K) {
			cout << tmp[t - 1];
		}
	}
}

void merge_sort(vector<int> &A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;

		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main() {
	cin >> N >> K;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	tmp = new int[N];
	merge_sort(v, 0, N - 1);

	if (cnt < K) {
		cout << "-1";
	}
}
//병합정렬을 구현하는 문제.
//처음에 merge와 merge_sort를 구현할때 vector를 참조형으로 사용하지 않아 시간초과가 났었다.
//참조자를 사용하면 값을 복사하는 시간을 줄일수 있어 시간초과가 나지 않는 것 같다.