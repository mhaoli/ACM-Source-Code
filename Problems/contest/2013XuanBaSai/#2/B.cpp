//by iforgot
#include <iostream>
#include <cstdio>
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

int64 Gcd( int64 a , int64 b )
{
	if(b == 0)
		return a;
	else
		return Gcd(b,a%b);
}

int main()
{
    //freopen("a.in","r",stdin);
	int64 a,b;
	while( cin >> a >> b ){
		if( !a && !b )
			break;
		int64 x = Gcd(a,b);
		int64 xxx = (a / x) * b;
		int64 ans = ( xxx / a ) * ( xxx / b );
		cout << ans << endl;
	}
    return 0;
}


  

 

