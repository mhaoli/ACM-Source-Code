/*
 * Author:  Plumrain
 * Created Time:  2014/4/18 13:02:29
 * File Name: graph-POJ-3041.cpp
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

bool v[1010];
int match[1010];
vector<int> an[1010];

bool crosspath(int x){
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
        if (crosspath (i)) ++ ret;
        clr (v, 0);
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        repf (i, 0, 2 * n) an[i].clear();
        int t1, t2;
        repf (i, 0, m-1){
            scanf ("%d%d", &t1, &t2);
            an[t1-1].pb (t2+n-1);
        }
        int ans = hungary (n);
        cout << ans << endl;
    }
    return 0;
}
