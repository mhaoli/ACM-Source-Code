/*
 * Author:  Plumrain
 * Created Time:  2014-02-09 13:33
 * File Name: I.cpp
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
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 100005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int n, k;
char s[2][N];
int an[2][N];

int dfs (int x, int y)
{
    if (y >= n || y < 0) return inf;
    if (s[x][y] == 'X') return inf;
    int &ret = an[x][y];
    if (ret != -1) return ret;
    
    ret = inf;
    int tmp = dfs (x^1, y - k);
    ret = min (ret, tmp + 1);

    tmp = dfs (x, y + 1);
    ret = min (ret, tmp + 1);

    tmp = dfs (x, y - 1);
    ret = min (ret, tmp + 1);
    if (ret > y) ret = inf;
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d%d", &n, &k) != EOF){
        clrs (an, -1); an[0][0] = 0;
        scanf ("%s%s", s[0], s[1]);
        bool ans = 0;
        for (int i = n-1; i >= max(n-k, 0); -- i){
            ans |= (dfs (0,i) <= i) | (dfs (1,i) <= i);
            if (ans) break;
        }
        if (ans) printf ("YES\n");
        else printf ("NO\n");
    }
    return 0;
}
