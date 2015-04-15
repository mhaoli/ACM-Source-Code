/*
 * Author:  Plumrain
 * Created Time:  2014-02-13 15:40
 * File Name: J.cpp
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

int cnt[1005];
bool v[1005][1005];
vector<pii > ans, pat;

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m){
        int t1, t2;
        clr (v);
        for (int i = 0; i < m; ++ i){
            scanf ("%d%d", &t1, &t2);
            pat.pb (make_pair(t1, t2));
            v[t1][t2] = 1; v[t2][t1] = 1;
        }

        clr (cnt);
        for (int i = 0; i < m; ++ i){
            int x = pat[i].first, y = pat[i].second;
            for (int j = 0; j < n; ++ j) if (!v[j][x] && !v[j][y]){
                ans.pb (make_pair(min(x, j), max(x, j)));
                ans.pb (make_pair(min(y, j), max(y, j)));
            }
        }
    }
    return 0;
}
