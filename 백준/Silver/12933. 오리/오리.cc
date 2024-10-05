//boj12933번_오리_그리디 알고리즘

#include<iostream>
#include<vector>

using namespace std;

bool visited[2501];

int main() {
	string str;
	cin >> str;

	int result = 0;

	for (int i = 0; i < str.size(); i++) {
		string temp = "";
		vector<int> v;
		bool check = false;

		for (int j = i; j < str.size(); j++) {
			if (str[j] == 'q' && !visited[j] && temp == "") {
				temp += 'q';
				v.push_back(j);
			}
			else if (str[j] == 'u' && !visited[j] && temp == "q") {
				temp += 'u';
				v.push_back(j);
			}
			else if (str[j] == 'a' && !visited[j] && temp == "qu") {
				temp += 'a';
				v.push_back(j);
			}
			else if (str[j] == 'c' && !visited[j] && temp == "qua") {
				temp += 'c';
				v.push_back(j);
			}
			else if (str[j] == 'k' && !visited[j] && temp == "quac") {
				temp += 'k';
				v.push_back(j);
			}

			if (temp == "quack") {
				temp = "";

				if (!check) {
					check = true;
					result++;
				}

				for (int k = 0; k < v.size(); k++) {
					visited[v[k]] = true;
				}
			}
		}
	}

	bool flag = false;

	for (int i = 0; i < str.size(); i++) {
		if (!visited[i]) {
			flag = true;
			break;
		}
	}

	if (flag) {
		cout << -1;
	}
	else {
		cout << result;
	}

	return 0;
}