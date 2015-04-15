/*
 * Author:  Plumrain
 * Created Time:  2014/9/10 0:12:19
 * File Name: Vijos1243.cpp
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
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = 100000 + 9;
int tim[6][maxn];
int d[6][maxn];
deque<pair<int, int> > dq[10][10];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m, K, l;
    scanf ("%d%d%d%d", &m, &n, &K, &l);
    rep (i, 0, n-1){
        rep (j, 0, m-1){
            int t;
            scanf ("%d", &t);
            tim[i][j] = j ? tim[i][j-1] + t : t;
        }
    }

    clr (d, 127);
    rep (j, 0, m-1){
        rep (i, 0, n-1) rep (k, 0, n-1){
            while (sz (dq[i][k]) && dq[i][k].front().x + l < j)
                dq[i][k].pop_front ();
        }

        rep (i, 0, n-1){
            if (j < l) chmin (d[i][j], tim[i][j]);
            rep (k, 0, n-1) if (i != k){
                if (sz (dq[k][i])) chmin (d[i][j], dq[k][i].front().y + tim[i][j] + K);
            }
        }

        rep (i, 0, n-1) rep (k, 0, n-1){
            while (sz (dq[i][k]) && dq[i][k].back().y >= d[i][j] - tim[k][j])
                dq[i][k].pop_back ();
            dq[i][k].push_back (mp (j, d[i][j] - tim[k][j]));
        }

        //if (j == 1) out (dq[1].back().x), out (dq[1].back().y);
    }

    //rep (i, 0, n-1){
        //rep (j, 0, m-1) tst (d[i][j]);
        //cout << endl;
    //}
//
    int ans = inf;
    rep (i, 0, n-1) chmin (ans, d[i][m-1]);
    printf ("%d\n", ans);
    return 0;
}
