/*
 * Author:  Plumrain
 * Created Time:  2014-02-10 15:45
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, -1, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
//#define out(x) cout<<#x<<":"<<(x)<<endl
//#define tst(a) cout<<a<<" "
//#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 10;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int v[105], d[505][505];
pii nod[505];
vector<pii > son[505], pat[505];

void dfs (int x)
{
    v[x] = 1;
    int n = sz(pat[x]);
    if (!n){
        nod[x].first = nod[x].second = 0;
        return ;
    }

    int cnt = 0, cost = 0;
    for (int i = 0; i < n; ++ i){
        pii tmp = pat[x][i];  
        if (v[tmp.first]) continue;

        dfs (tmp.first);
        son[x].pb (pat[x][i]);
        cnt += nod[tmp.first].first + 1;
        cost += nod[tmp.first].second + tmp.second;
    }
    nod[x].first = cnt; nod[x].second = cost;
}

void dp (int x)
{
    int n = sz(son[x]);
    d[x][0] = 0;
    if (!n) return;

    for (int i = 0; i < n; ++ i){
        dp(son[x][i].first);

        int y = son[x][i].first, cost = son[x][i].second;
        for (int j = nod[x].first; j >= 0; -- j) if (d[x][j] != -1 && d[x][j] != inf){
            for (int k = 0; k <= nod[y].first; ++ k) if (d[y][k] != -1 && d[y][k] != inf){
                d[x][j+k] = min(d[x][j+k]==-1?inf:d[x][j+k], d[y][k] + d[x][j]);
            }

            d[x][j+nod[y].first+1] = min(d[x][j+nod[y].first+1]==-1?inf:d[x][j+nod[y].first+1], d[x][j] + nod[y].second + cost);
        }
    }

    d[x][nod[x].first] = min(d[x][nod[x].first] == -1 ? inf : d[x][nod[x].first], nod[x].second);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, q;
    while (scanf ("%d%d", &n, &q) != EOF){
        int t1, t2, t3, sum = 0;
        for (int i = 0; i < n; ++ i) pat[i].clear(), son[i].clear();

        for (int i = 0; i < n-1; ++ i){
            scanf ("%d%d%d", &t1, &t2, &t3);
            -- t1; -- t2; sum += t3;
            pat[t1].pb (make_pair(t2, t3));
            pat[t2].pb (make_pair(t1, t3));
        }

        clr (v); dfs (0);
        clrs (d, -1); dp(0);
        cout << sum - d[0][n-1-q] << endl;
    }
    return 0;
}
