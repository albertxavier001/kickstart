#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define DEBUG 0
#define LOCAL 1

#define debugln(x) cout << #x" = " << x << endl
#define debug(x) cout << #x" = " << x << " "

string modify(string str) {
	string ret = "$";
	for (char ch : str) {
		if (ch != '*') {
			ret += ch;
		} else {
			ret += string(4, '$');
		}
	}
	return ret;
}

string solve(string a, string b) {

	a = modify(a);
	b = modify(b);

	int m = a.size(), n = b.size();
	if (DEBUG) {
		cout << "n = " << n << " m = " << m << endl;
	}

	vector<vector<bool> > f(m+1, vector<bool>(n+1, false));

	if (DEBUG) {
		cout << endl;
		debugln(a);
		debugln(b);
	}

	f[0][0] = true;
	for (int i = 0; i <m; i++) {
		for (int j = 0; j <n; j++) {
			if (f[i][j]) { // 从上一个传递
				// 向下：(i+1,j)，
				// j不移动，i匹配了0个字符，所以i必须是$才能把true传递下去
				f[i+1][j] = f[i+1][j] || (a[i+1] == '$');
				// 同理, 注意可能f[i][j+1]已经是1的情况，所以要|
				f[i][j+1] = f[i][j+1] || (b[j+1] == '$');
				// 都向前移动一位，说明，ij字符平凡且相等，
				// 或者ij中至少有一个是$，并且匹配了一个字符
				f[i+1][j+1] = f[i+1][j+1] || ((a[i+1] == '$') || (b[j+1] == '$') || (a[i+1] == b[j+1])); 
			}
		}
	}
	bool match = f[m-1][n-1];
	return match ? "TRUE": "FALSE";
}

int main() {
	if (LOCAL) {
		freopen("./B-large-practice.in", "r", stdin);
		// freopen("./output.txt", "w", stdout);
	}

	int T;
	cin >> T;

	for (int i = 1; i<=T; i++) {
		string a,b;
		cin >> a >> b;
		cout << "Case #" << i << ": " << solve(a,b) << endl;
	}

	return 0;
}