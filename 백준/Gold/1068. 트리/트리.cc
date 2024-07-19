//boj1068번_트리_그래프

#include<iostream>

using namespace std;

bool tree[51][51];
bool visited[51];

int N;
int root;
int leaf_count = 0;

int erase_node;

void DFS(int V) {
	bool leaf = true;

	for (int i = 0; i < N; i++) {
		if (tree[V][i] && i != erase_node) {
			leaf = false;
			DFS(i);
		}
	}

	if (leaf) {
		leaf_count++;
	}

}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num == -1) {
			root = i;
		}
		else {
			tree[num][i] = true;
		}
	}

	cin >> erase_node;

	if (root == erase_node) {
		cout << 0;
		return 0;
	}

	DFS(root);

	cout << leaf_count;

	return 0;
}