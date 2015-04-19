/*
 * Author:  Plumrain
 * Created Time:  2014-02-12 13:46
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
const int N = 10000;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int an[N];
int d[N][2];
bool v[N];
vector<int> son[N];

void dp(int x)
{
    int n = sz(son[x]);
    d[x][0] = 0; d[x][1] = an[x];

    if (!n) return;

    for (int i = 0; i < sz(son[x]); ++ i){
        int y = son[x][i];
        dp(y);
        
        d[x][0] = max(d[x][0], d[x][0] + max(d[y][1], d[y][0]));
        d[x][1] = max(d[x][1], d[x][1] + d[y][0]);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i) scanf ("%d", &an[i]);
    int t1, t2;
    clr (v);
    while (scanf ("%d%d", &t1, &t2) != EOF && t1){
        -- t1; -- t2;
        son[t2].pb (t1);
        v[t1] = 1;
    }

    clr (d);
    int ans = -inf;
    for (int i = 0; i < n; ++ i) if (!v[i]) dp(i), ans = max(ans, max(d[i][0], d[i][1]));
    printf ("%d\n", ans);
    return 0;
}
