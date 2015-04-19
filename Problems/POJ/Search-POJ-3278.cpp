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
const int maxx = 100005;
int n,k,ans;
bool vist[maxx];

class SE{
	public:
		int x;
		int time;
}pos[maxx];

void bfs (int x)
{
	int left = 0 , right = 1;
	vist[x] = 1;
	pos[0].x = x;
	pos[0].time = 0;
	while (left < right){
		x = pos[left].x;
		int time = pos[left++].time;
		if (x == k)
		{
			ans = time;
			return;
		}
		if (x - 1 >= 0 && !vist[x - 1])
		{
			pos[right].x = x - 1;
			pos[right++].time = time + 1;
			vist[x - 1] = 1;
		}
		if (x + 1 <= maxx && !vist[x + 1])
		{
			pos[right].x = x + 1;
			pos[right++].time = time + 1;
			vist[x + 1] = 1;
		}
		if (2 * x <= maxx && !vist[2 * x])
		{
			pos[right].x = 2 * x;
			pos[right++].time = time + 1;
			vist[2 * x] = 1;
		}
	}
	return;
}

int main()
{
	//freopen("a.in","r",stdin);
	while (cin >> n >> k){
		if (n == -2)
			break;
		memset(vist,false,sizeof(vist));
		ans = 0;
		bfs(n);
		cout<<ans<<endl;
	}
	return 0;
}
