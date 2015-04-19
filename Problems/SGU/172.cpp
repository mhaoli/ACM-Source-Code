/*
 * Author:  Plumrain
 * Created Time:  2014/7/4 15:14:29
 * File Name: 172.cpp
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
const int maxn = 205;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool ans_u;
int day[maxn];
vi pat[maxn];

void dfs (int x, int col){
    day[x] = col;
    repf (i, 0, sz(pat[x])-1){
        int v = pat[x][i];
        if (!day[v]) dfs (v, 3 - col);
        else if (day[v] == col) ans_u = 0;
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    scanf ("%d%d", &n, &m);
    repf (i, 0, n-1) pat[i].clear();
    int t1, t2;
    repf (i, 0, m-1){
        scanf ("%d%d", &t1, &t2); -- t1; -- t2;
        pat[t1].pb (t2); pat[t2].pb (t1);
    }

    ans_u = 1; clr (day, 0);
    repf (i, 0, n-1) if (!day[i]) dfs (i, 2);
    if (!ans_u) puts ("no");
    else{
        puts ("yes");
        vi ans;
        repf (i, 0, n-1) if (day[i] == 1) ans.pb (i);
        cout << sz(ans) << endl;
        repf (i, 0, sz(ans)-1){
            if (i) printf (" ");
            printf ("%d", ans[i] + 1);
        }
        puts ("");
    }
    return 0;
}
