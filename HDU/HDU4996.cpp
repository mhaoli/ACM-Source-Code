/*
 * Author:  Plumrain
 * Created Time:  2014/9/13 10:17:04
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

#define two(i) (1<<(i))
int dig[30];
int64 d[1<<20], pre[1<<20], res[22][22];

void init (){
    res[1][1] = d[1] = 1;
    rep (i, 1, 17){
        rep (j, 0, two(i)-1) pre[j] = d[j];
        rep (j, 0, two(i+1)-1) d[j] = 0;
        rep (j, 0, two(i)-1) if (pre[j]) rep (k, 0, i){
            int tot = 0;
            rep (t, 0, i-1) if (j & two(t)) dig[tot++] = t;
            rep (t, 0, tot-1) if (dig[t] >= k) ++dig[t];
            bool u = 0;
            rep (t, 0, tot-1) if (dig[t] > k){
                u = 1; dig[t] = k; break;
            }
            if (!u) dig[tot++] = k;
            int ts = 0;
            rep (t, 0, tot-1) ts |= two(dig[t]);
            d[ts] += pre[j];
        }
        rep (j, 0, two(i+1)-1) res[i+1][__builtin_popcount(j)] += d[j];
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init ();
    repcase{
        int n, k;
        scanf ("%d%d", &n, &k);
        printf ("%I64d\n", res[n][k]);
    }
    return 0;
}
