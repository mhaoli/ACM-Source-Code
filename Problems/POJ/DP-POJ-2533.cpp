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
const int maxx = 1005;
int an[maxx],d[maxx];

int binsearch(int l,int r,int x)
{
	while(l <= r)
	{
		int mid = (l+r) >> 1;
		if(d[mid] <= x)
			l = mid + 1;
		else 
			r = mid - 1;
	}
	return l;	
}

int LIS(int n)
{	
	memset(d,0,sizeof(d));
	d[1] = an[1];
	int len = 1;
	for(int i = 2;i <= n;i ++){
		int j;
		if(an[i] < d[1])
			j = 1;
		else if(an[i] > d[len])
			j = ++ len;
		else 
			j = binsearch(1,len,an[i]);
		d[j] = an[i];
	}
	return len;
}

int main()
{
	//freopen("a.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&an[i]);
	}
	int ans = LIS(n);
	cout<<ans<<endl;
	return 0;
}
