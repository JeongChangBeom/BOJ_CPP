//boj2607번_비슷한 단어_구현

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int first_alpha[26];
string arr[101];

int compare(int arr1[], string word) {
	int same = 0;

	int arr2[26];
	for (int i = 0; i < 26; i++) {
		arr2[i] = arr1[i];
	}

	for (int i = 0; i < word.size(); i++) {
		if (arr2[word[i] - 'A'] > 0) {
			arr2[word[i] - 'A']--;
			same++;
		}
	}

	return same;
}

int main() {
	int N;
	cin >> N;


	int result = 0;
	int first_length = 0;
	int next_length = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			first_length = arr[i].size();

			for (int j = 0; j < arr[i].size(); j++) {
				first_alpha[arr[i][j] - 'A']++;
			}
		}
		else {
			next_length = arr[i].size();

			if (first_length == next_length) {
				if (compare(first_alpha, arr[i]) == first_length || first_length - compare(first_alpha, arr[i]) == 1) {
					result++;
				}
			}
			else if (first_length - next_length == 1) {
				if (first_length - compare(first_alpha, arr[i]) == 1) {
					result++;
				}
			}
			else if (first_length - next_length == -1) {
				if (first_length == compare(first_alpha, arr[i])) {
					result++;
				}
			}
		}
	}
	cout << result;
}
//구현문제.
//상당히 애먹었던 문제이다. 같은 구성을 가지려면 두 개의 단어가 같은종류의 문자로 이루어져 있으며, 같은 문자는 같은 개수 만큼 있어야된다.
//이 문제는 단순하게 같은 구성을 가진 단어를 찾는 것이아니라, 비슷한 단어를 찾는 것인데 그 조건은 같은 구성을 갖거나, 한 문자를 더하거나, 빼거나
//다른 문자로 바꿨을 때 같은 구성을 가진 단어를 찾는 것이다.
//비슷한 단어를 찾는 핵심은 총 3가지로 1. 두 개의 단어의 길이가 같을 때, 구성이 같은지 한글자만 다른지 검사, 2. 첫 번째 단어가 한 글자 길때 한 글자를 추가해서 비슷한 단어가 되는지
//3. 첫 번째 단어가 한 글자 짧을 때 한 글자를 빼서 비슷한 단어가 될 수 있는지. 이렇게 3가지를 구현하면 해결할 수 있다.