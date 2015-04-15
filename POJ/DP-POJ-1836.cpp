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
const double eps = 1e-6;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int maxx = 1005;
double an[maxx],d[maxx];
int n;

int binsearch(int l,int r,double x)
{
    int mid;
    while(l <= r){
	mid = (int)(l+r) >> 1;
	if(d[mid-1]+eps < x && d[mid]-eps > x) 
            return mid;
	if(x > d[mid]-eps) 
            l = mid + 1;
	else 
            r = mid - 1;
    }
}

int LIS(int a,char x)
{
    int len;
    if(x == 'l'){
	memset(d,0.0,sizeof(d));
	d[1] = an[0];
	len = 1;
	for(int i = 1;i <= a;i ++){
	    int j;
	    if(an[i] < d[1]-eps) 
		j = 1;
	    else if(an[i] > d[len]+eps)
		j = ++ len;
	    else 
		j = binsearch(1,len,an[i]);
	    d[j] = an[i];    
	}	
    }
    if(x == 'r'){
	memset(d,0.0,sizeof(d));
	d[1] = an[n-1];
	len = 1;
	for(int i =n-2;i >= a;i --){
	    int j;
	    if(an[i] < d[1]-eps)
		j = 1;
	    else if(an[i] > d[len]+eps){
		j = ++ len;
	     //   out(an[i]);
		//out(d[len-1]);
	    }
	    else 
		j = binsearch(1,len,an[i]);
	    d[j] = an[i];
	}
    }
    return len;
}

int main()
{
    //freopen("a.in","r",stdin);
    while(scanf("%d",&n) != EOF){
	//if(n == -1)
	    //break;	
	for(int i = 0;i < n;i ++)
	    cin>>an[i];
	int ans = 0;
	bool xxx = true;
	for(int i = 0;i < n;i ++){
	    int left,right;
	    if(xxx){
		left = 0;
		right = LIS(0,'r');
		i --;
		xxx = false;
	    }
	    else{
		right = LIS(i+1,'r');
		left = LIS(i,'l');
	    }
	    if(i == n-1) right = 0;
	    //out(i);
	    //out(left);
	    //out(right);
	    ans = max(ans,left+right);
	}
	cout<<n-ans<<endl;
    }
    return 0;
}

