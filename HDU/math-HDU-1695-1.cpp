/*
 * Author:  Plumrain
 * Created Time:  2014-03-31 20:15
 * File Name: mobius-HDU-1695.cpp
 * Solution : inclusion-exclusion
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

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 100005;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int tot, x, y;
int phi[maxn];
bool v[maxn];
int tprm[maxn];
int prm[maxn];

void phi_table(int n)
{
    clr (phi, 0);
    phi[1] = 1;
    for (int i = 2; i <= n; ++ i)
        if (!phi[i]){
            for (int j = i; j <= n; j += i){
                if (!phi[j]) phi[j] = j;
                phi[j] -= phi[j]/i;
            }
        }
}

void sieve (int n){
    int m = sqrt (n + 0.5);
    clr (v, 0); v[0] = 1;
    repf (i, 2, m) if (!v[i])
        for (int j = i*i; j <= n; j += i) v[j] = 1;
}

void primes (int n){
    sieve (n);
    tot = 0;
    repf (i, 2, n) if (!v[i]) prm[tot++] = i;
}

int64 dfs (int t, int p, int u, int n, int ma){
    int64 ret = ma / t * u;
    repf (i, p, n-1){
        if ((int64)t * tprm[i] > ma) break;
        ret += dfs (t*tprm[i], i+1, -u, n, ma);
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    primes (maxn);
    phi_table(maxn);

    repf (i, 0, tot-1) tprm[i] = prm[i];
    dfs (1, 0, 1, tot, maxn);

    int T, cas = 0;
    scanf ("%d", &T);
    while (T --){
        printf ("Case %d: ", ++ cas);

        int tmp, k;
        cin >> tmp >> x; cin >> tmp >> y >> k;

        if (k == 0 || k > y || k > x){
            puts("0"); continue;
        }

        x /= k; y /= k;
        if (x < y) swap (x, y);

        int64 ans = 0;
        repf (i, 1, y) ans += phi[i];
        repf (i, y+1, x){
            if (!v[i]){
                ans += y;
                continue;
            }

            int cnt = i, facn = 0;
            repf (j, 0, tot-1){
                if ((int64)prm[j]*prm[j] > cnt) break;
                if (cnt % prm[j] != 0) continue;
                tprm[facn++] = prm[j];
                while (cnt % prm[j] == 0) cnt /= prm[j];
            }
            if (cnt > 1) tprm[facn++] = cnt;
            //if (i == y+1){
                //out (i);
                //repf (j, 0, facn-1) out (tprm[j]);
            //}
            ans += dfs (1, 0, 1, facn, y);
        }
        cout << ans << endl;
    }
    return 0;
}
