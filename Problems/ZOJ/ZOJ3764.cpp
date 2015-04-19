/*
 * Author:  Plumrain
 * Created Time:  2014/9/16 21:25:47
 * File Name: ZOJ3764.cpp
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

#define two(i) (1 << (i))

struct edge{
    int u, v, w;
    edge(){ }
    edge(int _u, int _v, int _w): u(_u), v(_v), w(_w){};
    bool operator<(const edge &t)const{
        return w > t.w;
    }
}e[1111];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m, k;
    while (scanf ("%d%d%d", &n, &m, &k) != EOF){
        if (n == 1){
            puts ("0"); continue;
        }

        rep (i, 0, m-1){
            int u, v, w;
            scanf ("%d%d%d", &u, &v, &w);
            e[i] = edge (--u, --v, w);
        }
        sort (e, e + m);
        int64 sum = (int64)9e18;
        rep (ss, 0, two(n-2)-1){
            int s = ss << 1 | 1;
            int64 res = 0;
            for (int i = 0, j = k; i < m; ++ i){
                if (s & two(e[i].v)) swap (e[i].u, e[i].v);
                if ((s & two(e[i].u)) && !(s & two(e[i].v))){
                    if (j) -- j;
                    else res += e[i].w;
                }
            }
            chmin (sum, res);
        }
        printf ("%lld\n", sum);
    }
    return 0;
}
