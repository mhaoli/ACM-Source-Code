/*
 * Author:  Plumrain
 * Created Time:  2014/9/15 11:08:06
 * File Name: ZOJ3803.cpp
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

const int mod = int(1e9) + 7;
const int maxn = int(1e5) + 9;
int L;
char s1[maxn], s2[maxn];
int d[maxn][2][2];
bool more[maxn][2][2];
int pat[maxn][2][2];

int stk[maxn];
char ans_c[maxn], ans_g[maxn];

inline bool add (int &a, int b){
    a += b;
    if (a >= mod){
        a -= mod; return 1;
    }
    return 0;
}

inline bool ok (int t, char c){
    if (c == '?') return 1;
    if (t == c - '0') return 1;
    return 0;
}

bool gao (char *s){
    while (s[0]){
        if (s[0] == '1') return 0;
        ++ s;
    }
    return 1;
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    while (scanf ("%s", s1) != EOF){
        scanf ("%s", s2);
        L = strlen (s1);

        int res = (gao (s1) && gao (s2));
        
        //clr (d, 0); clr (more, 0);
        rep (i, 0, L){
            clr (d[i], 0); clr (more[i], 0);
        }
        d[0][0][0] = 1;
        rep (i, 0, L-1){
            bool u = 0;
            if (s2[i] == '?'){
                u = 1; s2[i] = '0';
            }

            rep (xt, 0, 1){
                rep (j, 0, 1) rep (k, 0, 1) if (d[i][j][k] || more[i][j][k]){
                    int tmp = j << 1 | k;
                    //tmp.x = j; tmp.y = k;
                    //if (!i) tst (j), out (k);
                    if (k){
                        if (s2[i] == '0' && ok (j, s1[i])){
                            bool fg = add (d[i+1][0][1], d[i][j][k]);
                            more[i+1][0][1] |= (fg | more[i][j][k]);
                            pat[i+1][0][1] = tmp;
                        }
                    } else{
                        int t = (s2[i] - '0') ^ 1;
                        if (ok (t^j, s1[i])){
                            bool fg = add (d[i+1][t][k], d[i][j][k]);
                            more[i+1][t][k] |= (fg | more[i][j][k]);
                            pat[i+1][t][k] = tmp;
                            //pat[i+1][t][k].pb (tmp);
                        }
                        if (!t && ok (j^1, s1[i])){
                            bool fg = add (d[i+1][1][1], d[i][j][k]);
                            more[i+1][1][1] |= (fg | more[i][j][k]);
                            pat[i+1][1][1] = tmp;
                            //pat[i+1][1][1].pb (tmp);
                        }
                    }
                }
                if (!u) break;
                s2[i] = '1';
            }
        }
        int ans = d[L][0][1]; add (ans, d[L][1][1]);
        bool mor = more[L][0][1] | more[L][1][1];
        if (!ans && !mor && !res) puts ("IMPOSSIBLE");
        else if (mor || ans > 1 || (ans && res)){
            printf ("AMBIGUOUS %d\n", (ans + res) % mod);
        } else if (res){
            rep (i, 0, L-1) ans_c[i] = ans_g[i] = '0';
            ans_c[L] = ans_g[L] = 0;
            puts ("UNIQUE");
            puts (ans_g); puts (ans_c);
        } else{
            int top = 0, sta = d[L][0][1] ? 1 : 3, tpos = -1;
            stk[top++] = sta >> 1;
            if ((sta>>1) == 1 && tpos == -1) tpos = top-1;
            red (i, L, 2){
                //sta = pat[i][sta>>1][sta&1][0];
                sta = pat[i][sta>>1][sta&1];
                stk[top++] = sta >> 1;
                if ((sta>>1) == 1 && tpos == -1) tpos = top-1;
            }
            //rep (i, 0, top-1) tst (stk[i]); cout << endl;
            stk[top] = 0;
            for (int i = top-1, j = 0; i >= 0; -- i, ++ j){
                ans_g[j] = (stk[i] ^ stk[i+1]) + '0';
                if (i < tpos) ans_c[j] = '0';
                else if (i == tpos) ans_c[j] = '1';
                else ans_c[j] = (stk[i] ^ 1) + '0';
            }
            ans_c[top] = ans_g[top] = 0;
            puts ("UNIQUE");
            puts (ans_g); puts (ans_c);
        }
    }
    return 0;
}
