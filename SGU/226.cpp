/*
 * Author:  Plumrain
 * Created Time:  2014/7/16 16:06:58
 * File Name: 226.cpp
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
typedef vector<pii >  vii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi pat[700];
int d[700];

struct cmp{
    bool operator()(pii a, pii b){
        return a.y > b.y;
    }
};

int dfs (int s, int t, int n){
    repf (i, 0, n-1) d[i] = inf;
    d[s] = 0;
    priority_queue<pii, vii, cmp> q;
    q.push (mp (s, 0));
    while (sz(q)){
        int u = q.top().x, dis = q.top().y; q.pop();
        if (u == t) return dis;
        if (d[u] < dis) continue;
        repf (i, 0, sz(pat[u])-1){
            int v = pat[u][i];
            if (d[v] > dis + 1){
                q.push (mp (v, dis+1));
                d[v] = dis + 1;
            }
        }
    }
    return inf;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    repf (i, 0, 3*n) pat[i].clear();
    int s, e, c;
    repf (i, 0, m-1){
        cin >> s >> e >> c; -- s; -- e; -- c;
        repf (j, 0, 2) if (j != c) pat[3*s+j].pb (3*e+c);
    }

    int ans = inf;
    repf (i, 0, 2) repf (j, 3*n-3, 3*n-1) chmin (ans, dfs (i, j, 3*n));
    cout << (ans < inf ? ans : -1) << endl;
    return 0;
}
