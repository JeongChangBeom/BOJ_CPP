//boj25501번_재귀의 귀재_구현

#include<iostream>
#include<cstring>

using namespace std;

int result;
char arr[1001];

int recursion(const char* s, int l, int r) {
    result++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> arr;

        cout << isPalindrome(arr);
        cout << " " << result << '\n';

        result = 0;
    }
}