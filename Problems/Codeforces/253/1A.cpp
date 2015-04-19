/*
 * Author:  Plumrain
 * Created Time:  2014/9/9 20:52:10
 * File Name: A.cpp
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
const int inf = ~0U >> 1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

char str[111][2];
map<char, int> has, has2;
bool vis[111], vis2[111];

bool check (const int &n){
    rep (i, 0, n-1) rep (j, i+1, n-1){
        bool u = 0, u1 = 0, u2 = 0;
        if (str[i][0] != str[j][0]){
            if (vis[has[str[i][0]]] || vis[has[str[j][0]]]) u = 1;
        } else u1 = 1;
        if (str[i][1] != str[j][1]){
            if (vis2[has2[str[i][1]]] || vis2[has2[str[j][1]]]) u = 1;
        } else u2 = 1;

        if (u1 && u2) continue;
        if (!u) return 0;
    }
    return 1;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, t1 = 0, t2 = 0;
    scanf ("%d", &n);
    rep (i, 0, n-1){
        scanf ("%s", str[i]);
        if (!has.count (str[i][0])) has[str[i][0]] = t1 ++;
        if (!has2.count (str[i][1])) has2[str[i][1]] = t2 ++;
    }

    int ans = t1 + t2;
    int N = 1 << (t1 + t2);
    rep (i, 0, N-1){
        clr (vis, 0); clr (vis2, 0);
        rep (j, 0, t1-1) if (i & (1<<j)) vis[j] = 1;
        rep (j, t1, t1+t2-1) if (i & (1<<j)) vis2[j-t1] = 1;

        if (check (n)) chmin (ans, __builtin_popcount (i));
    }
    printf ("%d\n", ans);
    return 0;
}
