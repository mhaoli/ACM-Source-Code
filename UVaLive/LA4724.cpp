/*
 * Author:  Plumrain
 * Created Time:  2014/9/25 14:36:19
 * File Name: B.cpp
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
#include <complex>

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

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

vi pat[111];
int v[33], tv[33];
bool G[33][33], vis[33], has[33];
char str[33][33];

void modify (int u){
    tv[u] = 0;
    rep (i, 0, sz(pat[u])-1){
        int x = pat[u][i];
        if (vis[x]) continue;
        tv[x] -= v[u] / (sz(pat[u])+1);
        tv[x] -= v[x] / (sz(pat[x])+1);
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int T;
    scanf ("%d", &T);
    while (T--){
        int n, m; scanf ("%d%d", &n, &m);
        rep (i, 0, n-1) scanf ("%s", str[i]);

        clr (G, 0); clr (has, 0);
        rep (i, 0, n-1) rep (j, 0, m-1){
            has[str[i][j]-'A'] = 1;
            rep (k, 0, 3){
                int x = i + Dx[k], y = j + Dy[k];
                if (posin (x, y)){
                    int c1 = str[i][j] - 'A', c2 = str[x][y] - 'A';
                    if (c1 != c2){
                        G[c1][c2] = G[c2][c1] = 1;
                    }
                }
            }
        }

        int cnt = 0, sum = 0;
        rep (i, 0, 25){
            pat[i].clear ();
            rep (j, 0, 25) if (G[i][j]) pat[i].pb (j);
            cnt += (has[i]);
        }

        rep (i, 0, cnt-1) scanf ("%d", v + i);
        scanf ("%d", &sum);
        rep (i, 0, cnt-1){
            tv[i] = v[i];
            rep (j, 0, sz(pat[i])-1){
                tv[i] += (v[pat[i][j]] / (sz(pat[j]) + 1));
            }
        }

        clr (vis, 0);
        for (int u = 1; cnt && u; ){
            u = 0;
            rep (i, 0, 25) if (has[i] && !vis[i] && tv[i] < sum){
                u = 1;
                modify (i);
                -- cnt;
                vis[i] = 1;
            }
        }
        if (!cnt) puts ("Saruman");
        else puts ("Human");
    }
    return 0;
}
