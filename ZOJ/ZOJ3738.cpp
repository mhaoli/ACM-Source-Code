/*
 * Author:  Plumrain
 * Created Time:  2014/9/24 13:53:37
 * File Name: B.cpp
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

int dig[111], siz[1<<10];

int DP (int sta, int *d, int n, vi con[]){
    int top = 0;
    for (int i = 0; sta; sta >>= 1, ++ i){
        if (sta & 1) dig[top++] = i;
    }

    int res = 0;
    d[0] = 1;
    rep (i, 0, (1<<n)-1){
        if (siz[i] >= top){
            if (siz[i] == top) res += d[i];
            continue;
        }

        vi &v = con[dig[siz[i]]];
        rep (j, 0, sz(v)-1){
            if (!(i & (1<<v[j]))) d[i|(1<<v[j])] += d[i];
        }
    }
    return res;
}

int d[1<<10], g[1<<10];
int fg[2][11];
vi con[2][11];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    siz[0] = 0;
    rep (i, 1, (1<<10)-1) siz[i] = siz[i>>1] + (i & 1);

    int n, m, p;
    while (scanf ("%d%d%d", &n, &m, &p) != EOF){
        clr (fg, 0);
        int q; scanf ("%d", &q);
        while (q--){
            int t1, t2;
            scanf ("%d%d", &t1, &t2); -- t1; -- t2;
            if (n <= t2 && t2 < n + m) swap (t1, t2);
            t1 -= n;
            if (t2 < n){
                fg[0][t2] |= (1 << t1);
            } else{
                fg[1][t1] |= (1 << (t2 - n - m));
            }
        }

        rep (i, 0, n-1){
            con[0][i].clear ();
            rep (j, 0, m-1) if ((fg[0][i] & (1<<j)) == 0) con[0][i].pb (j);
        }

        rep (i, 0, m-1){
            con[1][i].clear ();
            rep (j, 0, p-1) if ((fg[1][i] & (1<<j)) == 0) con[1][i].pb (j);
        }

        clr (d, 0);
        DP ((1<<n)-1, d, m, con[0]);
        ll ans = 0;
        rep (i, 1, (1<<m)-1) if (siz[i] == n && d[i] > 0){
            clr (g, 0);
            ans += (ll)d[i] * DP (i, g, p, con[1]);
        }
        printf ("%lld\n", ans);
    }
    return 0;
}
