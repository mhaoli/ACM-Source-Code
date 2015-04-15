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

int a,b,sum;
int an[1000];

int Binary_Search(int a, int len)
{
    int l = 0, r = len - 1;
    while(r > l){
        int mid = (l+r) / 2;
        if( an[mid] < a )
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int Gcd( int a , int b ){
    if( b == 0 )
        return a;
    else
        return Gcd(b,a%b);
}

int Data_Output()
{
    if( !a || !b )
        return 0;
    if( sum % 2 )
        return -1;
    if( sum % Gcd(a,b) ){
        //tst(aaa);
        return -1;
    }
    int x = 0;
    while( 1 ){
        if( a == b )
            return x + 1;
        if( a > b )
            swap(a,b);
        if( x > 0 ){
            sort(an,an+x);
            int pos = Binary_Search(a,x);
            if( a == an[pos-1] || a == an[pos] || a == an[pos+1] ){
                //tst(aaa);
                return -1;
            }
        }
        an[x] = a;
        b -= a;
        a *= 2;
        x ++;
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    scanf( "%d%d" , &a , &b );
    sum = a + b;
    int ans = Data_Output();
    printf( "%d\n" , ans );
    return 0;
}
