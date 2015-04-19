/*
 * Author:  Plumrain
 * Created Time:  2014/8/28 0:26:58
 * File Name: SPOJ1258.cpp
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
const int maxn = 90005;

struct State{
    State *suf, *ch[maxs], *nxt;
    int mx, sum;
    int tot, go[30];
}*rt, *last;

State *head[maxn];
State memo[maxn<<1], *bat;

void extend (const int &w){
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

/*********************/

char str[maxn];
char ans[111111];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    bat = memo;
    rt = last = bat ++; 

    scanf ("%s", str);
    int L = strlen (str);
    rep (i, 0, L-1) extend (str[i] - 'a');

    memset (head, 0, sizeof head);
    for (State *p = memo; p != bat; ++ p)
        p->nxt = head[p->mx], head[p->mx] = p;

    red (xt, L, 0)
        for (State *p = head[xt]; p; p = p->nxt){
            p->sum = 1;
            rep (i, 0, maxs-1) if (p->ch[i]){
                p->go[p->tot++] = i;
                p->sum += p->ch[i]->sum;
            }
        }
    
    int q, i; scanf ("%d", &q);
    while (q --){
        int k; scanf ("%d", &k);
        int len = 0;
        State *x = rt;
        while (k > 0){
            rep (j, 0, x->tot-1){
                i = x->go[j];
                if (k > x->ch[i]->sum) k -= x->ch[i]->sum;
                else{
                    //printf ("%c", (char)(i + 'a'));
                    ans[len++] = i+'a';
                    x = x->ch[i];
                    -- k;
                    break;
                }
            }
        }
        ans[len] = 0;
        puts(ans);
    }

    return 0;
}
