/*
 * Author:  plum rain
 * Created Time:  2013-08-14 23:54
 * File Name: 
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
const int MAX = 500;
const int mod = 1000007;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

int C[MAX+10][MAX+10];

void Cinit()
{
    CLR (C);
    C[0][0] = 1;
    for (int i = 0; i <= MAX; ++ i){
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++ j)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    Cinit();

    int T;
    scanf ("%d", &T);
    int test = 0;
    while (T--){
        int n, m, k;
        scanf ("%d%d%d", &n, &m, &k);
        
        int sum = 0;
        for (int sta = 0; sta < 16; ++ sta){
            int num = 0, nn = n, mm = m;
            if (sta&1)
                ++ num, -- nn;
            if (sta&2)
                ++ num, -- nn;
            if (sta&4)
                ++ num, -- mm;
            if (sta&8)
                ++ num, -- mm;
            int tmp = C[mm*nn][k];
            if (num&1) tmp *= -1;
            sum = (sum + mod + tmp) % mod;
        }

        printf ("Case %d: %d\n", ++test, sum);
    }
    return 0;
}
