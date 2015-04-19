/*
 * Author:  Plumrain
 * Created Time:  2014/9/27 0:22:05
 * File Name: D.cpp
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

const int maxn = int(5e5) + 9;

void READ (int *a, int n){
    int t, last;
    scanf ("%d", &last);
    rep (i, 0, n-2){
        scanf ("%d", &t);
        a[i] = t - last;
        last = t;
    }
}

int a[maxn], b[maxn], f[maxn];

void fail (int *s, int *f, int n){
    f[0] = f[1] = 0;
    //int n = strlen(s);
    rep (i, 1, n-1){
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i+1] = s[j] == s[i] ? j+1 : 0;
    }
}

int match(int *s1, int *s2, int n, int m){ 
    //return the position of the first s2[] in s1[]
    //int n = strlen(s1), m = strlen(s2);
    fail (s2, f, m);
    int ret = 0, j = 0;
    rep (i, 0, n-1){
        while (j && s1[i] != s2[j]) j = f[j];
        if (s1[i] == s2[j]) ++ j;
        if (j == m){
            ++ ret;
            j = f[m];
        }
    }
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        READ (a, n);
        READ (b, m);
        if (m == 1) printf ("%d\n", n);
        else if (m > n) puts ("0");
        else printf ("%d\n", match (a, b, n-1, m-1));
    }
    return 0;
}
