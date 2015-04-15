/*
 * Author:  Plumrain
 * Created Time:  2014/8/9 23:43:29
 * File Name: URAL1806.cpp
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
const int maxn = 50005;
const int maxe = maxn * 100;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct edge{
    int v, d;
    edge *nxt;
}e[maxe], head0, *head[maxn], *null;

struct nod{
    int x, y;
    nod(){}
    nod(int _x, int _y) : x(_x), y(_y) {}
    bool operator<(const nod &a)const{
        return x > a.x;
    }
};

int val[15], stk[maxn], vis[maxn];
int pre[maxn], d[maxn], tot;
map<string, int> has;

void adde (int u, int v, int c){
    e[tot].v = v; e[tot].d = c; e[tot].nxt = head[u]; head[u] = &e[tot++];
    e[tot].v = u; e[tot].d = c; e[tot].nxt = head[v]; head[v] = &e[tot++];
}

void spfa(int s, int t){
    clr (d, 127); d[s] = 0; pre[s] = -1;
    priority_queue<nod> q; q.push (nod (0, s));

    clr (vis, 0);
    while (sz (q)){
        nod p = q.top(); q.pop();
        if (p.x != d[p.y]) continue;
        if (vis[p.y]) continue;
        if (p.y == t) break;
        vis[p.y] = 1;
        for (edge *v = head[p.y]; v != null; v = v->nxt){
            if (!vis[v->v] && d[v->v] > p.x + v->d){
                d[v->v] = p.x + v->d;
                pre[v->v] = p.y;
                q.push (nod (d[v->v], v->v));
            }
        }
    }

}

map<string, int> :: iterator it;

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    int n; scanf ("%d", &n);
    repf (i, 0, 9) scanf ("%d", val+i);

    has.clear();
    null = &head0;
    repf (i, 0, n-1) head[i] = null;

    char s[15];
    tot = 0;
    repf (i, 0, n-1){
        scanf ("%s", s);
        repf (j, 0, 9){
            int bak = s[j];
            repf (k, '0', '9') if (k != bak){
                s[j] = k;
                it = has.find (s);
                if (it != has.end()) adde (i, it->second, val[j]);
            }
            s[j] = bak;
        }

        repf (j, 0, 9) repf (k, j+1, 9) if (s[j] != s[k]){
            swap (s[j], s[k]);
            it = has.find (s);
            if (it != has.end()) adde (i, it->second, val[j]);
            swap (s[j], s[k]);
        }
        
        has[s] = i;
    }
    
    spfa (0, n-1);

    if (d[n-1] > inf) puts ("-1");
    else{
        printf ("%d\n", d[n-1]);

        int p = n-1;
        int top = 0;
        while (p != -1) stk[top++] = p, p = pre[p];
        printf ("%d\n", top);
        while (top){
            printf ("%d", stk[--top] + 1);
            if (top) printf (" ");
        }
        puts ("");
    }
    return 0;
}

