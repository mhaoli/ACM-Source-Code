//by PlumRain
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

int64 dp[35];

int main()
{
    //freopen("a.in","r",stdin);
    int64 k;
    cin >> k;
    if( k == 1 )
        printf( "1 2\n" );
    else if( k == 2 )
        printf( "2 3\n" );
    else{
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for( int i = 3 ; i <= k ; i ++ ){
            dp[i] = 0;
            if( i % 2 ){
                int a = 0;
                //out(i);
                while( a < i / 2 ){
                    //tst(a);
                    //out(dp[a]);
                    //out(dp[a-1]);
                    dp[i] += 2 * dp[a] * dp[i-a-1];
                    a ++;
                }
                //out(dp[i]);
                dp[i] += dp[i/2] *dp[i/2];
            }
            else{
                int a = 0;
                while( a < i / 2 ){
                    dp[i] += 2 * dp[a] * dp[i-a-1];
                    a ++;
                }
            }
        }
        cout << dp[k] << ' ' << k+1 << endl;
    }
    return 0;
}
