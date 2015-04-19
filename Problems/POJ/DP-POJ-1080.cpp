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
char ann[maxx],bnn[maxx];
int dp[maxx][maxx];

int sim(char x,char y)
{
	if(x == y)
		return 5;
	if((x > y && y != '-') || x == '-'){
		char c = x;
		x = y;
		y = c;
	}
	if(x == 'A'){
		if(y == 'C')
			return -1;
		if(y == 'G')
			return -2;
		if(y == 'T')
			return -1;
		if(y == '-')
			return -3;
	}
	if(x == 'C'){
		if(y == 'G')
			return -3;
		if(y == 'T')
			return -2;
		if(y == '-')
			return -4;
	}
	if(x == 'G'){
		if(y == 'T')
			return -2;
		if(y == '-')
			return -2;
	}
	if(x == 'T'){
		if(y == '-')
			return -1;
	}
}

int DP(int a,int b)
{
	memset(dp,0,sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1;i <= a;i ++)
		dp[i][0] = dp[i-1][0] + sim(ann[i-1],'-');
	for(int i = 1;i <= b;i ++)
		dp[0][i] = dp[0][i-1] + sim('-',bnn[i-1]);
	for(int i = 1;i <= a;i ++)
		for(int j = 1;j <= b;j ++){
			int a1 = dp[i-1][j]+sim(ann[i-1],'-');
			int a2 = dp[i][j-1]+sim('-',bnn[j-1]);
			int a3 = dp[i-1][j-1]+sim(ann[i-1],bnn[j-1]);
			dp[i][j] = max(a1,a2);
			dp[i][j] = max(dp[i][j],a3);
		}
//	for(int i = 0;i <= a;i ++){
//		for(int j = 0;j <= b;j ++){
//			printf("%d ",dp[i][j]);
//		}
//		puts("");
//	}
	return dp[a][b];
}

int main()
{
	//freopen("a.in","r",stdin);
	int t;
	scanf("%d",&t);
	for(int i = 0;i < t;i ++){
		int a,b;
		cin>>a>>ann>>b>>bnn;
	    printf("%d\n",DP(a,b));
	}
	return 0;
}
