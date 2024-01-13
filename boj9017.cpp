//boj9017번_크로스 컨트리_구현

#include<iostream>

using namespace std;

struct team {
	int count;
	int score;
	int fifth_score;
	int fifth_count;
};

team tm[201];
int arr[1001];

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 201; i++) {
			tm[i].count = 0;
			tm[i].score = 0;
			tm[i].fifth_score = 0;
			tm[i].fifth_count = 0;
		}

		int N;
		cin >> N;	

		int rank_count = 1;
		int min_team;

		for (int i = 0; i < N; i++){
			int rank;
			cin >> rank;
			arr[i] = rank;
			tm[rank].count++;
		}

		for (int i = 0; i < N; i++) {
			if (tm[arr[i]].count < 6) {
				continue;
			}
			else {
				if (tm[arr[i]].fifth_count < 4) {
					tm[arr[i]].score += rank_count;
				}			
				if (tm[arr[i]].fifth_count == 4) {
					tm[arr[i]].fifth_score = rank_count;
				}
				tm[arr[i]].fifth_count++;
				rank_count++;
			}
		}

		for (int i = 0; i < 201; i++) {
			if (tm[i].count < 6) {
				continue;
			}
			else {
				min_team = i;
				break;
			}
		}

		for (int i = 0; i < 201; i++) {
			if (tm[i].score == 0) {
				continue;
			}
			else {
				if (tm[min_team].score > tm[i].score) {
					min_team = i;
				}
				else if (tm[min_team].score == tm[i].score) {
					if (tm[min_team].fifth_score > tm[i].fifth_score) {
						min_team = i;
					}
				}
				else {
					continue;
				}
			}
		}
		cout << min_team << '\n';
	}
}
//구현문제.
//등수를 정하는 조건이 많아 구조체배열을 통해 팀의 총점, 5등의 점수, 팀 인원 등 여러 정보를 저장해가며 풀었다.
//문제에 참가팀의 선수가 모두 6명보다 적을 때 어떻게 처리하라는지 안나와있어 헷갈렸다.
//난이도가 실버3으로 나와있는데 실버3문제는 절때 아닌 것 같다.