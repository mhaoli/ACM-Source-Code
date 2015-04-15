/*
 * Author:  Plumrain
 * Created Time:  2014/8/12 12:27:40
 * File Name: 1007.cpp
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
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
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
//const int inf = 2139062143;
const int maxn = (1e5) + 5;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

map<int, int> hx, hy;
map<pii, int> has;
map<pii, int> :: iterator it1;
map<int, int> :: iterator it2;
int f[maxn], g[maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        int n, m, k; scanf ("%d%d%d", &n, &m, &k);
        hx.clear(); hy.clear(); has.clear();
        int ix = 0, iy = 0;
        pii tmp;
        repf (i, 0, k-1){
            int x, y, c;
            scanf ("%d%d%d", &x, &y, &c);
            it2 = hx.find (x);
            if (it2 == hx.end()) hx[x] = ix ++;
            it2 = hy.find (y);
            if (it2 == hy.end()) hy[y] = iy ++;
            tmp.x = hx[x]; tmp.y = hy[y]; has[tmp] = c;
            //chmax (xmx, tmp.x); chmax (ymx, tmp.y);
        }

        repf (i, 0, maxn-3) f[i] = i; 
        repf (i, 0, maxn-3)  g[i] = i;
        int q, op, a, b; scanf ("%d", &q);
        printf ("Case #%d:\n", ++ cas);
        while (q--){
            scanf ("%d%d%d", &op, &a, &b);
            int t1, t2;
            if (op == 1){
                it2 = hx.find (a);
                if (it2 == hx.end()) continue;
                t1 = it2->second;
                it2 = hx.find (b);
                t2 = it2->second;
                swap (f[t1], f[t2]);
            }
            else if (op == 2){
                it2 = hy.find (a);
                if (it2 == hx.end()) continue;
                t1 = it2->second;
                it2 = hy.find (b);
                t2 = it2->second;
                swap (g[t1], g[t2]);
            }
            else{
                it2 = hx.find (a);
                if (it2 == hx.end()) puts ("0");
                else{
                    tmp.x = f[it2->second];
                    it2 = hy.find (b);
                    if (it2 == hy.end()) puts ("0");
                    tmp.y = g[it2->second];
                    it1 = has.find (tmp);
                    if (it1 == has.end()) puts ("0");
                    else printf ("%d\n", it1->second);
                }
            }
        }
    }
    return 0;
}
