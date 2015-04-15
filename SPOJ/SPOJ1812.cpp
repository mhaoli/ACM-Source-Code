/*
 * Author:  Plumrain
 * Created Time:  2014/8/25 9:46:03
 * File Name: SPOJ-LCS2.cpp
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
const int maxs = 26;
const int maxn = 100005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct SAM{
    struct State{
        State *suf, *go[maxs], *nxt;
        int val, cnt, lcs, tlcs;
        State (){ 
            suf = 0; val = lcs = tlcs = 0;
            memset (go, 0, sizeof go);
        }
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
        np->lcs = np->val = p->val + 1;
        np->cnt = 1;
        while (p && !p->go[w])
            p->go[w] = np, p = p->suf;
        if (!p) np->suf = rt;
        else{
            State *q = p->go[w];
            if (p->val + 1 == q->val) np->suf = q;
            else{
                State *nq = bat++; 
                memcpy (nq->go, q->go, sizeof q->go);
                nq->lcs = nq->val = p->val + 1; 
                nq->suf = q->suf;
                q->suf = nq;
                np->suf = nq;
                while (p && p->go[w] == q)
                    p->go[w] = nq, p = p->suf;
            }
        }
        last = np;
    }

    void topo (int _L){
        L = _L; 
        memset (head, 0, sizeof head);
        for (State *i = memo; i != bat; ++ i)
            i->nxt = head[i->val], head[i->val] = i;
    }

    /*********************/
    int calc (char *str){
        int n = strlen (str), l = 0;
        State *p = rt;
        rep (i, 0, n-1){
            int id = str[i] - 'a';
            if (p->go[id]) ++ l, p = p->go[id];
            else{
                while (p && !p->go[id]) p = p->suf;
                if (p) l = p->val + 1, p = p->go[id];
                else l = 0, p = rt;
            }
            chmax (p->tlcs, l);
        }

        int res = 0;
        red (i, L, 0) for (State *p = head[i]; p; p = p->nxt){
            chmin (p->lcs, p->tlcs);
            if (p->suf){
                chmax (p->suf->tlcs, p->tlcs);
                chmax (res, p->lcs);
            }
            p->tlcs = 0;
        }
        return res;
    }
}gao;

char str[maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    scanf ("%s", str);
    int n = strlen (str);
    gao.init ();
    rep (i, 0, n-1) gao.extend (str[i] - 'a');
    gao.topo (n);

    int ans;
    while (scanf ("%s", str) != EOF){
        ans = gao.calc (str);
    }
    printf ("%d\n", ans);
    return 0;
}
