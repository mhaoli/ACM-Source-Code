/*
 * Author:  Plumrain
 * Created Time:  2014/8/29 21:52:24
 * File Name: E.cpp
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
#define two(x) (1<<(x))
#define twol(x) (1ll<<(x))
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
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
const int inf = ~0U >> 1;
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int64 mod = 1000000007;
const int maxs = 30;
const int maxn = int(3e5) + 5;

struct State{
    State *suf, *ch[maxs], *nxt;
    int mx, mi, cnt[3];
}*rt, *last;

State memo[maxn<<1], *bat;
State *head[maxn];

void init (){
    bat = memo;
    rt = last = bat ++; 
}
void extend (int w){
    //printf ("%c\n", w + 'a');
    State *p = last, *np = bat++; 
    np->mx = p->mx + 1;
    while (p && !p->ch[w])
        p->ch[w] = np, p = p->suf;
    if (!p) np->suf = rt;
    else{
        State *q = p->ch[w];
        if (p->mx + 1 == q->mx) np->suf = q;
        else{
            State *nq = bat++; 
            memcpy (nq->ch, q->ch, sizeof q->ch);
            nq->mx = p->mx + 1;
            nq->suf = q->suf;
            q->suf = nq;
            np->suf = nq;
            while (p && p->ch[w] == q)
                p->ch[w] = nq, p = p->suf;
        }
    }
    last = np;
}

void topo (const int &L){
    memset (head, 0, sizeof head);
    for (State *p = memo; p != bat; ++ p){
        p->nxt = head[p->mx], head[p->mx] = p;

        if (p->suf) p->mi = p->suf->mx + 1;
    }

    for (int i = L; i >= 0; -- i)
        for (State *p = head[i]; p; p = p->nxt)
            if (p->suf) for (int j = 0; j < 3; ++ j)
                p->suf->cnt[j] += p->cnt[j];
}

int ans[maxn];
char str[maxn];

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init ();
    int L = inf, Lsum = 3;
    rep (i, 0, 2){
        scanf ("%s", str);
        int len = strlen (str);
        chmin (L, len);
        Lsum += len;

        rep (j, 0, len-1){
            extend (str[j] - 'a');
            ++ last->cnt[i];
        }
        extend (26 + i);
    }

    topo (Lsum);

    clr (ans, 0);
    for (int i = L; i >= 0; -- i)
        for (State *p = head[i]; p; p = p->nxt){
            int64 tmp = 1;
            for (int j = 0; j < 3; ++ j)
                tmp = tmp * p->cnt[j] % mod;
            add (ans[p->mx], tmp);
            if (p->mi) add (ans[p->mi-1], mod - (tmp%mod));
        }
            
    red (i, L-1, 1) add (ans[i], ans[i+1]);
    rep (i, 1, L){
        if (i > 1) printf (" ");
        printf ("%d", ans[i]);
    }
    puts ("");
    return 0;
}
