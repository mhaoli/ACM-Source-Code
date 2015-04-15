/*
 * Author:  Plumrain
 * Created Time:  2014/8/12 0:26:09
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
const int maxn = 1e5 + 5;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int has[maxn], cnt[maxn];
vi num[maxn], an[maxn], bn;

int del (int &p){
    //out (p); out (bn[p]); out (cnt[bn[p]]);
    while (p >= 0 && !cnt[bn[p]]) -- p;
    if (p < 0) return 0;
    -- cnt[bn[p]];
    return bn[p];
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, idx = 0, sum = 0;
    scanf ("%d", &n);

    bn.clear ();
    repf (i, 0, n-1) an[i].clear ();
    clr (cnt, 0); 
    clr (has, -1);
    repf (i, 0, n-1){
        int a, b; scanf ("%d%d", &a, &b);
        if (a == 0) continue;
        if (has[a] == -1) has[a] = idx++;
        an[ has[a] ].pb (b);
        sum += b; ++ cnt[b]; bn.pb (b);
    }

    sort (all (bn));
    repf (i, 0, idx-1) sort (all (an[i]));
    repf (i, 0, n) num[i].clear();
    repf (i, 0, idx-1) num[ sz(an[i]) ].pb (i);

    vi q;
    int ans = sum, p = sz(bn) - 1, tcnt = n - sz(bn);
    if (sz (num[n])) -- cnt[ an[ num[n][0] ][0] ], q.pb (num[n][0]);
    repd (ti, sz(bn) - 1, 0){
        int i = tcnt + ti;
        //out (i);
        if (i <= 0) break;
        for (auto j : num[i]) q.pb (j);
        for (auto j : q){
            //out (j); out (sz (an[j]) - i);
            int t = an[j][sz(an[j])-i];
            //out (t);
            if (t > bn[p] || (t == bn[p] && !cnt[bn[p]])) sum += t - del (p);
            else -- cnt[t];
        }

        sum -= del (p);
        //tst (p); tst (bn[p]); tst (cnt[bn[p]]); out (sum);
        chmin (ans, sum);
        if (p < 0) break;
    }
    cout << ans << endl;
    return 0;
}
