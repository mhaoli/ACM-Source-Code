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

const int64 mod = 1000000007;
const int maxn = int(1e5) + 9;
char str[maxn], ss[maxn];
vs qn;
vi an;

int phiB;
int d[2][11][11], len[2][11][11];
int mor[2][11][11];

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

bool add (int &a, int b, int mod){
    a += b; if (a >= mod){
        a -= mod;
        return 1;
    }
    return 0;
}

int64 pow_mod (int64 p, int64 n){
    int64 ret = 1;
    while (n){
        if (n & 1) ret = ret * p % mod;
        n >>= 1;
        p = p * p % mod;
    }
    return ret;
}

void equal (int p, int t){
    rep (i, 0, 9){
        d[p][t][i] = d[p^1][t][i];
        len[p][t][i] = len[p^1][t][i];
    }
}

int euler_phi(int n)
{
    int m = (int)sqrt(n + 0.5);
    int ans = n;
    for (int i = 2; i <= m; ++ i)
        if (!(n % i)){
            ans -= ans/i;
            while (!(n % i)) n /= i;
        }
    if (n > 1) ans -= ans/n;
    return ans;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    phiB = euler_phi (mod);
    scanf ("%s", str);
    int L = strlen (str), q;
    reverse (str, str + L);
    scanf ("%d", &q);

    string buf;
    scanf ("\n");
    while (q--){
        gets (ss);
        //out (ss);
        buf.clear ();
        int tl = strlen (ss);
        red (i, tl-1, 3) buf.pb (ss[i]);
        //out (buf);
        qn.pb (buf); an.pb (ss[0] - '0');
    }

    rep (i, 0, 9){
        rep (j, 0, 9){
            d[0][i][j] = (i == j);
            len[0][i][j] = (i == j);
        }
    }

    int now = 0, nxt = 1;
    red (i, sz (qn)-1, 0){
        //out (an[i]);
        //out (qn[i]);
        clr (d[nxt], 0); 
        clr (len[nxt], 0);
        clr (mor[nxt], 0);

        rep (j, 0, 9){
            if (j != an[i]){
                equal (nxt, j);
            } else{
                int64 tl = 0, cof = 1;
                rep (k, 0, sz (qn[i])-1){
                    int add_len = 0;
                    bool more = 0;
                    rep (t, 0, 9){
                        add (d[nxt][j][t], cof * d[now][qn[i][k]-'0'][t] % mod);
                        mor[nxt][j][t] = (add (len[nxt][j][t], len[now][qn[i][k]-'0'][t], phiB) | mor[now][qn[i][k]-'0'][t]);
                        more |= (add (add_len, len[now][qn[i][k]-'0'][t], phiB) | mor[now][qn[i][k]-'0'][t]);
                    }
                    //tl = (tl + add_len) % mod;
                    if (more) cof = cof * pow_mod (10, add_len + phiB) % mod;
                    else cof = cof * pow_mod (10, add_len) % mod;
                }
            }
        }

        swap (now, nxt);

        //rep (i, 0, 9){
            //rep (j, 0, 9) tst (d[now][i][j]);
            //cout << endl;
        //}
        //cout << endl;
        //rep (i, 0, 9){
            //rep (j, 0, 9) tst (len[now][i][j]);
            //cout << endl;
        //}
        //cout << endl;
    }

    int ans = 0;
    int64 tl = 0, cof = 1;
    rep (i, 0, L-1){
        int add_len = 0;
        bool more = 0;
        rep (t, 0, 9){
            add (ans, (cof * t % mod) * d[now][str[i]-'0'][t] % mod);
            more |= add (add_len, len[now][str[i]-'0'][t], phiB) | mor[now][str[i]-'0'][t];
        }
        if (more) cof = cof * pow_mod (10, add_len + phiB) % mod;
        else cof = cof * pow_mod (10, add_len) % mod;
    }
    printf ("%d\n", ans);
    return 0;
}
