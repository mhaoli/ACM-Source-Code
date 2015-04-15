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

bool dp[10][10][1<<9][2];

int main()
{
    //freopen("a.in","r",stdin);
    int m,n;
    scanf("%d%d" , &m , &n );
    memset(dp,false,sizeof(dp));
    for( int i = 1 ; i < m ; i ++ ){
        for( int k = 1 ; k < (1 << m) ; k ++ ){
            dp[1][i][k+]
        }
    }
    for( int i = 2 ; i <= m ; i ++ ){
        for( int j = 1 ; j <= n ; j ++ ){

        }
    }
    return 0;
}
