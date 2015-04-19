/*
 * Author:  Plumrain
 * Created Time:  2014/7/22 13:00:07
 * File Name: 1009.cpp
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
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int mod = 1000000009;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 cn[100005];

int64 pow_mod (int64 p, int x){
    int64 ret = 1;
    while (x){
        if (x & 1) ret = ret * p % mod;
        x >>= 1;
        p = (p * p) % mod;
    }
    return ret;
}

void init (int n){
    cn[0] = 1;
    repf (i, 1, n) cn[i] = cn[i-1] * i % mod;
}

int C (int m, int n){
    int64 ans = cn[m] * pow_mod (cn[n], mod-2) % mod;
    ans = ans * pow_mod (cn[m-n], mod-2) % mod;
    return (int)ans;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    init (100000);
    int n, m; 
    while (scanf ("%d%d", &n, &m) != EOF){
        int l = 0, r = 0, t, rr, ll;
        repf (i, 0, n-1){
            scanf ("%d", &t);
            if (r + t <= m) rr = r + t;
            else if (l + t <= m) rr = (((m-r+t)&1) ? m - 1 : m);
            else rr = 2*m - t - l;

            if (l >= t) ll = l - t;
            else if (r - t >= 0) ll = ((l+t) & 1);
            else ll = t - r;

            r = rr; l = ll;
        }

        int ans = 0;
        for (int i = l; i <= r; i += 2) ans = (ans + C (m, i)) % mod;
        printf ("%d\n", (ans + mod) % mod);
    }
    return 0;
}
