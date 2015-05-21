/*
 * Author:  Plumrain
 * Created Time:  2014/8/16 1:03:10
 * File Name: E.cpp
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

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define two(x) (1<<(x))
#define twol(x) (1ll<<(x))
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
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
const int inf = 2147483647 / 2;
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};
const int maxn = (int)3e5 + 5;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct pat{
    int u, v, c;
    pat(){ }
    pat(int _u, int _v, int _c) : u(_u), v(_v), c(_c){ }
    bool operator<(const pat &a)const{
        return c < a.c;
    }
};

pat an[maxn];
int stk[maxn];
int tmp[maxn], d[maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m;
    while (cin >> n >> m){
        int u, v, c;
        rep (i, 0, m-1){
            scanf ("%d%d%d", &u, &v, &c); -- u; -- v;
            an[i] = pat (u, v, c);
        }

        int top = 0;
        clr (d, 0); clr (tmp, 0);
        sort (an, an+m); an[m] = pat (0, 0, -1);
        rep (i, 0, m){
            if (i && an[i].c != an[i-1].c){
                while (top--) chmax (d[stk[top]], tmp[stk[top]]), tmp[stk[top]] = 0;
                top = 0;
            }
            u = an[i].u, v = an[i].v;
            if (d[v] < d[u] + 1) if (chmax (tmp[stk[top] = v], d[u] + 1)) ++ top;
        }

        int ans = 0;
        rep (i, 0, n-1) chmax (ans, d[i]);
        cout << ans << endl;
    }
    return 0;
}
