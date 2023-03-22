//boj1010번_다리놓기_수학

#include<iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;

		int result = 1;
		int x = 1;
		for (int i = M; i > M - N; i--) {
			result *= i;
			result /= x++;
		}

		cout << result << "\n";
	}
}
//맨 처음에는 nCr = n!/(n-r)!r! 이라는 공식을 사용해서 팩토리얼을 사용해서 풀면 되겠다 생각했는데
//3번째 테스트 케이스에서 29팩토리얼을 계산하면서 오버플로우가 발생했다. 그래서 조합을 풀어서
//기본 원리대로 for문을 사용해서 풀었더니 맞았다.