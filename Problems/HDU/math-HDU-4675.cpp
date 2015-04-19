/*
 * Author:  plum rain
 * Created Time:  2013-08-16 11:10
 * File Name: fuck.cpp
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
const int N = 300005;
const int mod = 1000000007;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

int n, m, k;
int an[N];
int64 f[N];
int64 C[N];

int64 Mypow(int64 a, int64 n)
{
    int64 ret = 1, tmp = a % mod;
    while (n){
        if (n&1)
            ret = (ret * tmp) % mod;
        tmp = (tmp * tmp) % mod;
        n >>= 1;
    }
    return ret;
}

void Cinit()
{
    CLR (C);
    int64 x = n - k;
    C[x] = 1;
    for (int i = x; i < n; ++ i){
        C[i+1] = (C[i] * (i + 1)) % mod;
        C[i+1] = (C[i+1] * Mypow(i+1-x, mod-2)) % mod;
    }
}


void solve(int x)
{
    int cnt = 0;
    int64 sum = 0;
    for (int i = 1; i*x <= m; ++ i){
        cnt += an[i*x];
        if (i > 1) sum = (sum + f[i*x]) % mod;
    }
    int t = m / x;
    if (t == 1){
        if (cnt == n - k) f[x] = 1;
        else f[x] = 0;
        return ;
    }
    if (cnt < n - k){
        f[x] = 0;
        return;
    }
    int64 tmp = (C[cnt] * Mypow(t, n-cnt)) % mod; 
    tmp = (tmp * Mypow(t-1, cnt - n + k)) % mod;
    f[x] = (tmp - sum + mod) % mod;
}

int main()
{
//    freopen("tst.in","r",stdin);
//    freopen("fuck.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d%d%d", &n, &m, &k) != EOF){ 
        CLR (an);
        int x;
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &x);
            ++ an[x];
        }

        CLR (f);
        Cinit();
        for (int i = m; i >= 1; -- i)
            solve(i);

        printf ("%I64d", f[1]);
        for (int i = 2; i <= m; ++ i)
            printf (" %I64d", f[i]);
        printf ("\n");
    }
    return 0;
}
