#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int row, col, K;
char Map[MAXN][MAXN];
bool ok[MAXN][MAXN][MAXN]; // i, j, h
int size[MAXN];
int DP[MAXN][MAXN][MAXN];

int ST[MAXN][10][MAXN];

void Work()
{
	scanf("%d%d%d", &row, &col, &K);
	for (int i = 0; i < row; i ++)
		scanf("%s", Map[i]);

	for (int i = 1; i <= row; i ++)
		size[i] = i * i;
	
	memset(ok, 0, sizeof(ok));
	for (int i = 0; i < row; i ++)
		for (int j = 0; j < col; j ++)
			ok[i][j][1] = (Map[i][j] == '#');
	for (int h = 2; h <= row; h ++)
	{
		for (int i = 0; i < row; i ++)
			for (int j = 0; j < col; j ++)
			{
				if (i == row || j == 0 || j == col - 1)
					ok[i][j][h] = 0;
				else
					ok[i][j][h] = (ok[i][j][h - 1]) && (ok[i + 1][j - 1][h - 1]) && (ok[i + 1][j][h - 1]) && (ok[i + 1][j + 1][h - 1]);
			}
	}

	memset(DP, 0, sizeof(DP));

	for (int i = row - 1; i >= 0; i --)
		for (int j = 0; j < col; j ++)
		{
			for (int h = 1; ok[i][j][h]; h ++)
				DP[1][i][j] = size[h];
			if (DP[1][i][j] == 0)
				DP[1][i][j] = -1000000;
		}

	int C = (int) (log((double) col) / log(2.));
	for (int k = 2; k <= K; k ++)
	{
		// DP[k - 1][i]
		for (int i = row - 1; i >= 0; i --)
		{
			for (int j = 0; j < col; j ++)
				ST[i][0][j] = DP[k - 1][i][j];
			for (int c = 1; c <= C; c ++)
				for (int j = 0; j < col; j ++)
					if (i + (1 << (c - 1)) < col)
						ST[i][c][j] = max(ST[i][c - 1][j], ST[i][c - 1][j + (1 << (c - 1))]);
					else
						ST[i][c][j] = ST[i][c - 1][j];
		}
		for (int i = row - 1; i >= 0; i --)
		{
			for (int j = 0; j < col; j ++)
			{
				DP[k][i][j] = -1000000;
				for (int h = 1; ok[i][j][h]; h ++)
				{
					int jjleft = max(j - h + 1, 0);
					int jjright = min(j + h - 1, col - 1);
					if (i + h < row)
					{
						//for (int jj = jjleft; jj <= jjright; jj ++)
						//	DP[k][i][j] = max(DP[k][i][j], size[h] + DP[k - 1][i + h][jj]);
						int L = (jjright - jjleft + 1);
						int c = (int) (log((double) L) / log(2.));
						DP[k][i][j] = max(DP[k][i][j], size[h] + max(ST[i + h][c][jjleft], ST[i + h][c][jjright - (1 << c) + 1]));
					}
				}
				if (DP[k][i][j] < 0)
					DP[k][i][j] = -1000000;
			}
		}
	}

	int Ans = 0;
	for (int i = row - 1; i >= 0; i --)
		for (int j = 0; j < col; j ++)
			if (DP[K][i][j] > Ans)
				Ans = DP[K][i][j];
	printf("%d\n", Ans);
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
	{
		printf("Case #%d: ", Case);
		fprintf(stderr, "Case #%d: \n", Case);
		Work();
		fflush(stdout);
	}
	return 0;
}