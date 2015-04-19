/*
 * Author:  plum rain
 * Created Time:  2013-08-19 10:39
 * File Name: math-LA-4123.cpp
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
#define zero(x) (((x)>0?(x):-(x))<eps)
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

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

int64 min(int64 a, int64 b)
{
    return a < b? a: b;
}

int64 C(int64 y, int64 x)
{
    if (y < x) return 0;
    x = min (x, y-x);

    int64 ret = 1;
    for (int64 i = y, j = 1; i > y - x; -- i, ++ j)
        ret = (ret * i) / j;
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, test = 0;
    while (scanf ("%d", &n) != EOF && n){
        printf ("Case %d: ", ++ test);
        if (n&1 || n == 2) printf ("0\n");
        else if (n == 4) printf ("1\n");
        else{
            int r = (n + 4) / 2, o = (n - 4) / 2;
            cout << C((int64)r, (int64)o) + C((int64)(r-1), (int64)(o-1))<< endl;
        }
    }
    return 0;
}
