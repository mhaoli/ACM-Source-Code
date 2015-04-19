//by iforgot
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define int64 long long
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

using namespace std;
const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;

int main()
{
	//freopen("a.in","r",stdin);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	printf( "%.9lf" ,  ( a*d + 0.0 ) / ( a*d + b*c - a*c + 0.0 ) );	
	return 0;
}
