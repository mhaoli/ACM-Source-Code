/*
 * Author:  Plumrain
 * Created Time:  2014/7/26 0:44:12
 * File Name: URAL-1743.cpp
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
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

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
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool vis[maxn];
pii an[maxn], ans[maxn];

bool cmp (pii a, pii b){
    return a.x == b.x ? a.y > b.y : a.x < b.x;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n; scanf ("%d", &n);
    repf (i, 0, n-1){
        scanf ("%d%d", &an[i].x, &an[i].y);
        if (an[i].x > an[i].y) swap (an[i].x, an[i].y);
    }
    sort (an, an+n, cmp);

    //repf (i, 0, n-1) tst (an[i].x), out (an[i].y);
   // 
    int cnt1 = 1;
    clr (vis, 0);
    ans[0] = an[0];
    repf (i, 1, n-1){
        if (an[i].x >= ans[cnt1-1].x && an[i].y <= ans[cnt1-1].y){
            vis[i] = 1; ans[cnt1++] = an[i];
        }
    }

    int cnt2 = n - 1;
    repf (i, 1, n-1) if (!vis[i]){
        if (cnt2 == n-1){
            ans[cnt2] = an[i]; vis[i] = 1;
            swap (ans[cnt2].x, ans[cnt2].y); -- cnt2;
        }
        else if (an[i].x >= ans[cnt2+1].y && an[i].y <= ans[cnt2+1].x){
            ans[cnt2] = an[i]; vis[i] = 1;
            swap (ans[cnt2].x, ans[cnt2].y); -- cnt2;
        }
    }

    if (cnt2 + 1 != cnt1) puts ("NO");
    else{
        bool u = 0;
        repf (i, 1, n-1) if (ans[i].x < ans[i-1].x || ans[i].y > ans[i-1].y) u = 1;
        if (u) puts ("NO");
        else{
            puts ("YES");
            repf (i, 0, n-1) printf ("%d %d\n", ans[i].x, ans[i].y);
        }
    }
    return 0;
}
