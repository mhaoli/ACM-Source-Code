/*
 * Author:  Plumrain
 * Created Time:  2014/4/19 1:23:25
 * File Name: graph-HDU-1045.cpp
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

char s[10][10];
vector<int> an[100];
int match[100], v[100];
int ix[10][10], iy[10][10];

bool crosspath (int x){
    repf (i, 0, sz(an[x])-1){
        int p = an[x][i];
        if (!v[p]){
            v[p] = 1;
            if (match[p] == -1 || crosspath(match[p])){
                match[p] = x; return 1;
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
        if (crosspath (i)) ++ ret;
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF && n){
        repf (i, 0, n-1) scanf ("%s", s[i]);

        int tx = -1, ty = -1;
        repf (i, 0, n-1){
            int j = 0, u = 1;
            while (j < n){
                if (s[i][j] == '.') ix[i][j] = u ? ++tx : tx, u = 0;
                else u = 1;
                ++ j;
            }
        }
        repf (j, 0, n-1){
            int i = 0, u = 1;
            while (i < n){
                if (s[i][j] == '.') iy[i][j] = u ? ++ty : ty, u = 0;
                else u = 1;
                ++ i;
            }
        }

        repf (i, 0, tx) an[i].clear();
        repf (i, 0, n-1) repf (j, 0, n-1) if (s[i][j] == '.') an[ix[i][j]].pb (iy[i][j]);
        int ans = hungary (tx+1);
        cout << ans << endl;
    }
    return 0;
}
