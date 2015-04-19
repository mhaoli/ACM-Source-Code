/*
 * Author:  Plumrain
 * Created Time:  2014/8/18 15:59:28
 * File Name: D.cpp
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
const int inf = 2147483647 / 2;
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};
const int maxn = 555;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 w[maxn], d[maxn][maxn], g[maxn];

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        if (!n && !m) break;
        rep (i, 1, m) cin >> w[i];
        sort (w+1, w+m+1);

        clr (d, 0x3f); clr (g, 0x3f);
        d[0][0] = g[0] = 0;
        rep (i, 1, m) g[i] = g[i-1] + w[i];
        rep (i, 1, n){
            rep (j, 2, m){
                if (j > i) break;
                chmin (d[i][j], d[i-1][j-1] + w[j]);
                rep (k, 1, i) chmin (d[i][j], d[i-k][j-1] + k*w[j] + g[k]);
                chmin (g[i], d[i][j]);
            }
            d[i][1] = g[i] + w[1]*i;
        }
        cout << g[n] << endl;
    }
    return 0;
}
