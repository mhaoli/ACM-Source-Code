/*
 * Author:  Plumrain
 * Created Time:  2014/8/9 13:54:42
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

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

pii cor[4];
int vis[10], cnt[10], siz[50];

void calc (int x, int y){
    repf (i, 1, 20) repf (j, 1, 20){
        bool bre = 0;
        repf (k, 0, 3) if (vis[k] && i == cor[k].x && j == cor[k].y) bre = 1;
        if (y != -1 && i != cor[y].x && j != cor[y].y) bre = 1;
        repf (k, 0, 3) if (vis[k] && y != k && (i == cor[k].x || j == cor[k].y)) bre = 1;
        if (bre) continue;

        cor[x].x = i; cor[x].y = j; return;
    }
}

int in_line (pii a, pii b){
    if (a.x == b.x || a.y == b.y) return 1;
    return 0;
}

int ok (int s, int u){
    clr (vis, 0);
    repf (i, 0, 3) if (s & (1<<i)) vis[i] = 1;
    clr (cnt, 0);
    repf (i, 0, 3) if (vis[i]){
        repf (j, 0, 3) if (vis[j] && j != i && in_line (cor[i], cor[j])) ++ cnt[i];
        if (cnt[i] > 1) return 0;
    }

    int num = 0;
    repf (i, 0, 3) if (vis[i]) num += cnt[i];
    num /= 2;
    if (siz[s] == 3 && !num) return 0;
    if (siz[s] == 4 && num <= 1) return 0;

    if (!u) return 1;

    repf (i, 0, 3) if (!vis[i]){
        repf (j, 0, 3) if (vis[j] && !cnt[j]){
            calc (i, j);
            ++ cnt[j]; ++ cnt[i]; vis[i] = 1; 
            break;
        }

        if (!vis[i]) calc (i, -1), vis[i] = 1;
    }
    return 1;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int x, y;
    while (scanf ("%d%d", &cor[0].x, &cor[0].y) != EOF){
        repf (i, 1, 3) scanf ("%d%d", &cor[i].x, &cor[i].y);
        siz[0] = 0;
        repf (i, 1, 15) siz[i] = siz[i>>1] + (i & 1);

        int ans = 4, idx = 0;
        repf (i, 0, 15){
            if (!ok(i, 0)) continue;
            if (chmin (ans, 4 - siz[i])) idx = i;
        }

        ok (idx, 1);
        repf (i, 0, 3) printf ("%d %d\n", cor[i].x, cor[i].y);
    }
    return 0;
}
