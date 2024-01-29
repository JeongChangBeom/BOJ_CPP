//boj20006번_랭킹전 대기열_구현

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Player {
	int plv = 0;
	string name = "";
};

struct Room {
	int rlv = 0;
	int count = 0;
	vector<Player> player;
};

bool compare(Player a, Player b) {
	return a.name < b.name;
}

int main() {
	int p, m;
	cin >> p >> m;

	vector<Room> v;

	for (int i = 0; i < p; i++) {
		int l;
		string n;

		cin >> l >> n;

		bool room_flag = false;

		for (int j = 0; j < v.size(); j++) {
			if (v[j].count == 0) {
				continue;
			}

			if (abs(v[j].rlv - l) > 10) {
				continue;
			}

			Player py;

			v[j].count--;

			py.plv = l;
			py.name = n;
			v[j].player.push_back(py);

			room_flag = true;
			break;
		}

		if (room_flag == false) {
			Room r;
			r.rlv = l;
			r.count = m - 1;

			Player py;
			py.plv = l;
			py.name = n;

			v.push_back(r);
			v[v.size() - 1].player.push_back(py);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		sort(v[i].player.begin(), v[i].player.end(), compare);

		if (v[i].count == 0) {
			cout << "Started!" << '\n';
			for (int j = 0; j < v[i].player.size(); j++) {
				cout << v[i].player[j].plv << " " << v[i].player[j].name << '\n';
			}
		}
		else {
			cout << "Waiting!" << '\n';
			for (int j = 0; j < v[i].player.size(); j++) {
				cout << v[i].player[j].plv << " " << v[i].player[j].name << '\n';
			}
		}
	}
}
//구조체와 벡터를 사용해서 구현한 문제.
//방이 없으면 방을 생성한다.
//방에 들어가려는 플레이어의 레벨이 방의 레벨제한(처음 생성한 사람의 +-10)에 맞으면서 자리가 있을 경우
//들어가고 아니면 방을 생성한다. *조건에 맞는 방이 여러개일 경우 먼저 생성된 방을 우선적으로 들어간다.
//위 조건을 구현하면 되는 문제이다.
//그리고 출력할때 닉네임 사전순으로 출력해야되기때문에 sort함수를 이용했다.