//boj14713번_앵무새_큐

#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;

	cin.ignore();

	vector<queue<string>> bird;

	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);

		string word = "";

		queue<string> q;

		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ' ') {
				q.push(word);
				word = "";
			}
			else {
				word += str[j];
			}
		}
		q.push(word);

		bird.push_back(q);
	}

	string L;
	getline(cin, L);

	string temp = "";

	queue<string> L_q;

	for (int i = 0; i < L.size(); i++) {
		if (L[i] == ' ') {
			L_q.push(temp);
			temp = "";
		}
		else {
			temp += L[i];
		}
	}
	L_q.push(temp);

	int size = L_q.size();

	for (int i = 0; i < size; i++) {
		bool check = false;

		for (int j = 0; j < N; j++) {
			if (!bird[j].empty() && L_q.front() == bird[j].front()) {
				bird[j].pop();
				L_q.pop();
				check = true;
				break;
			}
		}

		if (!check) {
			cout << "Impossible";
			return 0;
		}
	}


	for (int i = 0; i < N; i++) {
		if (!bird[i].empty()) {
			cout << "Impossible";
			return 0;
		}
	}

	cout << "Possible";


	return 0;
}