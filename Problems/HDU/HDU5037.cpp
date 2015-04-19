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
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = int(2e5) + 9;
typedef pair<ll, int> pii;
int p[maxn], d[maxn], L;

void calc (ll t, ll p, int &k){
    k = (t - p - 1) / (L + 1);
}

#define debug(t) tst (t.x); out (t.y)

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        int n, tar;
        scanf ("%d%d%d", &n, &tar, &L);
        d[0] = p[0] = 0;
        rep (i, 1, n) scanf ("%d", p + i);
        sort (p + 1, p + 1 + n);
        p[++n] = tar;

        pii last = pii ((ll)(-L), 0), now = pii (0ll, 0);
        rep (i, 1, n){
            //out (p[i]);
            //debug (last); debug (now);
            if (p[i] <= now.x + L){
                if (last.x + L >= p[i]){
                    d[i] = last.y + 1;
                    now.x = p[i];
                    now.y = last.y + 1;
                } else{
                    last = now;
                    d[i] = now.y + 1;
                    now.x = p[i]; now.y = d[i];
                }
            } else{
                ll p1 = last.x + L + 1, p2 = now.x + L + 1;
                //tst (p1); out (p2);
                if (p1 == p2){
                    ++ p2;
                }
                if (p1 + L >= p[i]){
                    d[i] = d[i-1] + 2;
                    now.x = p[i]; now.y = d[i];
                    last.x = p1; last.y = d[i] - 1;
                } else{
                    int k1, k2;
                    calc (p[i], p1, k1); calc (p[i], p2, k2);
                    //tst (k1); out (k2);
                    if (k1 == k2){
                        if (k1 * (L + 1ll) + p1 + L >= p[i]){
                            now.x = k1 * (L + 1ll) + p1; now.y = 1 + k1 + k2 + d[i-1];
                            last.x = (k2 - 1ll) * (L + 1) + p2; last.y = k1 + k2 + d[i-1];
                        } else{
                            now.x = k2 * (L + 1ll) + p2; now.y = 2 + k1 + k2 + d[i-1];
                            last.x = k1 * (L + 1ll) + p1; last.y = 1 + k1 + k2 + d[i-1];
                        }
                    } else{
                        if (k2 * (L + 1ll) + p2 + L >= p[i]){
                            now.x = k2 * (L + 1ll) + p2; now.y = 1 + k1 + k2 + d[i-1];
                            last.x = (k1 -1ll) * (L + 1) + p1; last.y = k1 + k2 + d[i-1];
                        } else{
                            now.x = k1 * (L + 1ll) + p1; now.y = 2 + k1 + k2 + d[i-1];
                            last.x = k2 * (L + 1ll) + p2; last.y = 1 + k1 + k2 + d[i-1];
                        }
                    }
                    -- i;
                }
            }
            //cout << endl;
        }
        printf ("Case #%d: %d\n", ++ cas, d[n]);
    }
    return 0;
}
