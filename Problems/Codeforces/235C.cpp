/*
 * Author:  Plumrain
 * Created Time:  2014/8/29 0:07:08
 * File Name: 235C.cpp
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
const int inf = 2147483647 / 2;
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/
const int maxs = 26;
const int maxn = (int)1e6 + 5;

struct State{
    State *suf, *ch[maxs], *nxt;
    int mx, mi, cnt, mark;
}*rt, *last;

int L;
State memo[maxn<<1], *bat;
State *head[maxn];

void init (){
    bat = memo;
    rt = last = bat ++; 
}
void extend (int w){
    State *p = last, *np = bat++; 
    np->mx = p->mx + 1;
    np->cnt = 1;
    while (p && !p->ch[w])
        p->ch[w] = np, p = p->suf;
    if (!p) np->suf = rt;
    else{
        State *q = p->ch[w];
        if (p->mx + 1 == q->mx) np->suf = q;
        else{
            State *nq = bat++; 
            //nq->clear();
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

void topo (const int &_L){
    L = _L;
    memset (head, 0, sizeof head);
    for (State *p = memo; p != bat; ++ p){
        p->nxt = head[p->mx], head[p->mx] = p;

        if (p->suf) p->mi = p->suf->mx + 1;
        else p->mi = 1;
    }
    rt->mi = 0;

    for (int i = L; i >= 0; -- i)
        for (State *p = head[i]; p; p = p->nxt)
            if (p->suf) p->suf->cnt += p->cnt;
}

/*********************/

void calc (char *str, const int &len, const int &mark){
    int64 res = 0;
    State *p = rt;
    int lcs = 0;
    rep (i, 0, 2*len - 2){
        int id = i >= len ? str[i-len] - 'a' : str[i] - 'a';
        if (p->ch[id]) ++ lcs, p = p->ch[id];
        else{
            while (p && !p->ch[id]) p = p->suf;
            if (p) lcs = p->mx + 1, p = p->ch[id];
            else lcs = 0, p = rt;
        }

        if (i < len - 1) continue;
        if (lcs < len) continue;
        while (p && p->mi > len) p = p->suf, lcs = p->mx;
        if (p->mark != mark) res += p->cnt, p->mark = mark;
        else break;
    }
    printf ("%I64d\n", res);
}

char str[maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init ();
    scanf ("%s", str);
    int L = strlen (str);
    rep (i, 0, L-1) extend (str[i] - 'a');
    topo (L);

    repcase{
        scanf ("%s", str);
        int len = strlen (str);
        calc (str, len, ++ cas);
    }
    return 0;
}
