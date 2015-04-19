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
const int maxx = 105;
int an[maxx],bn[maxx],sum[maxx],dp[maxx];

int DP(int n)
{
	memset(dp,maxint,sizeof(dp));
	dp[0] = 0;
	for(int i = 1;i <= n;i ++){
		dp[i] = dp[i-1] + (an[i]+10)*bn[i];
		for(int j = 0;j <= i;j ++){
			dp[i] = min(dp[i],(sum[i]-sum[j]+10)*bn[i]+dp[j]);
		}	   
	}
	return dp[n];
}

int main()
{
	//freopen("a.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t --){
		memset(an,0,sizeof(an));
		memset(bn,0,sizeof(bn));
		memset(sum,0,sizeof(sum));
		int n;
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++){
			scanf("%d%d",&an[i],&bn[i]);
			sum[i] = sum[i-1] + an[i];	
		}
		printf("%d\n",DP(n));
	}
	return 0;
}
