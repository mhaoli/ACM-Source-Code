/*
 * Author:  Plumrain
 * Created Time:  2014-02-10 13:05
 * File Name: K.cpp
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

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int an[10][10], ann[10][10];

void flip(int x, int y)
{
    an[x][y] ^= 1;
    if (y) an[x][y-1] ^= 1;
    if (y < 3) an[x][y+1] ^= 1;
    if (x) an[x-1][y] ^= 1;
    if (x < 3) an[x+1][y] ^= 1;
}

int gao(int sta, int temp)
{
    for (int i = 0; i < 4; ++ i) for (int j = 0; j < 4; ++ j) an[i][j] = ann[i][j];
    for (int i = 0; i < 4; ++ i) if (sta & (1<<i)) flip(0, i);

    int ret = 0;
    for (int i = 1; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j)
            if (an[i-1][j] != temp) flip(i, j), ++ ret;
    for (int i = 0; i < 4; ++ i) if (an[3][i] != temp) return inf;
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    string s;
    for (int i = 0; i < 4; ++ i){
        cin >> s;
        for (int j = 0; j < 4; ++ j) ann[i][j] = (s[j] == 'b' ? 1 : 0);
    }
    int ans = inf;
    for (int i = 0; i < (1<<4); ++ i)
        ans = min(ans, min(gao(i, 0), gao(i, 1)) + __builtin_popcount(i));
    if (ans >= inf) cout << "Impossible" << endl;
    else cout << ans << endl;
    return 0;
}
