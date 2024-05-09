//boj1991번_트리 순회_재귀

#include<iostream>
#include<map>

using namespace std;

struct Node {
	char left;
	char right;
};

map<char, Node> m;

void pre(char node) {
	if (node != '.') {
		cout << node;
		pre(m[node].left);
		pre(m[node].right);
	}
}

void in(char node) {
	if (node != '.') {
		in(m[node].left);
		cout << node;
		in(m[node].right);
	}
}

void post(char node) {
	if (node != '.') {
		post(m[node].left);
		post(m[node].right);
		cout << node;
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		char node, left, right;
		cin >> node >> left >> right;

		m[node].left = left;
		m[node].right = right;
	}

	pre('A');
	cout << '\n';
	
	in('A');
	cout << '\n';

	post('A');
	cout << '\n';

	return 0;
}