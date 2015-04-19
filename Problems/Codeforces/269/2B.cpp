/*
 * Author:  Plumrain
 * Created Time:  2014/9/26 23:45:20
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

pii a[3333];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    while (scanf ("%d", &n) != EOF){
        rep (i, 0, n-1){
            scanf ("%d", &a[i].x);
            a[i].y = i + 1;
        }
        sort (a, a + n);
        int cnt = 0;
        rep (i, 1, n-1) if (a[i].x == a[i-1].x) ++ cnt;
        if (cnt < 2) puts ("NO");
        else{
            puts ("YES");
            rep (i, 0, n-1) printf ("%d%c", a[i].y, " \n"[i==n-1]);
            int t = -1;
            rep (i, 0, n-1)
                if (i == n-1 || a[i].x != a[i+1].x){
                    printf ("%d%c", a[i].y, " \n"[i==n-1]);
                } else{
                    if (t == -1){
                        printf ("%d %d%c", a[i+1].y, a[i].y, " \n"[i==n-2]);
                        t = i++;
                    } else printf ("%d%c", a[i].y, " \n"[i==n-1]);
                }

            rep (i, 0, n-1)
                if (i == n-1 || a[i].x != a[i+1].x){
                    printf ("%d%c", a[i].y, " \n"[i==n-1]);
                } else{
                    if (i > t){
                        printf ("%d %d%c", a[i+1].y, a[i].y, " \n"[i==n-2]);
                        t = inf;
                        ++ i;
                    } else printf ("%d%c", a[i].y, " \n"[i==n-1]);
                }
        }
    }
    return 0;
}
