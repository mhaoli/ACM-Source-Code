/*
 * Author:  Plumrain
 * Created Time:  2014/9/12 23:39:27
 * File Name: C.cpp
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

const int maxn = int(5e5) + 9;
int a[maxn];
int64 s[maxn];
int g[maxn], f[maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    while (scanf ("%d", &n) != EOF){
        rep (i, 0, n-1){
            scanf ("%d", a + i);
            s[i] = i ? s[i-1] + a[i] : a[i];
        }

        if (s[n-1] % 3 != 0){
            puts ("0"); continue;
        }
        int t1 = 0, t2 = 0;
        int64 s1 = s[n-1] / 3, s2 = 2 * s1;
        rep (i, 0, n-1){
            if (s[i] == s1) g[t1++] = i;
            if (s[i] == s2) f[t2++] = i;
        }

        while (t2 && f[t2-1] == n-1) -- t2;

        //reptest (g, t1);
        //reptest (f, t2);
//
        int64 ans = 0;
        for (int p1 = 0, p2 = 0; p1 < t1 && g[p1] < n-1; ++ p1){
            while (p2 < t2 && f[p2] <= g[p1]) ++ p2;
            ans += t2 - p2;
        }
        cout << ans << endl;
    }
    return 0;
}
