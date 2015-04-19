/*
 * Author:  Plumrain
 * Created Time:  2014/8/2 0:06:20
 * File Name: Btst.cpp
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
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi num;
vi use[35];
int an[1000];
int tot, d[105][1<<17], f[35][1<<17], pat[105][1<<17];
int prm[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

void dfs (int p, int x, int sta){
    if (x >= 59) return;
    dfs (p, x*prm[p], sta);
    bool u = 0;
    repf (i, p+1, tot-1) if (sta & (1<<i)){
        u = 1; dfs (i, x*prm[i], sta); break;
    }
    if (!u) num.pb (x);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    tot = 16;
    repf (i, 2, 30) repf (j, 0, (1<<tot)-1) f[i][j] = 1;
    repf (i, 2, 32) use[i].clear();
    repf (i, 1, (1<<tot)-1){
        num.clear(); 
        repf (j, 0, tot-1) if (i & (1<<j)) {dfs (j, prm[j], i); break;}
        sort (all (num)); num.erase (unique (all (num)), num.end());
        repf (j, 2, 30) for (int x : num){
            if (abs (x - j) < abs(1 - j)){ 
                use[j].pb (i);
                if (abs (f[j][i]-j) > abs (x-j)) f[j][i] = x;
            }
        }
    }

    repf (i, 1, 30) use[i].pb (0), f[i][0] = 1;
    repf (i, 1, 30) sort (all (use[i])), use[i].erase (unique (all (use[i])), use[i].end());

    int n; scanf ("%d", &n);
    repf (i, 0, n-1) scanf ("%d", &an[i]);
    clr (d, 127);
    for (int x : use[an[0]]) d[0][x] = abs (f[an[0]][x] - an[0]), pat[0][x] = 0;
    repf (i, 0, n-1) repf (j, 0, (1<<tot)-1) if (d[i][j] < inf){
        for (int x : use[an[i+1]]) if (!(x & j)){
            int tmp = d[i][j] + abs (f[an[i+1]][x] - an[i+1]);
            if (d[i+1][j|x] > tmp){
                pat[i+1][j|x] = j; d[i+1][j|x] = tmp;
            }
        }
    }

    int cnt = inf, idx = (1<<tot) - 1;
    repf (i, 0, (1<<tot)-1) if (cnt > d[n-1][i]) cnt = d[n-1][i], idx = i;

    vi ans;
    repd (i, n-1, 0){
        int pre = pat[i][idx];
        ans.pb (f[an[i]][pre^idx]);
        idx = pat[i][idx];
    }
    repd (i, sz(ans)-1, 0){
        printf ("%d", ans[i]);
        if (i) printf (" ");
        else printf ("\n");
    }
    return 0;
}
