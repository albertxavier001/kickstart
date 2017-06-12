#include "../h.h"

#include <iostream>
using namespace std;

const bool debug=0;
const bool local=1;
const int INF = 300000000;


bool cover (
	std::vector<int> &x, 
	std::vector<int> &y, 
	std::vector<int> &z, 
	std::vector<int> &r, 
	int minx, int maxx, 
	int miny, int maxy, 
	int minz, int maxz)
{
	if (0) 
	{
			cout << minx << " " << maxx 
					<< " " << miny << " " << maxy 
					<< " " << minz << " " << maxz 
					<< endl;
			// cout << " x = " ;
			// for (auto xx:x) {cout << xx <<" ";};
			  // cout << endl;
	}

	int n = x.size();
	int e = maxx - minx;
	std::vector<bool> isCovered(n, false);
	for (int i = 0; i < n; ++i)
	{
		if (
				x[i]-r[i] >= minx && 
				y[i]-r[i] >= miny &&
				z[i]-r[i] >= minz &&
				x[i]+r[i] <= maxx && 
				y[i]+r[i] <= maxy && 
				z[i]+r[i] <= maxz
			)
			isCovered[i] = true;
	}

	if (0) 
	{
		cout << "isCovered = ";
		for (auto ele: isCovered) {cout << ele << " ";}
		cout << endl;
	}

	int minx2 = INF;
	int miny2 = INF;
	int minz2 = INF;
	int maxx2 = -INF;
	int maxy2 = -INF;
	int maxz2 = -INF;

	for (int i = 0; i < n; ++i)
	{
		if (isCovered[i] == true)
			continue;
		if (debug) cout << "exist not covered" << endl;
		minx2 = min(minx2, x[i]-r[i]);
		miny2 = min(miny2, y[i]-r[i]);
		minz2 = min(minz2, z[i]-r[i]);
		maxx2 = max(maxx2, x[i]+r[i]);
		maxy2 = max(maxy2, y[i]+r[i]);
		maxz2 = max(maxz2, z[i]+r[i]);

	}

	if (
			maxx2 - minx2 <= e &&
			maxy2 - miny2 <= e &&
			maxz2 - minz2 <= e
		)
		return true;
	return false;

}


int main () 
{

	if (local)
	{
		freopen("C-large-practice.in", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	int T;
	
	

	cin >> T;
	for (int i = 0; i < T; ++i) 
	{
		int N;
		cin >> N;

		std::vector<int> x(N),y(N),z(N),r(N);
		int minx = INF;
		int miny = INF;
		int minz = INF;
		int maxx = -INF;
		int maxy = -INF;
		int maxz = -INF;
		
		for (int j = 0; j < N; ++j)
		{
			cin >> x[j] >> y[j] >> z[j] >> r[j];
			minx = min(minx, x[j]-r[j]);
			miny = min(miny, y[j]-r[j]);
			minz = min(minz, z[j]-r[j]);
			maxx = max(maxx, x[j]+r[j]);
			maxy = max(maxy, y[j]+r[j]);
			maxz = max(maxz, z[j]+r[j]);

			if (debug)
			{
				cout << minx << " " << maxx << endl;
			}
		}
		
		int lo = 0, hi = 500000000, mid;
		while (lo < hi) 
		{
			mid = lo + ((hi - lo) >> 1);
			if (0) 
			{
				cout << "lo = " << lo << " mid = " << mid << " hi = " << hi << endl;
			}
			if (debug) cout << "mid = " << mid << endl;
			if (
					cover(x,y,z,r,minx, minx+mid, miny, miny+mid, minz, minz+mid) ||
					
					cover(x,y,z,r,maxx-mid, maxx, miny, miny+mid, minz, minz+mid) ||
					cover(x,y,z,r,minx, minx+mid, maxy-mid, maxy, minz, minz+mid) ||
					cover(x,y,z,r,minx, minx+mid, miny, miny+mid, maxz-mid, maxz) ||
				
					cover(x,y,z,r,minx, minx+mid, maxy-mid, maxy, maxz-mid, maxz) ||
					cover(x,y,z,r,maxx-mid, maxx, miny, miny+mid, maxz-mid, maxz) ||
					cover(x,y,z,r,maxx-mid, maxx, maxy-mid, maxy, minz, minz+mid) ||
					
					cover(x,y,z,r,maxx-mid, maxx, maxy-mid, maxy, maxz-mid, maxz)
				) 
				hi = mid;
			else 
				lo = mid + 1;
		}

		cout << "Case #" << i+1 << ": " << lo << endl;
	}

	
	return 0;
}