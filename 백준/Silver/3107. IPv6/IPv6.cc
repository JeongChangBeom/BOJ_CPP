//boj3107번_IPv6_문자열

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	string ip;
	cin >> ip;

	vector<string> v;

	string temp = "";

	bool check = false;

	for (int i = 0; i < ip.size(); i++) {
		if (ip[i] == ':') {
			if (temp == "" && check == false) {
				v.push_back("A");
				check = true;
			}
			else {
				v.push_back(temp);
				temp = "";
			}
		}
		else {
			temp += ip[i];
		}
	}

	v.push_back(temp);

	vector<string> ip_result;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == "A") {
			for (int j = 0; j < 9 - v.size(); j++) {
				ip_result.push_back("0000");
			}
		}
		else {
			ip_result.push_back(v[i]);
		}
	}

	string result = "";

	for (int i = 0; i < ip_result.size(); i++) {
		string str = "";
		int count = 0;

		for (int j = 0; j < 4 - ip_result[i].size(); j++) {
			str += "0";
		}

		if (i != ip_result.size() - 1) {
			str += ip_result[i] + ":";
		}
		else {
			str += ip_result[i];
		}

		result += str;
	}

	cout << result;

	return 0;
}