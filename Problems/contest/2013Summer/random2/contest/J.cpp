/*
 * Author:  plum rain
 * Created Time:  2013年08月05日 星期一 12时59分00秒
 * File Name: J.cpp
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
const int N = 105;
const int maxx = 1440;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}
 
struct line{
    int a, b;
}lin[N];
int hash[maxx];

int main()
{
//    freopen("J.in","r",stdin);
    //freopen("a.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        int n;
        scanf ("%d", &n);
        rep (i, n){
            int a, time = 0;
            char x;
            scanf ("%d", &a);
            time += a * 60;
            scanf ("%c", &x);
            scanf ("%d", &a);
            time += a;
            lin[i].a = time;
            time = 0;
            scanf ("%d", &a);
            time += a * 60;
            scanf ("%c", &x);
            scanf ("%d", &a);
            time += a;
            lin[i].b = time;
        }
        CLR(hash);
        rep (i, maxx){
            int cnt = 0;
            rep (j, n){
                if (lin[j].a <= i && lin[j].b >= i)
                    cnt ++;
            }
            hash[i] = cnt;
        }
        int ll, rr, tmp = hash[0], tmpl = 0, ans = 0;
        repf (i, 1, maxx){
            if (tmp == hash[i])
                continue;
            if (tmp > ans){
                ans = tmp;
                ll = tmpl;
                rr = i - 1;
            }
            tmpl = i;
            tmp = hash[i];
        } 
        int l = ll, r = rr;
        if (l/60 < 10)
            printf ("0%d:", l / 60);
        else
            printf ("%d:", l / 60);
        if (l%60 < 10)
            printf ("0%d ", l % 60);
        else
            printf ("%d ", l % 60);
        if (r/60 < 10)
            printf ("0%d:", r / 60);
        else
            printf ("%d:", r / 60);
        if (r%60 < 10)
            printf ("0%d\n", r % 60);
        else
            printf ("%d\n", r % 60);
    }
    return 0;
}

