//by iforgot
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int64 long long
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

using namespace std;
const double eps = 1e-8;
const double PI = atan (1.0) * 4;
const int maxint = 2139062143;
int an[10][10], ans_an[10][10];
bool ans;
bool row[9][10], col[9][10], grid[9][10];

void Change (int a, int &x, int &y)
{
	y = a / 9;
	x = a - 9 * y;
}

void DFS (int a)
{
	if (ans)
		return;
	if (a == 81) {
		ans = true;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				ans_an[i][j] = an[i][j];
		return;
	}
	int x, y;
	Change (a, x, y);
	int k = 3 * (y / 3) + x / 3;
	if (an[y][x] == 0) {
		for (int i = 1; i < 10; i++) {
			if (!row[y][i] && !col[x][i] && !grid[k][i]) {
				an[y][x] = i;
				row[y][i] = true;
				col[x][i] = true;
				grid[k][i] = true;
				DFS (a + 1);
				an[y][x] = 0;
				row[y][i] = false;
				col[x][i] = false;
				grid[k][i] = false;
			}
		}
	}
	else {
		DFS (a + 1);
	}
	return;
}

int main ()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int t;
	cin >> t;
	while (t--) {
		memset (row, false, sizeof (row));
		memset (col, false, sizeof (col));
		memset (grid, false, sizeof (grid));
		char x;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) {
				cin >> x;
				an[i][j] = x - '0';
				if (x != '0') {
					int k = 3 * (i / 3) + j / 3;
					row[i][x - '0'] = true;
					col[j][x - '0'] = true;
					grid[k][x - '0'] = true;
				}
			}
		ans = false;
		DFS (0);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << ans_an[i][j];
			cout << endl;
		}
	}
	return 0;
}
