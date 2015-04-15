/*
 * Author:  Plumrain
 * Created Time:  2014/6/1 14:23:11
 * File Name: graph-POJ-1041.cpp
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
const int maxn = 50;
const int maxm = 2005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool vis[maxm];
int num[maxn], top, stk[maxm];
vector<pii > pat[maxn];

bool cmp (pii a, pii b){
    return a.y < b.y;
}

void add (int t1, int t2, int t3){
    pat[t1].pb (mp (t2, t3));
    pat[t2].pb (mp (t1, t3));
    ++ num[t1]; ++ num[t2];
}

void calc (int x){
    repf (i, 0, sz(pat[x])-1) if (!vis[pat[x][i].y]){
        vis[pat[x][i].y] = 1;
        calc (pat[x][i].x);
        stk[ top++ ] = pat[x][i].y;
    }
}

void output(){
    repd (i, top-1, 0){
        if (i != top-1) printf (" ");
        printf ("%d", stk[i]);
    }
    printf ("\n");
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int t1, t2, t3;
    while (scanf ("%d%d", &t1, &t2) != EOF){
        if (!t1 && !t2) break;

        repf (i, 0, 49) pat[i].clear();
        clr (num, 0);

        int sta =  min (t1, t2) - 1, n = max (t1, t2) - 1;
        scanf ("%d", &t3); add (t1-1, t2-1, t3);
        while (scanf ("%d%d", &t1, &t2) != EOF){
            if (!t1 && !t2) break;
            scanf ("%d", &t3); add (t1-1, t2-1, t3);
            chmax (n, max (t1, t2)-1);
        }
        repf (i, 0, n) sort (all (pat[i]), cmp);

        bool ans_u = 1;
        clr (vis, 0); top = 0;
        repf (i, 0, n) if (num[i] & 1) ans_u = 0;
        if (!ans_u) printf ("Round trip does not exist.\n");
        else calc (sta), output ();
    }
    return 0;
}
