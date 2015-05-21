/*
 * Author:  Plumrain
 * Created Time:  2014/8/30 15:49:39
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
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define two(x) (1<<(x))
#define twol(x) (1ll<<(x))
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
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
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

void R(int &ret){
    ret = 0;
    bool ok = 0;
	for( ; ;){
		int c = getchar();
		if (c >= '0' && c <= '9') ret = (ret << 3) + ret + ret + c - '0', ok = 1;
		else if (ok) return;
	}
}

const int maxn = 2002;

int n;
int a[maxn][maxn];
int64 s1[2][maxn], s2[2][maxn];
int64 ans[2];
pii pos[2];

int64 calc_1 (int x, int y){
    if (y >= x) return s1[0][y-x];
    else return s1[1][x-y];
}

int64 calc_2 (int x, int y){
    if (y >= (n - 1 - x)) return s2[1][y - (n - 1 - x)];
    else return s2[0][x + y];
}

void solve (int x, int y){
    int64 sum = calc_1 (x, y) + calc_2 (x, y) - a[x][y];
    if (sum > ans[(x+y)&1]){
        ans[(x+y)&1] = sum;
        pos[(x+y)&1] = mp (x, y);
    }
}

void OUT (pii &t){
    printf ("%d %d", t.x + 1, t.y + 1);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    R (n);
    rep (i, 0, n-1) rep (j, 0, n-1) R (a[i][j]);

    clr (s1, 0);
    rep (i, 0, n-1){
        int t1 = 0, t2 = i;
        while (t1 < n && t2 < n){
            s1[0][i] += a[t1++][t2++];
        }

        t1 = i; t2 = 0;
        while (t1 < n && t2 < n){
            s1[1][i] += a[t1++][t2++];
        }
    }

    clr (s2, 0);
    rep (i, 0, n-1){
        int t1 = i, t2 = 0;
        while (t1 >= 0 && t2 < n){
            s2[0][i] += a[t1--][t2++];
        }

        t1 = n-1; t2 = i;
        while (t1 >= 0 && t2 < n){
            s2[1][i] += a[t1--][t2++];
        }
    }

    clr (ans, -1);
    rep (i, 0, n-1) rep (j, 0, n-1) solve (i, j);
    printf ("%I64d\n", ans[0] + ans[1]);
    OUT (pos[0]); printf (" ");
    OUT (pos[1]); puts ("");
    return 0;
}
