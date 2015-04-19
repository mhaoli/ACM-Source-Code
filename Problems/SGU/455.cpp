/*
 * Author:  Plumrain
 * Created Time:  2014/8/15 22:32:19
 * File Name: 455.cpp
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
const int maxn = (int)2e6;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 a, b, c;
int64 last, len, num[3000], tot;

void init (){
    int64 x = 1, pre = 1;
    num[tot = 0] = 1;
    rep (i, 1, maxn){
        x = (pre * a + (pre % b)) % c;
        pre = x;
        if ((i % 1000) == 0) num[++tot] = x;
    }
    last = x; len = -1; pre = 1;
    rep (i, 1, maxn-1){
        x = (pre * a + (pre % b)) % c;
        pre = x;
        if (x == last) len = maxn - i;
    }
}

int64 calc (int m){
    int p = m / 1000;
    int64 x = num[p], pre = x;
    rep (i, p*1000 + 1, m){
        x = (pre * a + (pre % b)) % c;
        pre = x;
    }
    return x;
}

int solve (){
    int l = len, r = maxn, ret = maxn;
    while (l <= r){
        int m = (l + r) >> 1;
        if (calc (m) == calc (m - len)) ret = m, r = m - 1;
        else l = m + 1;
    }
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    while (cin >> a >> b >> c){
        init ();
        if (len == -1) puts ("-1");
        else printf ("%d\n", solve ());
    }
    return 0;
}
