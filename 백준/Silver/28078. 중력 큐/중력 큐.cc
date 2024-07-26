//boj28078번_중력 큐_자료구조(덱)

#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q;
	cin >> Q;

	cin.ignore();

	deque<char> d;

	int rotate = 0;

	int b_count = 0;
	int w_count = 0;

	for (int i = 0; i < Q; i++) {
		string cmd;
		getline(cin, cmd);

		if (cmd == "push b") {
			if (rotate == 0 || rotate == 2) {
				d.push_front('b');
				b_count++;
			}
			else if (rotate == 1) {
				if (!d.empty() && d.back() == 'w') {
					d.push_front('b');
					b_count++;
				}
			}
			else if (rotate == 3) {
				continue;
			}
		}
		else if (cmd == "push w") {
			if (rotate == 0 || rotate == 2) {
				d.push_front('w');
				w_count++;
			}
			else if (rotate == 1) {
				d.push_front('w');
				w_count++;
			}
			else if (rotate == 3) {
				d.push_front('w');
				w_count++;
			}
		}
		else if (cmd == "pop") {
			if (!d.empty()) {
				if (rotate == 1) {
					if (d.back() == 'w') {
						d.pop_back();
						w_count--;

						while (!d.empty()) {
							if (d.back() == 'b') {
								d.pop_back();
								b_count--;
							}
							else {
								break;
							}
						}
					}
				}
				else {
					if (d.back() == 'b') {
						d.pop_back();
						b_count--;
					}
					else if (d.back() == 'w') {
						d.pop_back();
						w_count--;
					}
				}
			}
		}
		else if (cmd == "rotate l") {
			rotate = (rotate + 3) % 4;

			if (rotate == 1) {
				while (!d.empty()) {
					if (d.back() == 'b') {
						d.pop_back();
						b_count--;
					}
					else {
						break;
					}
				}
			}
			else if (rotate == 3) {
				while (!d.empty()) {
					if (d.front() == 'b') {
						d.pop_front();
						b_count--;
					}
					else {
						break;
					}
				}
			}
		}
		else if (cmd == "rotate r") {
			rotate = (rotate + 1) % 4;

			if (rotate == 1) {
				while (!d.empty()) {
					if (d.back() == 'b') {
						d.pop_back();
						b_count--;
					}
					else {
						break;
					}
				}
			}
			else if (rotate == 3) {
				while (!d.empty()) {
					if (d.front() == 'b') {
						d.pop_front();
						b_count--;
					}
					else {
						break;
					}
				}
			}
		}
		else if (cmd == "count b") {
			cout << b_count << '\n';
		}
		else if (cmd == "count w") {
			cout << w_count << '\n';
		}
	}

	return 0;
}