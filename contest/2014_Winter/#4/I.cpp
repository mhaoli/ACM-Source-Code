/*
 * Author:  Plumrain
 * Created Time:  2014-02-13 15:30
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

int n, m;
char s[20][20];

bool gao(int x, int y)
{
    bool u = 0;
    for (int i = 0; i < n; ++ i) if (s[i][y] == 'S') u = 1;
    if (!u) return 1;

    u = 0;
    for (int i = 0; i < m; ++ i) if (s[x][i] == 'S') u = 1;
    if (!u) return 1;
    return 0;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (cin >> n >> m){
        for (int i = 0; i < n; ++ i) scanf ("%s", s[i]);
        int cnt = 0;
        for (int i = 0; i < n; ++ i) for (int j = 0; j < m; ++ j) if (gao(i, j)) ++ cnt;
        printf ("%d\n", cnt);
    }
    return 0;
}
