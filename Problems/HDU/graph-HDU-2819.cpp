/*
 * Author:  Plumrain
 * Created Time:  2014/4/21 19:32:15
 * File Name: graph-HDU-2819.cpp
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

vi son[105];
int v[105], match[105];
vector<pii > ans;
int bod[105][105];

bool crosspath (int x){
    repf (i, 0, sz(son[x])-1){
        int p = son[x][i];
        if (!v[p]){
            v[p] = 1;
            if (match[p] == -1 || crosspath (match[p])){
                match[p] = x; return 1;
            }
        }
    }
    return 0;
}

int hungary (int n){
    clr (match, -1);
    int ret = 0;
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
    while (scanf ("%d", &n) != EOF){
        repf (i, 0, n-1) repf (j, 0, n-1) scanf ("%d", &bod[i][j]);
        repf (i, 0, n-1){
            son[i].clear();
            repf (j, 0, n-1) if (bod[i][j] == 1) son[i].pb (j);
        }

        int cnt = hungary(n);
        if (cnt != n){
            cout << "-1" << endl;
            continue;
        }

        ans.clear();
        repf (i, 0, n-1){
            while (match[i] != i){
                ans.pb (mp (match[i], i));
                swap (match[i], match[match[i]]);
            }
        }
        cout << sz(ans) << endl;
        repf (i, 0, sz(ans)-1) cout << "C " << ans[i].x+1 << " " << ans[i].y+1 << endl;
    }
    return 0;
}
