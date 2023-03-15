//boj2869번_달팽이는 올라가고 싶다_수학

#include<iostream>

using namespace std;

//int main() {
//	int A, B, V;
//	cin >> A >> B >> V;
//
//	int sum = 0;
//	int count = 0;
//
//	while (true) {
//		count++;
// 
//		sum += A;
//
//		if (sum >= V) {
//			cout << count << "\n";
//			break;
//		}
//
//		sum -= B;
//	}
//}

int main() {
	int A, B, V;
	cin >> A >> B >> V;

	int count = 1; //무조건 1일은 걸리기 때문에 1로 초기화

	count += (V - A) / (A - B); // V - A 까지만 올라가면 다음날 낮에 바로 정상에 올라갈 수 있음

	if (((V - A) % (A - B)) != 0) { // 정상까지 조금이라도 남으면 다음날 낮에 올라가야함
		count++;
	}

	cout << count;
}
//처음에는 문제에서 요구하는 그대로 무한루프를 통해 구현했는데 시간초과가 났다.
//그 후에 다시 보니 V의 입력값이 1,000,000,000까지 가능했고 시간제한이 0.25초가
//걸려있다는 것을 깨달았다. 그래서 공식을 찾아 다시 풀어보니 정답이였다.