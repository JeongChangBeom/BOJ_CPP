//boj2075번_N번째 큰수_정렬, 우선순위 큐

//메모리초과
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	int N;
//	cin >> N;
//	vector<int> v;
//
//	for (int i = 0; i < (N * N); i++) {
//		int num;
//		cin >> num;
//		v.push_back(num);
//	}
//
//	sort(v.begin(), v.end());
//	cout << v[N * N - N];
//}

//메모리 초과
//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int main() {
//	int N;
//	cin >> N;
//	priority_queue<int> pq;
//
//	for (int i = 0; i < (N * N); i++) {
//		int num;
//		cin >> num;
//		pq.push(num);
//	}
//
//	for (int i = 0; i < N - 1; i++) {
//		pq.pop();
//	}
//
//	cout << pq.top();
//}

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct compare {
	bool operator()(int x, int y) {
		return x > y;
	}
};

int main() {
	ios_base::sync_with_stdio(false); // <- 입출력 가속이 없으면 시간초과
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int,vector<int>,compare> pq;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			pq.push(num);
		}
		while (pq.size() > N) {
			pq.pop();
		}
	}

	cout << pq.top();
}
//우선순위 큐를 사용해 해결할 수 있는 문제.
//맨처음에는 벡터에 값을 전부 받아 정렬후 출력했더니 메모리초과가났다.
//다음에는 우선순위큐에 모든 입력값을 저랑했더니 똑같이 메모리초과가났다.
//그래서 우선순위큐에 N번째까지 큰수를 제외한 모든수를 pop하는 방법으로 해결했다.