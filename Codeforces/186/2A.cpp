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
	//freopen("a.out","w",stdout);
	int n;
	while( cin >> n ){
		if( n >= 0 )
			cout << n << endl;
		else{
			if( n >= -10 )
				cout << "0" << endl;
			else{
				int a = n % 10 , b = (n % 100 - a) / 10 , c = n - a - 10*b;
				int d = max( a , b );
				c = c / 10 + d;
				cout << c << endl;
			}
		}
	}
	return 0;
}
