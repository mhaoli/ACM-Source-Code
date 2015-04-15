/*
 * Author:  Plumrain
 * Created Time:  2014/8/25 12:18:25
 * File Name: HDU4436.cpp
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
const int mod = 2012;
const int maxs = 11;
const int maxn = 222222;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

struct SAM{
    struct State{
        State *suf, *go[maxs], *nxt;
        int val, cnt, sum;
        State (){ 
            nxt = suf = 0; val = cnt = sum = 0;
            memset (go, 0, sizeof go);
        }
        void clear(){
            nxt = suf = 0; val = cnt = sum = 0;
            memset (go, 0, sizeof go);
        }
    }*rt, *last;

    int L;
    State memo[maxn<<1], *bat;
    State *head[maxn];

    void init (){
        L = 0;
        bat = memo;
        rt = last = bat ++; 
        rt->clear();
    }
    void extend (int w){
        ++ L;
        State *p = last, *np = bat++; 
        np->clear();
        np->val = p->val + 1;
        np->cnt = 0;
        while (p && !p->go[w])
            p->go[w] = np, p = p->suf;
        if (!p) np->suf = rt;
        else{
            State *q = p->go[w];
            if (p->val + 1 == q->val) np->suf = q;
            else{
                State *nq = bat++; 
                nq->clear();
                memcpy (nq->go, q->go, sizeof q->go);
                nq->val = p->val + 1;
                nq->suf = q->suf;
                q->suf = nq;
                np->suf = nq;
                while (p && p->go[w] == q)
                    p->go[w] = nq, p = p->suf;
            }
        }
        last = np;
    }

    /*********************/
    void calc (){
        memset (head, 0, sizeof head);
        for (State *p = rt; p != bat; ++ p)
            p->nxt = head[p->val], head[p->val] = p;

        int res = 0;
        rt->cnt = 1; rt->sum = 0;
        rep (i, 1, 9) if (rt->go[i]){
            State *p = rt->go[i];
            p->cnt = rt->cnt;
            p->sum = i;
        }
        rep (i, 1, L) for (State *p = head[i]; p; p = p->nxt){
            add (res, p->sum);
            rep (j, 0, 9) if (p->go[j]){
                State *q = p->go[j];
                add (q->sum, (10 * p->sum + p->cnt * j) % mod); 
                add (q->cnt, p->cnt);
            }
        }
        printf ("%d\n", res);
    }
}gao;

char str[maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    while (scanf ("%d", &n) != EOF){
        gao.init ();
        rep (i, 0, n-1){
            if (i) gao.extend (10);
            scanf ("%s", str);
            int m = strlen (str);
            rep (j, 0, m-1) gao.extend (str[j] - '0');
        }
        gao.calc ();
    }
    return 0;
}
