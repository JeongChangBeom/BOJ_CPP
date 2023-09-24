//boj1141번_접두사_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int,string>> v;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back({ str.size(), str });
	}

	sort(v.begin(), v.end());

	int count = 0;

	for (int i = 0; i < v.size(); i++) {
		bool check = false;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j].second.substr(0, v[i].first) == v[i].second) {
				count++;
				break;
			}
		}
	}

	int result = N - count;

	cout << result;
}
//정렬 문제. 문제의 말이 헷갈려서 문제를 이해하는데 오래걸렸다.
//예를 들면 첫번째 예제 입력을 예를 들면
//6
//hello
//hi
//h
//run
//rerun
//running
//에서 h는 hello,hi의 접두사가 될 수 있고, run은 runnig의 접두사가 될 수 있으므로 출력이 4가 나와야 정답이다.
//문자열을 입력받아 문자열의 크기와 함께 vector에 저장하고 문자열을 정렬하여 접두사를 비교해가며 풀면 해결할 수 있다.