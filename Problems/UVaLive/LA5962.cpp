/*
 * Author:  Plumrain
 * Created Time:  2014/8/3 14:19:19
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
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

char s[500];

bool v[1010];      //visited
bool del[505];
int match[1010];   
vector<int> an[1010];   //graph

bool crosspath(int x){
    repf (i, 0, sz(an[x])-1){
        int p = an[x][i];
        if (!v[p] && !del[p]){
            v[p] = 1;
            if (match[p] == -1 || crosspath(match[p])){
                match[p] = x; return 1;
            }
        }
    }
    return 0;
}

int hungary (int n){
    int ret = 0;
    clr (match, -1);
    repf (i, 0, n-1) if (!del[i]){
        clr (v, 0);
        if (crosspath (i)) ++ ret;
    }
    return ret;
}

int f[505];
bool g[305][305];

int find (int x){
    return x == f[x] ? f[x] : f[x] = find (f[x]);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        int n, m; scanf ("%d%d", &n, &m);
        clr (g, 0);
        repf (i, 0, n+m-1) an[i].clear();

        repf (i, 0, n-1){
            scanf ("%s", s);
            repf (j, 0, m-1) if (s[j] == '1') g[i][j] = 1;
        }

        int ans = 0;
        repf (i, 0, n-1) repf (j, 0, m-1){
            clr (del, 0);
            int cnt = n + m;
            repf (k, 0, m-1) if (!g[i][k]) del[k+n] = 1, -- cnt;
            repf (k, 0, n-1) if (!g[k][j]) del[k] = 1, -- cnt;
            if (cnt == 1) continue;

            repf (i, 0, n-1) an[i].clear();
            repf (t, 0, n-1) repf (k, 0, m-1) if (!del[t] && !del[k+n] && !g[t][k]) an[t].pb (k+n);
            chmax (ans, cnt - hungary (n));
        }
        
        printf ("Case %d: %d\n", ++ cas, ans);
    }
    return 0;
}
