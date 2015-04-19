/*
 * Author:  Plumrain
 * Created Time:  2014/6/11 13:30:53
 * File Name: 103.cpp
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
const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct junc{
    int c, lef, dur, t[2];
}an[305];

int d[305], p[305];
bool done[306];
vector<pii > pat[305];

struct cmp{
    bool operator() (const int &a, const int &b) const{
        return d[a] > d[b];
    }
};

int next_time (int i, int t){
    int tmp = an[i].lef - an[i].t[0];
    if (an[i].c) tmp -= an[i].t[1];
    int xx = (t - tmp) % an[i].dur;
    if (xx < an[i].t[0]) return t + an[i].t[0] - xx;
    return t + an[i].dur - xx;
}

int ask_col (int i, int t){
    int tmp = an[i].lef - an[i].t[0];
    if (an[i].c) tmp -= an[i].t[1];
    if ((t - tmp) % an[i].dur < an[i].t[0]) return 0;
    return 1;
}

int calc (int u, int v){
    int t = d[u];
    int col1 = ask_col (u, t), col2 = ask_col (v, t);
    if (col1 == col2) return t;

    int tim1 = t, tim2 = t;
    int cnt = 0;
    while (cnt < 3){
        tim1 = next_time (u, tim1);  tim2 = next_time (v, tim2);
        if (tim1 != tim2) return min (tim1, tim2);
        ++ cnt;
    }
    return inf;
}

void dijskra (int sta, int tar, int n){
    clr (d, 127); d[sta] = 0;
    clr (done, 0);
    priority_queue<int, vi, cmp> q; q.push (sta);
    while (sz(q)){
        int u = q.top(); q.pop();
        if (done[u]) continue;
        done[u] = 1;
        if (u == tar) return ;
        repf (i, 0, sz(pat[u])-1){
            int v = pat[u][i].x, tim = calc (u, v) + pat[u][i].y;
            if (!done[v] && tim < d[v]){
                d[v] = tim; q.push (v); p[v] = u;
            }
        }
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m, sta, tar;
    scanf ("%d%d%d%d", &sta, &tar, &n, &m); -- tar, -- sta;

    char buf[10];
    repf (i, 0, n-1){
        scanf ("%s%d%d%d", buf, &an[i].lef, &an[i].t[0], &an[i].t[1]);
        an[i].c = buf[0] == 'B' ? 0 : 1;
        an[i].dur = an[i].t[0] + an[i].t[1];
    }

    repf (i, 0, n-1) pat[i].clear();

    int t1, t2, tim;
    repf (i, 0, m-1){
        scanf ("%d%d%d", &t1, &t2, &tim); -- t1; -- t2;
        pat[t1].pb (mp (t2, tim)); pat[t2].pb (mp (t1, tim));
    }

    dijskra (sta, tar, n);
    if (!done[tar]) puts ("0");
    else{
        printf ("%d\n", d[tar]);
        vi ans;
        while (tar != sta) ans.pb (tar), tar = p[tar];
        printf ("%d", sta + 1);
        repd (i, sz(ans)-1, 0) printf (" %d", ans[i] + 1);
        puts("");
    }
    return 0;
}
