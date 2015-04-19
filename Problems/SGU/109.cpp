/*
 * Author:  Plumrain
 * Created Time:  2014/6/15 18:41:36
 * File Name: 109.cpp
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int main()
{
    //    freopen("a.in","r",stdin);
    //    freopen("a.out","w",stdout);
    //    std::ios::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    if (n == 2){
        printf("3 4\n5 2 3\n"); return 0;
    }

    int tk = n & 1 ? n+1 : n, y = 2, x = 1, num = 0, cur = 0;
    vi ans[2]; ans[0].clear(); ans[1].clear();
    while (num < n*n-1){
        int ty = y, tx = x;
        while (ty >= 1 && tx <= n){
            ans[cur].pb ((tx-1)*n + ty); ++ num;
            ++ tx; -- ty;
        }

        if (y < n) ++ y;
        else ++ x;
        cur ^= 1;
    }

    printf ("%d", tk);
    repf (i, 0, sz(ans[0])-1) printf (" %d", ans[0][i]);
    puts ("");
    printf ("%d", tk+1);
    repf (i, 0, sz(ans[1])-1) printf (" %d", ans[1][i]);
    puts ("");
    return 0;
}
