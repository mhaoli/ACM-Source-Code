/*
 * Author:  Plumrain
 * Created Time:  2014/9/29 14:36:30
 * File Name: C.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

int deg[111];
int sum[1<<13], siz[1<<13];
bool d[25][1<<11][25];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    for (int i = 1; i < (1<<13); ++ i) siz[i] = siz[i>>1] + (i&1);

    int n;
    scanf ("%d", &n);
    int cnt = 0;
    rep (i, 0, n-1){
        scanf ("%d", deg + i);
        if (deg[i] == 1) ++ cnt;
    }

    sort (deg, deg + n, greater<int>() );
    if (cnt < (n + 2) / 2 || deg[0] != n) return puts("NO"), 0;

    int up = 1 << (n - cnt);
    rep (i, 0, up-1){
        sum[i] = 0;
        rep (j, 0, n-cnt-1) if (i & (1<<j)) sum[i] += deg[j];
    }

    clr (d, 0);
    up >>= 1;
    rep (i, 0, up-1){
        int tsum = sum[(i^(up-1))<<1], tnum = deg[0] - 1 - tsum;
        if (tnum <= cnt && tnum+siz[(i^(up-1))<<1] >= 2){
            //tst (i); out (cnt-deg[0]+1+tsum);
            d[0][i][cnt-tnum] = 1;
        }
    }
    for (int i = 0; i < n-cnt-1; ++i, up>>=1)
        rep (j, 0, up-1) if (!(j&1)) rep (k, 0, cnt) if (d[i][j][k]){
            for (int s = j; ; s = (s-1)&j){
                int tsum = sum[(j^s)<<(i+1)], tnum = deg[i+1] - 1 - tsum;
                if (tnum >= 0 && tnum <= k && tnum+siz[(j^s)<<(i+1)] >= 2){
                    d[i+1][s>>1][k-tnum] = 1;
                }
                if (!s) break;
            }
        }
    puts (d[n-cnt-1][0][0] ? "YES" : "NO");
    return 0;
}
