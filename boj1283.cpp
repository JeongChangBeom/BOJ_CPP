//boj1283번_단축키 지정_문자열

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();

	vector<char> v;
	vector<string> result;

	for (int n = 0; n < N; n++) {
		string str;
		getline(cin, str);

		vector<string> word;
		string temp = "";

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				word.push_back(temp);
				temp = "";
			}
			else {
				temp += str[i];
			}
		}
		word.push_back(temp);

		string tmp = "";
		string tmp2 = "";

		bool flag = false;

		for (int i = 0; i < word.size(); i++) {
			if (find(v.begin(), v.end(), toupper(word[i][0])) == v.end() && !flag) {
				v.push_back(toupper(word[i][0]));

				tmp += "[";
				tmp += word[i][0];
				tmp += "]";

				for (int j = 1; j < word[i].size(); j++) {
					tmp += word[i][j];
				}
				if (i != word.size() - 1) {
					tmp += " ";
				}
				flag = true;
			}
			else {
				tmp += word[i];
				if (i != word.size() - 1) {
					tmp += " ";
				}
			}
		}
		if (!flag) {
			bool check = false;
			for (int i = 0; i < word.size(); i++) {
				for (int j = 0; j < word[i].size(); j++) {
					if (find(v.begin(), v.end(), toupper(word[i][j])) == v.end() && !check) {
						v.push_back(toupper(word[i][j]));

						for (int k = 0; k < word[i].size(); k++) {
							if (word[i][k] == word[i][j] && !check) {
								tmp2 += "[";
								tmp2 += word[i][j];
								tmp2 += "]";
								check = true;
							}
							else {
								tmp2 += word[i][k];
							}
						}
						if (i != word.size() - 1) {
							tmp2 += " ";
						}
						break;
					}
					else if (check) {
						tmp2 += word[i][j];
					}
				}
				if (tmp2 == "") {
					tmp2 = str;
				}
			}
		}
		if (flag) {
			result.push_back(tmp);
		}
		else {
			result.push_back(tmp2);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}