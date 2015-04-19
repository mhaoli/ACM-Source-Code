/*
 * Author:  plum rain
 * Created Time:  2013-08-17 10:41
 * File Name: math-UVa-11361.cpp
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

int mod;
int an[40];
int num[40];
int f[11][100][100];

int Mypow(int p, int n)
{
    int sq = 1;
    while (n > 0){
        if (n & 1) 
            sq = sq * p;
        n /= 2;
        p = p * p;
    }
    return sq;
}

int asklen(int x)
{
    if (!x) return 1;
    int ret = 0;
    while (x > 0){
        an[ret ++] = x % 10;
        x /= 10;
    }
    return ret;
}

int askf(int d, int m1, int m2)
{
    if (f[d][m1][m2] != -1)
        return f[d][m1][m2];

    int ret = 0;
    if (d == 0){ 
        f[d][m1][m2] = (!m1 && !m2);
        return (!m1 && !m2);
    }

    for (int i = 0; i < 10; ++ i){
        int mm1 = (m1 - i) % mod;
        if (mm1 < 0) mm1 += mod;
        int mm2 = (m2 - i * Mypow(10, d-1)) % mod;
        if (mm2 < 0) mm2 += mod;
        ret += askf (d-1, mm1, mm2);
    }
    f[d][m1][m2] = ret;
    return ret;
}

int solve (int x)
{
    int ret = 0;
    if (x == 0) return 1;
    if (mod == 1) return x+1;
    CLR (an), CLR (num);
    int len = asklen(x);
    int cnt = 1;
    cnt = Mypow(10, len-1);
    for (int i = len-1; i >= 0; -- i){
        for (int j = 0; j < an[i]; j ++){
            num[i] = j;
            int m1 = 0, m2 = 0;
            int tmp = cnt;
            for (int k = len-1; k >= i; -- k)
                m1 += num[k], m2 += num[k] * tmp, tmp /= 10;
            m1 = (mod - m1) % mod, m2 = (mod - m2) % mod;
            if (m1 < 0) m1 += mod;
            if (m2 < 0) m2 += mod;
            ret += askf (i, m1, m2);
        }
        num[i] = an[i];
    }
    if (!(x % mod)){
        int num_sum = 0;
        for (int i = 0; i < len; ++ i)
            num_sum += num[i];
        if (!(num_sum % mod)) ++ ret;
    }
    return ret;
}

int main()
{
//    freopen("tst.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        int a, b;
        scanf ("%d%d%d", &a, &b, &mod);
        if (mod >= 100)
            printf ("0\n");
        else {
            memset (f, -1, sizeof (f));
            printf ("%d\n", solve (b) - solve (a-1));
        }
    }
    return 0;
}
