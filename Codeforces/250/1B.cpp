/*
 * Author:  Plumrain
 * Created Time:  2014/9/16 18:31:34
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
typedef pair<int, pii > piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = int(1e5) + 9;
int c[maxn], f[maxn], num[maxn];
piii e[maxn];

int find (int x){
    return x == f[x] ? f[x] : f[x] = find (f[x]);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        rep (i, 0, n-1) scanf ("%d", c + i);
        rep (i, 0, m-1){
            int t1, t2;
            scanf ("%d%d", &t1, &t2); -- t1; -- t2;
            e[i].x = min (c[t1], c[t2]); 
            e[i].y.x = t1; e[i].y.y = t2;
        }
        sort (e, e + m);

        int64 sum = 0;
        rep (i, 0, n-1) f[i] = i, num[i] = 1;
        red (i, m-1, 0){
            int t1 = find (e[i].y.x), t2 = find (e[i].y.y);
            if (t1 != t2){
                sum += 2LL * num[t1] * num[t2] * e[i].x;
                f[t1] = t2;
                num[t2] += num[t1];
            }
        }
        printf ("%.6f\n", sum / (n * (n - 1.0)));
    }
    return 0;
}
