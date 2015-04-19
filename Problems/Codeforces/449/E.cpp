/*
 * Author:  Plumrain
 * Created Time:  2014/8/3 20:16:23
 * File Name: E.cpp
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
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = (int)1e6 + 5;
const int mod = 1000000007;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool check[maxn];
int g[maxn], gsum[3][maxn];
int prm[maxn], phi[maxn], gd[maxn];

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

void phi_init (int n){
    clr (check, 0); phi[1] = 1;
    int tot = 0;
    repf (i, 2, n){
        if (!check[i]) prm[tot++] = i, phi[i] = i - 1;
        repf (j, 0, tot-1){
            if (i * prm[j] > n) break;
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0){
                phi[i*prm[j]] = phi[i] * prm[j]; break;
            }
            else phi[i*prm[j]] = phi[i] * (prm[j] - 1);
        }
    }
}

void gcd_init (int n){
    clr (gd, 0);
    repf (i, 1, n){
        for (int j = 0; j <= n; j += i){
            add (gd[j], (int)(1LL * i * phi[j/i]));
        }
    }
}

void init(int n){
    phi_init (n);
    gcd_init (n);

    repf (i, 1, n){
        g[i] = mod - (3LL * i * i % mod);
        add (g[i], gd[i]); add (g[i], gd[i]);
        int tmp;
        if (i % 3 == 0) tmp = (1LL * (i/3) * (i+1) % mod) * (2*i+1) % mod;
        else if (i % 3 == 1) tmp = (1LL * (2*i+1)/3 * i % mod) * (i + 1) % mod;
        else tmp = (1LL * (i+1)/3 * i % mod) * (2*i + 1) % mod;
        add (g[i], tmp);
    }

    clr (gsum, 0);
    repf (i, 1, n){
        int tmp = 1;
        repf (j, 0, 2){
            gsum[j][i] = gsum[j][i-1];
            add (gsum[j][i], (int)(1LL * tmp * g[i] % mod));
            tmp = (int)(1LL * tmp * i % mod);
        }
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init (maxn - 5);
    repcase{
        int n, m; scanf ("%d%d", &n, &m);
        int mi = min (n, m);
        int ans = (int)(1LL * ((1LL*m*n+m+n+1) % mod) * gsum[0][mi] % mod);
        ans = (ans - (1LL * ((n + m + 2) % mod) * gsum[1][mi] % mod)) % mod;
        if (ans < 0) ans += mod;
        add (ans, gsum[2][mi]);
        printf ("%d\n", (int)ans);
    }
    return 0;
}
