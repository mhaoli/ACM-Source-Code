/*
 * Author:  Plumrain
 * Created Time:  2014/9/25 20:59:18
 * File Name: ZOJ3817.cpp
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

const int maxn = int(1e5) + 9;
const int seed = 257;
pii p[maxn][8];
int has[9][maxn], d[maxn][8], pp[maxn];
char str[8][maxn], tar[maxn];

void encode (char *s, int n, int *has){
    for (int i = 0; s[0]; ++ s, ++ i){
        has[i] = i ? has[i-1]*seed + s[0] - 'a' : s[0] - 'a';
    }
}

bool equal (int p1, int t, int p2, int len){
    int t1 = has[8][p1+len-1];
    if (p1) t1 -= has[8][p1-1] * pp[len];
    int t2 = has[t][p2+len-1];
    if (p2) t2 -= has[t][p2-1] * pp[len];
    if (t1 != t2) return 0;
    return 1;
}

int calc (int t1, int t2, const int&n){
    return n * (t1>>1) + ((t1 & 1) ? n - t2 : t2 + 1);
}

int stk[maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    pp[0] = 1;
    for (int i = 1; i < maxn; ++ i) pp[i] = pp[i-1] * seed;

    int T; scanf ("%d", &T);
    while (T--){
        int n, m; scanf ("%d%d", &n, &m); 
        rep (i, 0, 3){
            scanf ("%s", str[i<<1]);
            for (int j = 0, k = n-1; j < n; ++ j, -- k)
                str[i<<1|1][j] = str[i<<1][k];
        }

        rep (i, 0, 7) encode (str[i], n, has[i]);

        scanf ("%s", tar);
        encode (tar, n, has[8]);

        if (m <= n){
            bool u = 0;
            rep (i, 0, 7) if (!u){
                rep (j, 0, n-m)
                    if (equal (0, i, j, m)){
                        u = 1;
                        rep (t, j, j+m-1){
                            printf ("%d%c", calc (i, t, n), " \n"[t==j+m-1]);
                        }
                        break;
                    }
            }
            if (u) continue;
        }

        clr (d, -1);
        rep (i, 0, m-2) rep (j, 0, 7){
            if (d[i][j] == -1 && i < n){
                if (equal (0, j, n-i-1, i+1)){
                    d[i][j] = 0; p[i][j].x = j; p[i][j].y = n - i - 1;
                }
            }
            if (d[i][j] == -1) continue;

            int len = min (m-i-1, n);
            rep (k, 0, 7) if ((j ^ k) != 1){
                if (equal (i+1, k, 0, len)){
                    d[i+len][k] = i+1; p[i+len][k].x = j; p[i+len][k].y = 0;
                    break;
                }
            }
        }

        int top = 0;
        rep (t, 0, 7) if (!top && ~d[m-1][t])
            for (int pos = m-1, s = t, ts; ~pos; ts = s, s = p[pos][s].x, pos = d[pos][ts]-1){
                red (i, pos, d[pos][s]){
                    stk[top++] = calc (s, p[pos][s].y + i - d[pos][s], n);
                }
            }
        if (top) red (i, top-1, 0){
            printf ("%d%c", stk[i], " \n"[!i]);
        } else puts ("No solution!");
    }
    return 0;
}
