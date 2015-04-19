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
	int n,k;
	cin >> n >> k;
	int ans = n * (n-1) / 2;
	if( ans <= k )
		cout << "no solution" << endl;
	else{
		int x = 0;
		while( x < n ){
			cout << "0 " << x++ << endl;
		}
	}
	return 0;
}
