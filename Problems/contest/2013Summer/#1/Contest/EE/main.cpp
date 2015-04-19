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
//#define out(x) cout<<#x<<':'<<x<<endl
//#define tst(a) cout<<#a<<endl

using namespace std;
const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 8005;

int an[N];

int main()
{
    //freopen("a.in","r",stdin);
    int n,k;
    scanf( "%d%d" , &k , &n );
    for( int i = 0 ; i < n ; i ++ ){
        scanf( "%d" , &an[i] );
    }
    sort(an,an+n);
    int ans = 3, x = an[0] / 1000 , cnt = 0;
    for( int i = 0 ; i < n ; i ++ ){
        int a = an[i] / 1000;
        if( x == a ){
            cnt ++;
            if( cnt == k + 1 ){
                cnt = 1;
                ans ++;
            }
        }
        else{
            x = a;
            cnt = 1;
            ans ++;
        }
    }
    printf( "%d\n" , ans );
    return 0;
}
