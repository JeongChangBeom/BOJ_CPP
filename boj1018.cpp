//boj1018번_체스판 다시 칠하기_브루트포스

#include<iostream>
#include<algorithm>

using namespace std;

char arr[51][51];

char WB[51][51] = { {'W','B','W','B','W','B','W','B'}, //W로 시작하는 체스판
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'}, 
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'}, 
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'}, 
                    {'B','W','B','W','B','W','B','W'} };

char BW[51][51] = { {'B','W','B','W','B','W','B','W'}, //B로 시작하는 체스판
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'} };

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf_s("%1s", &arr[i][j], N * M); //띄어쓰기 없이 입력 받음(scanf_s는 백준에선 컴파일 오류가 나옴)
        }
    }

    int min_num = 99999;
    int result;

    for (int i = 0; i + 8 <= N; i++) { //체스판을 8*8으로 자르기
        for (int j = 0; j + 8 <= M; j++) {
            int WB_cnt = 0;
            int BW_cnt = 0;

            for (int x = 0; x < 8; x++) { //체스판에서 잘못 칠해진 곳을 확인
                for (int y = 0; y < 8; y++) {
                    if (arr[x+i][y+j] != WB[x][y]) {
                        WB_cnt++;
                    }
                    if (arr[x+i][y+j] != BW[x][y]) {
                        BW_cnt++;
                    }
                }
            }
            result = min(WB_cnt, BW_cnt);

            if (min_num > result) {
                min_num = result;
            }
        }
    }

    cout << min_num;
}
//모든 경우의 수를 확인하는 알고리즘으로 풀 수 있는 문제