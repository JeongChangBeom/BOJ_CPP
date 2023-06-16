//boj11497번_통나무 건너뛰기_정렬

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int k = 0; k < T; k++) {
		int N;
		cin >> N;

		vector<int> v;

		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}

		sort(v.begin(), v.end());

		vector<int> result1;
		stack<int> result2;

		for (int i = 0; i < v.size(); i++) {
			if (i % 2 == 0) {
				result1.push_back(v[i]);
			}
			else {
				result2.push(v[i]);
			}
		}

		vector<int> result;

		for (int i = 0; i < result1.size(); i++) {
			result.push_back(result1[i]);
		}

		while (!result2.empty()) {
			result.push_back(result2.top());
			result2.pop();
		}

		int max_num = 0;

		for (int i = 1; i < result.size(); i++) {
			max_num = max(max_num, abs(result[i] - result[i - 1]));
		}
		max_num = max(max_num, abs(result[result.size() - 1] - result[0]));
		
		cout << max_num << '\n';
	}
}
//정렬을 사용해서 풀 수 있는 문제.
//문제의 조건을 만족하려면 오름차순으로 정렬후 작은 수부터 돌아가면서 앞과 뒤로 배치하면 된다.
//문제의 예시를 통해 예를 들면 2,4,5,7,9를 입력받았을 때 2,4 / 2,5,7,4 / 2,5,9,7,4 이런식으로 배치한 후
//간격간의 최대값을 구하면 그것이 문제의 해답이다. 처음에 간격의 값을 절대값으로 구하지 않아 오답처리됐었다.