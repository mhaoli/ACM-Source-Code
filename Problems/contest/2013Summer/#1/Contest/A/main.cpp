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

int main()
{
    //freopen("a.in","r",stdin);
    int n;
    scanf( "%d" , &n );
    int64 a = 1 , b = 1 ,sum = 2;
    if( n == 1 )
        printf( "1\n" );
    else if( n == 2 )
        printf( "2\n" );
    else{
        int cnt = 2;
        while( cnt < n ){
            cnt ++;
            int64 c = a + b;
            a = b;
            b = c;
            sum += c;
        }
        cout << sum << endl;
    }
    return 0;
}
