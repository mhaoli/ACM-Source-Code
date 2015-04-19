/*
 * Author:  Plumrain
 * Created Time:  2014/9/20 0:54:18
 * File Name: G.cpp
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
bool check[maxn+5];
int prm[maxn+5], prm_tot;

int primes(int n){
    clr (check, 0);
    int tot = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[tot++] = i;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
    return tot;
}

int fac_dep (int x, int *a, int *b){
    int top = 0;
    for (int i = 0; prm[i]*prm[i] <= x; ++ i) if (x % prm[i] == 0){
        a[top] = prm[i]; b[top] = 0;
        while (x % prm[i] == 0){
            ++ b[top]; x /= prm[i];
        }
        ++ top;
    }
    if (x > 1){
        a[top] = x; b[top] = 1; ++ top;
    }
    return top;
}

int A, B;
int an[2][111], bn[2][111];
int a[222], b[222], top;
ll M, AB;
ll ans_x, ans_y;

void calc (int *a1, int *b1, int *a2, int *b2){
    top = 0;
    while (a1[0] || a2[0]){
        if (!a1[0]){
            a[top] = a2[0];
            b[top++] = b2[0];
            ++ a2; ++ b2;
        } else if (!a2[0]){
            a[top] = a1[0];
            b[top++] = b1[0];
            ++ a1; ++ b1; 
        } else{
            if (a1[0] == a2[0]){
                a[top] = a1[0];
                b[top++] = b1[0] + b2[0];
                ++ a1; ++ b1;
                ++ a2; ++ b2;
            } else if (a1[0] < a2[0]){
                a[top] = a1[0];
                b[top++] = b1[0];
                ++ a1; ++ b1;
            } else{
                a[top] = a2[0];
                b[top++] = b2[0];
                ++ a2; ++ b2;
            }
        }
    }
}

void dfs (int p, ll v){
    if (p == top){
        ll x = B + v, y = A + AB/v;
        if (x < M) return;
        bool u = 0;
        if (ans_x == -1) u = 1;
        else if (ans_x + ans_y > x + y) u = 1;
        else if (ans_x + ans_y == x + y && ans_x > x) u = 1;
        if (u){
            ans_x = x; ans_y = y;
        }
        return;
    }

    dfs (p + 1, v);
    rep (i, 1, b[p]){
        v *= a[p];
        dfs (p + 1, v);
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    prm_tot = primes (maxn - 5);
    while (scanf ("%d%d%lld", &A, &B, &M) != EOF){
        AB = (ll)A * B;
        clr (an, 0); clr (bn, 0);
        fac_dep (A, an[0], bn[0]);
        fac_dep (B, an[1], bn[1]);
        calc (an[0], bn[0], an[1], bn[1]);

        //reptest (a, top);
        //reptest (b, top);
       // 
        ans_x = -1;
        dfs (0, 1ll);

        if (~ans_x) printf ("%lld %lld\n", ans_x, ans_y);
        else puts ("No answer");
    }
    return 0;
}
