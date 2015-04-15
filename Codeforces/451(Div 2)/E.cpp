/*
 * Author:  Plumrain
 * Created Time:  2014/7/25 11:00:29
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
const int mod = 1e9 + 7;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 an[25];

int64 pow_mod (int64 p, int64 n){
    p %= mod;
    int64 ret = 1;
    while (n){
        if (n & 1) ret = ret * p % mod;
        n >>= 1;
        p = p * p % mod;
    }
    return ret;
}

int64 C (int64 m, int64 n){
    int64 ret = 1;
    for (int64 i = m; i >= m - n + 1; -- i) ret = ret * (i % mod) % mod;
    int64 fac = 1;
    repf (i, 1, n) fac = fac * i % mod;
    ret = (ret * pow_mod (fac, mod-2)) % mod;
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    int64 sum;
    while (cin >> n >> sum){
        repf (i, 0, n-1) cin >> an[i];

        int64 ans = 0;
        repf (i, 0, (1<<n)-1){
            int64 t = sum, num = 0;
            repf (j, 0, n-1) if (i & (1<<j)) t -= an[j] + 1, num ^= 1;
            if (t < 0) continue;
            ans += (num ? -1 : 1) * C (t + n - 1, n - 1);
            ans %= mod;
        }
        cout << (ans + mod) % mod << endl;
    }
    return 0;
}
