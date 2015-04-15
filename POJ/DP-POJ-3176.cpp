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
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int maxx = 355;
int an[maxx][maxx],dp[maxx][maxx];

int DP(int n)
{
	memset(dp,0,sizeof(dp));
	dp[1][1] = an[1][1];
	for(int i = 2;i <= n;i ++)
		for(int j = 1;j <= i;j ++)
		{
			dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + an[i][j];
		}
	int ans = 0;
	//for(int i = 1;i <= n;i ++){
	//	for(int j = 1;j <= i;j ++){
	//		printf("%d ",dp[i][j]);
	//	}
	//	puts("");
	//}
	for(int i = 1;i <= n;i ++)
		ans = max(ans,dp[n][i]);
	return ans;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n;
	while(scanf("%d",&n) != EOF){
		//if(n == -1)
		//	break;
		memset(an,0,sizeof(an));
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= i;j ++){
				scanf("%d",&an[i][j]);
			}
		}
	//	for(int i = 1;i <= n;i ++){
	//		for(int j = 1;j <= n;j ++){
	//			printf("%d ",an[i][j]);
	//		}
	//		puts("");
	//	}
		printf("%d\n",DP(n));
	}
	return 0;
}
