/*
 * Author:  Yzcstc
 * Created Time:  2014/9/18 14:24:22
 * File Name: c.cpp
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
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

int M;
int d[1001][2];
int n, x, y, z;
#define Ft 4

int dfs (int s, int u){
    if (s <= 0) return u ? -(x / 2) : 0;
    if (~d[s][u]) return d[s][u];

    int &ans = d[s][u]; ans = inf;
    int tmp = u ? z : x + y, xt;

    rep (i, 0, s){
        //tst (i);
        xt = -inf;
        chmax (xt, tmp + dfs (s - i - 1, 1));
        chmax (xt, tmp + dfs (i, 0));
        chmin (ans, xt);
    }
    return ans;
}

int solve(){
    scanf("%d%d%d%d", &n, &x, &y, &z);
    clr (d, -1);
    return dfs (n - 1, 0);
}

int main(){
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int i = 1; i <= cas; ++i){
        printf("Case %d: %d\n", i, solve());
    }
    return 0;
}
