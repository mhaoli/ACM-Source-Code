/*
 * Author:  Plumrain
 * Created Time:  2014/10/7 10:25:56
 * File Name: BZOJ2342.cpp
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

const int N = 500009;

int manacher (char *str, int *len, int n){  //len[i] means the max palindrome length centered i/2
    for (int i = 0; i < 2*n; ++ i) len[i] = 0;
    int mx = 0;
    for (int i = 0, j = 0, k; i < 2*n; i += k, j = max (j-k, 0)){
        while (i - j >= 0 && i + j + 1 < 2*n && str[(i-j) / 2] == str[(i+j+1) / 2]) ++ j;
        len[i] = j;
        chmax (mx, j);
        for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] != j - k; ++ k){
            len[i+k] = min (len[i - k], j - k);
        }
    }
    return mx;
}

int len[N<<1], f[N];
char s[N];

int find (int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n; scanf ("%d%s", &n, s);
    manacher (s, len, n);
    rep (i, 0, n-1) f[i] = i;
    int ans = 0;
    for (int i = 1, j; i < (n<<1); i += 2) if (len[i]){
        for (j = (i>>1) - (len[i]>>2); j + (len[j<<1|1]>>1) < (i >> 1); j = find(j)) f[j] = f[j+1];
        if (j < (i >> 1)) chmax (ans, ((i>>1) - j) << 2);
    }
    printf ("%d\n", ans);
    return 0;
}
