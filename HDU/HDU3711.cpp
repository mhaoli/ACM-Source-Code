/*
 * Author:  Plumrain
 * Created Time:  2014/8/28 12:38:51
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
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
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

const int maxn = (int)2e6;
int siz[maxn + 5];

int n;
int a[1111], b[1111];

int calc (int t1, int t2){
    return siz[t1^t2];
}

int solve (int x){
    int ans = a[0], cnt = calc (a[0], x);
    rep (i, 1, n-1){
        int tmp = calc (a[i], x);
        if (tmp < cnt || (cnt == tmp && ans > a[i]))
            ans = a[i], cnt = tmp;
    }
    return ans;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    siz[0] = 0;
    rep (i, 1, maxn) siz[i] = siz[i>>1] + (i & 1);

    repcase{
        int m; scanf ("%d%d", &n, &m);
        rep (i, 0, n-1) scanf ("%d", a + i);
        rep (i, 0, m-1){
            int t;
            scanf ("%d", &t);
            printf ("%d\n", solve (t));
        }
    }
    return 0;
}
