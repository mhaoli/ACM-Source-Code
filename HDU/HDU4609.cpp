/*
 * Author:  Plumrain
 * Created Time:  2014/9/19 15:46:29
 * File Name: HDU4609.cpp
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
typedef pair<pii, int> piii;
typedef vector<piii > viii;
typedef complex<double> CD;

const double eps = 1e-10;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = int(5e5) + 9;

namespace FFT{
    const CD I(0, 1);
    const double PI = atan(1.0)*4;
    CD a[maxn], b[maxn], tmp[maxn];
    void DFT (CD *a, int n, const int &rev){
        if (n == 1) return;
        for (int i = 0; i < n; ++ i){
            tmp[i] = a[i];
        }
        for (int i = 0; i < n; ++ i){
            if (i & 1) a[(n>>1) + (i>>1)] = tmp[i];
            else a[i >> 1] = tmp[i];
        }
        CD *a0 = a, *a1 = a + (n >> 1);
        DFT (a0, n >> 1, rev);
        DFT (a1, n >> 1, rev);
        CD cur(1, 0);
        double alpha = 2 * PI / n * rev;
        CD step = exp (I * alpha);
        for (int k = 0; k < (n>>1); ++ k){
            tmp[k] = a0[k] + cur * a1[k];
            tmp[k + (n>>1)] = a0[k] - cur * a1[k];
            cur *= step;
        }
        for (int i = 0; i < n; ++ i){
            a[i] = tmp[i];
        }
    }
    void conv (double *aa, double *bb, double *c, const int &n){
        if (n <= 500){
            for (int i = 0; i < 2*n; ++ i) c[i] = 0;
            for (int i = 0; i < n; ++ i)
                for (int j = 0; j < n; ++ j)
                    c[i+j] += aa[i] * bb[j];
            return ;
        }
        
        int N = 1;
        for (; N < n; N <<= 1); N <<= 1;
        for (int i = 0; i < N; ++ i){
            if (i < n) a[i] = aa[i], b[i] = bb[i];
            else a[i] = b[i] = 0.0;
        }
        DFT (a, N, 1);
        DFT (b, N, 1);
        for (int i = 0; i < N; ++ i){
            a[i] *= b[i];
        }
        DFT (a, N, -1);
        for (int i = 0; i < N; ++ i){
            c[i] = a[i].real() / N;
        }
    }
}

ll s[maxn];
int aa[maxn];
double a[maxn], b[maxn];
double c[maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        clr (a, 0);
        int n; scanf ("%d", &n);
        rep (i, 0, n-1){
            scanf ("%d", aa + i);
            a[aa[i]] += 1;
        }
        sort (aa, aa + n);
        int m = aa[n-1];
        rep (i, 0, m) b[i] = a[i];
        FFT::conv (a, b, c, m + 1);

        rep (i, 0, n-1) c[aa[i] + aa[i]] -= 1;
        rep (i, 1, 2*m) s[i] = s[i-1] + (ll)(0.5 + c[i] / 2);
        ll ans = 0, tot = (ll)n * (n - 1) * (n - 2) / 6;
        rep (i, 2, n-1){
            ans += s[2*m] - s[aa[i]];
            ans -= (n - 1);
            ans -= (ll)(n - i - 1) * i;
            ans -= (ll)(n - i - 1) * (n - i - 2) / 2;
        }
        printf ("%.7f\n", (double)ans / tot);
    }
    return 0;
}
