//boj23971번_ZOAC 4_수학

#include<iostream>
#include<cmath>

using namespace std;

int main() {
	double H, W, N, M;
	cin >> H >> W >> N >> M;

	int x = ceil(W / (M + 1));
	int y = ceil(H / (N + 1));

	cout << x * y;
}
//최대한 많이 사람이 앉으려면 첫번째칸(0,0)부터 거리두기 수칙을 지키면서 앉아야 된다.
//가로에 몇 명 앉을 수 있는지 세로에 몇 명 앉을 수 있는지 구해서 곱하면 구할 수 있다.
//가로, 세로에 몇 명 앉을 수 있는지 구하는 법은 {테이블의 개수 / (몇 칸마다 한명씩 앉을 수 있는지)} << 이 값을 올림해주면 된다.
//올림하는 이유는 첫번째칸(0,0)에는 무조건 사람이 앉기 때문이다.