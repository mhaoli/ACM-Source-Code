/*
 * Author:  Plumrain
 * Created Time:  2014/9/13 13:28:15
 * File Name: 1005.cpp
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

const int maxn = 55;
const int maxe = 3333;
struct edge{
    int v;
    edge *nxt;
    void add (int _v, edge*t){
        nxt = t; v = _v;
    }
}e[maxe];

int L, n;
int cnt[maxn];
edge *head[maxn], *bat;

double f[2][maxn];
double xt;

void add (int u, int v){
    bat->add (v, head[u]); head[u] = bat++;
    bat->add (u, head[v]); head[v] = bat++;
}

void solve (int t){
    clr (f, 0);
    int now = 0, nxt = 1;
    rep (i, 0, n-1) f[0][i] = xt;
    rep (i, 0, L-1){
        clr (f[nxt], 0);
        rep (j, 0, n-1) if (j != t){
            double tmp = f[now][j] / cnt[j];
            for (edge *p = head[j]; p; p = p->nxt){
                f[nxt][p->v] += tmp;
            }
        }

        //rep (j, 0, n-1) tst (f[nxt][j]); cout << endl;
        swap (now, nxt);
    }
    double sum = 0;
    rep (i, 0, n-1) if (i != t) sum += f[now][i];
    printf ("%.7f\n", sum);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        int m;
        scanf ("%d%d%d", &n, &m, &L);
        xt = 1.0 / n;

        bat = e;
        clr (head, 0); clr (cnt, 0);
        rep (i, 0, m-1){
            int u, v; 
            scanf ("%d%d", &u, &v);
            add (--u, --v);
            ++ cnt[u]; ++ cnt[v];
        }

        rep (i, 0, n-1) solve (i);
    }
    return 0;
}
