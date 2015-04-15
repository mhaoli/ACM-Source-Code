/*
 * Author:  Plumrain
 * Created Time:  2014/6/29 16:40:04
 * File Name: 142.cpp
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
const int maxn = 500000;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int n;
bool vis[1<<19];
char s[maxn+5], ans_s[maxn+5];

bool solve (int l, int u){
    clr (vis, 0);
    int sta = 0, tmp = 1 << (l-1);
    repf (i, 0, l-1) if (s[i] == 'b') sta |= (1 << i);
    vis[sta] = 1;
    repf (i, l, n-1){
        sta >>= 1; if (s[i] == 'b') sta |= tmp;
        vis[sta] = 1;
    }
    int ans = -1;
    repf (i, 0, (1<<l)-1) if (!vis[i]){
        if (!u) return 1; ans = i;
    }
    if (ans == -1) return 0;
    repf (i, 0, l-1) printf ("%c", (ans&(1<<i)) ? 'b' : 'a');
    puts ("");
    return 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    scanf ("%d%s", &n, s);
    int l = 1, r = 0;
    while ((1<<(++r)) <= n);
    int ans = r;
    while (l <= r){
        int m = (l + r) >> 1;
        if (solve (m, 0)) ans = m, r = m - 1;
        else l = m + 1;
    }
    cout << ans << endl;
    solve (ans, 1);
    return 0;
}
