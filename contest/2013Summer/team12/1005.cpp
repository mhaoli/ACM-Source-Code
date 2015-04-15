/*
 * Author:  plum rain
 * Created Time:  2013-08-24 14:18
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
const int maxx = 10000;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

int all, an[maxx], bn[maxx];

void int_dev (int x)
{
    all = -1;
    for (int i = 2; i*i <= x;){
        if (!(x%i)){
            an[++all] = i;
            bn[all] = 0;
        }
        while (!(x%i)){
            ++ bn[all];
            x /= i;
        }
        if (i == 2) ++ i;
        else i += 2;
    }
    ++ all;
    if (x != 1){
        an[all] = x;
        bn[all++] = 1;
    }
}

int solve(int l, int r)
{
    if (l > r || r % l) return 0;
    if (l == r) return 1;

    int x = r / l;
    int_dev(x);
    int ret = 1;
    for (int i = 0; i < all; ++ i)
        ret *= (6 * bn[i]);
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T --){
        int l, r;
        scanf ("%d%d", &l, &r);
        
        int ans = solve (l, r);
        printf ("%d\n", ans);
    }
    return 0;
}
