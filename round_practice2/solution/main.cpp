#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 4000;

int tree[MAX][MAX];

int ready(int x, int y) {
	int sum = 0;
	while (y > 0) {
		sum += tree[x][y];
		y -= (y & -y);
	}
	return sum;
}

int readx(int x, int y) {
	int sum = 0;
	while (x > 0) {
		sum += ready(x, y);
		x -= (x & -x);
	}
	return sum;
}

void updatey(int x, int y, int val) {
	while (y < MAX) {
		tree[x][y] += val;
		y += (y & -y);
	}
}

void updatex(int x, int y, int val) {
	while (x < MAX) {
		updatey(x, y, val);
		x += (x & -x);
	}
}

int query(int x, int y, int d) {
	int ans = readx(x + d - 1, y + d - 1);
	ans -= readx(x + d - 1, y - 1);
	ans -= readx(x - 1, y + d - 1);
	ans += readx(x - 1, y - 1);
	return ans;
}

bool test(int x, int y, int size) {
	if (size == 0) return true;
	return query(x, y, size) == 0;
}

int main() {
	        freopen("/Users/albertxavier/workspace/kickstart/round_c/b/cmake-build-debug/B-small-practice.in", "r", stdin);
//        freopen("input.txt", "r", stdin);

		freopen("/Users/albertxavier/workspace/kickstart/round_c/b/cmake-build-debug/output_ref.txt", "w", stdout);

	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		memset(tree, 0, sizeof(tree));
		int R, C, K;
		cin >> R >> C >> K;
		cerr << "Case #" << cas << endl;
		for (int i = 0; i < K; i++) {
			int r, c;
			cin >> r >> c;
			updatex(r + 1, c + 1, 1);
		}
		long long ans = 0;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				int left = 0, right = min(R - i + 1, C - j + 1);
				while (left < right) {
					int mid = (left + right + 1) / 2;
					if (test(i, j, mid)) {
						left = mid;
					} else {
						right = mid - 1;
					}
				}
				ans += left;
			}
		}
		cout << "Case #" << cas << ": " << ans << endl;

		for (auto row: tree) {
			for (auto x: row) {
				cout << x <<" ";
			}
			cout << endl;
		}
		cout << endl;
		for (auto row: tree) {
			for (auto x: row) {
				cout << x <<" ";
			}
			cout << endl;
		}
		cout << endl;
	}
}