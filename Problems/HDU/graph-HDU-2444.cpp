/*
 * Author:  Plumrain
 * Created Time:  2014/4/19 22:41:13
 * File Name: graph-HDU-2444.cpp
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
#define INF 999999999999999999
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
const int maxn = 205;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

bool ans;
vi son[maxn];
int match[maxn], v[maxn], col[maxn];

bool crosspath(int p){
    repf (i, 0, sz(son[p])-1){
        int x = son[p][i];
        if (!v[x]){
            v[x] = 1;
            if (match[x] == -1 || crosspath (match[x])){
                match[x] = p; return 1;
            }
        }
    }
    return 0;
}

int hungary (int n){
    int ret = 0;
    clr (match, -1);
    repf (i, 0, n-1){
        clr (v, 0); 
        if (crosspath(i)) ++ ret;
    }
    return ret;
}

void dfs (int x, int c){
    col[x] = c;
    repf (i, 0, sz(son[x])-1){
        int j = son[x][i];
        if (!col[j]) dfs (j, 3 - c);
        else if (col[j] == c) ans = 0;
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        repf (i, 0, n-1) son[i].clear();
        int s, e;
        repf (i, 0, m-1){
            scanf ("%d%d", &s, &e); -- s; -- e;
            son[s].pb (e); son[e].pb (s);
        }

        ans = 1;
        clr (col, 0);
        repf (i, 0, n-1) if (!col[i]) dfs (i, 1);

        if (!ans){
            cout << "No" << endl;
            continue;
        }

        int ans = hungary (n) / 2;
        cout << ans << endl;
    }
    return 0;
}
