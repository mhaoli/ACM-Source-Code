/*
 * Author:  Plumrain
 * Created Time:  2014/9/29 1:05:37
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

#define sqr(x) ((x) * (x))
const int N = 100009;

struct Pnt{
    int x, y;
};

long long dis (const Pnt &a, const Pnt &b){
    return sqr ((ll)(a.x - b.x)) + sqr ((ll)(a.y - b.y));
}

namespace gao{
    int b[N];
    Pnt *a;
    bool cmp_y (int x, int y){
        return a[x].y < a[y].y;
    }
    bool cmp_x (Pnt a, Pnt b){
        return a.x < b.x;
    }
    long long dfs (int l, int r){
        if (l == r) return (long long)(9e18);
        if (l == r - 1) return dis (a[l], a[l+1]);

        int mid = (l + r) >> 1;
        long long mi = dfs (l, mid), tmi = dfs (mid+1, r);
        if (tmi < mi) mi = tmi;
        int tl, tr;
        for (tl = mid; tl > l && a[mid].x - a[tl-1].x < mi; -- tl);
        for (tr = mid; tr < r && a[tr+1].x - a[mid].x < mi; ++ tr);

        int top = 0;
        for (int i = tl; i <= tr; ++ i) b[top++] = i;
        sort (b, b + top, cmp_y);
        for (int i = 0; i < top; ++ i)
            for (int j = i+1; j < min (i+8,top); ++ j){
                long long tmp = dis (a[b[i]], a[b[j]]);
                if (tmp < mi) mi = tmp;
            }
        return mi;
    }
    long long solve (int n, Pnt *t){
        a = t;
        sort (a, a + n, cmp_x);
        return dfs (0, n-1);
    }
}

Pnt a[N];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n; scanf ("%d", &n);
    rep (i, 0, n-1){
        scanf ("%d", &a[i].x);
        a[i].y = i ? a[i-1].y + a[i].x : a[i].x;
        a[i].x = i;
    }
    cout << gao::solve (n, a) << endl;
    return 0;
}
