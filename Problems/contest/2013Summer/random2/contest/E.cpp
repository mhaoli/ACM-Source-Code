/*
 * Author:  plum rain
 * Created Time:  2013年08月05日 星期一 12时36分19秒
 * File Name: E.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define INF 999999999999
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
#define flin freopen( "a.in" , "r" , stdin )
#define flout freopen( "a.out" , "w" , stdout )
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

int solve (int a)
{
    int ret = 0;
    while (a > 0){
        ret = max (ret, a%10);
        a /= 10;
    }
    return ret + 1;
}

int toten (int a, int ma)
{
    int cnt = 1, ret = 0;
    while (a > 0){
        ret += (a%10) * cnt;
        cnt *= ma;
        a /= 10;
    }
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        int a, b;
        scanf ("%d%d", &a, &b);
        int maxa = solve(a), maxb = solve(b); 
        int aa = toten (a, maxa), bb = toten (b, maxb);
        printf ("%d\n", aa + bb);
    }
    return 0;
}
