#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main () {
	long long M, N=10;
	M = 2;
	long long c;

	c = M == 2 ? N-1 : pow((long long)N,(double)1/2);
	cout << c << endl;
	return 0;
}