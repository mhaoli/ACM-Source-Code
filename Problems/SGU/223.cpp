/*
 * Author:  Plumrain
 * Created Time:  2014/7/13 16:59:17
 * File Name: 223.cpp
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 1100;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int sta[maxn], c[maxn], n, tot;
int64 d[11][maxn][101];

void dfs (int p, int t){
    if (p >= n){
        sta[tot] = t;
        c[tot++] = __builtin_popcount(t);
        return;
    }
    dfs (p+1, t<<1);
    if (!(t & 1)) dfs (p+1, t<<1|1);
}

bool ok (int t1, int t2){
    if (t1 & t2) return 0;
    if (t1 & (t2 << 1)) return 0;
    if (t2 & (t1 << 1)) return 0;
    return 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int K;
    cin >> n >> K;
    tot = 0; dfs (0, 0);
    clr (d, 0); d[0][0][0] = 1;
    repf (i, 1, n) repf (j, 0, tot-1) repf (t, 0, K) if (d[i-1][j][t])
        repf (k, 0, tot-1) if (ok (sta[j], sta[k])) d[i][k][t+c[k]] += d[i-1][j][t];
    int64 ans = 0;
    repf (i, 0, tot-1) ans += d[n][i][K];
    cout << ans << endl;
    return 0;
}
