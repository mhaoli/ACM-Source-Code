/*
 * Author:  Plumrain
 * Created Time:  2014-02-27 00:03
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

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 2005;
const int M = 50005;
const int mod = 1000000007;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

vector<pii > tmp, prm;
int64 fac[M];
int an[505];

int64 pow_mod(int64 p, int64 n){
    int64 ret = 1;
    p %= mod;
    while (n > 0){
        if (n & 1) 
            ret = (ret * p) % mod;
        n >>= 1;
        p = (p * p) % mod;
    }
    return ret;
}

void init(int n){
    fac[0] = 1;
    for (int i = 1; i < n; ++ i) fac[i] = fac[i-1] * i % mod;
}

int64 C(int n, int m){
    if (n <= m || !m) return 1;
    int64 ret = 1;
    //for (int i = 1; i <= m; ++ i) ret = (((ret  * (n - i + 1)) % mod) * pow_mod(i, mod-2)) % mod;
    ret = fac[n] * pow_mod (fac[n-m] * fac[m] % mod, mod-2) % mod;
    return ret;
}

bool cmp(pii a, pii b){
    return a.first < b.first;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    init(M-1);
    int n;
    while (scanf ("%d", &n) != EOF){
        prm.clear(); tmp.clear();
        repf (i, 0, n-1) scanf ("%d", &an[i]);

        for (int i = 0; i < n; ++ i){
            int t = an[i];
            for (int64 j = 2; j*j <= t; ++ j) if (t % j == 0){
                int cnt = 0;
                while (t % j == 0) ++ cnt, t /= j;
                tmp.pb (mp (j, cnt));
            }
            if (t != 1) tmp.pb (mp (t, 1));
        }
        sort (all(tmp), cmp); tmp.pb (mp (-1, 0));
//
        //repf (i, 0, sz(tmp)-1) tst (tmp[i].first), out (tmp[i].second);

        int cnt = tmp[0].second;
        for (int i = 1; i < sz(tmp); ++ i){
            if (tmp[i].first == tmp[i-1].first) cnt += tmp[i].second;
            else prm.pb (mp (tmp[i-1].first, cnt)), cnt = tmp[i].second;
        }

        //repf (i, 0, sz(prm)-1) tst (prm[i].first), out (prm[i].second);
//
        int64 ans = 1;
        repf (i, 0, sz(prm)-1) ans = ans * C(prm[i].second+n-1, n-1) % mod;
        cout << ans << endl;
    }
    return 0;
}

