/*
 * Author:  Plumrain
 * Created Time:  2014-02-13 17:17
 * File Name: JJ.cpp
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int col[1005];
int d[1005][1005];
vi pat[1005], num;

int dfs (int x)
{
    col[x] = 1;
    int ret = 1;
    for (int i = 0; i < sz(pat[x]); ++ i) 
        if (!col[pat[x][i]]) ret += dfs (pat[x][i]);
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (cin >> n >> m){
        clr (col);
        int t1, t2;
        for (int i = 0; i < m; ++ i){
            scanf ("%d%d", &t1, &t2);
            -- t1; -- t2;
            pat[t1].pb (t2); pat[t2].pb (t1);
        }

        for (int i = 0; i < n; ++ i) if (!col[i]) num.pb (dfs (col[i]));
        clr (d);
        d[0][0] = 1; d[0][num[0]] = 1;
        for (int i = 1; i < sz(num); ++ i)
            for (int j = 0; j <= n; ++ j) if (d[i-1][j]){
                d[i][j] = 1;
                if (j + num[i] <= n) d[i][j+num[i]] = 1;
            }
        int t1 = n / 2, t2;
        if (2*t != n) t2 = 
    }
    return 0;
}
