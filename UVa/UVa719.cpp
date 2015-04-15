/*
 * Author:  Plumrain
 * Created Time:  2014/8/24 12:20:33
 * File Name: UVa719.cpp
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
const int maxn = 10005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

char str[maxn];

struct SAM{
    const static int maxs = 30;
    const static int maxn = 20005;

    struct State{
        State *suf, *go[maxs], *nxt;
        int val, cnt;
        State (){ 
            suf = 0; val = 0;
            memset (go, 0, sizeof go);
        }
        void clear(){
            suf = 0; val = 0;
            memset (go, 0, sizeof go);
        }
    }*rt, *last;

    State memo[maxn<<1], *bat;

    void init (){
        bat = memo;
        rt = last = bat ++; rt->clear();
    }
    void extend (int w){
        State *p = last, *np = bat++; np->clear();
        np->val = p->val + 1;
        np->cnt = 1;
        while (p && !p->go[w])
            p->go[w] = np, p = p->suf;
        if (!p) np->suf = rt;
        else{
            State *q = p->go[w];
            if (p->val + 1 == q->val) np->suf = q;
            else{
                State *nq = bat++; nq->clear();
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
    int dfs (State *p, int l){
        if (!l) return p->val;
        rep (i, 0, maxs-1) if (p->go[i]){
            int k = dfs (p->go[i], l-1);
            if (~k) return k;
        }
        return -1;
    }
}gao;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        scanf ("%s", str);
        gao.init ();

        int n = strlen (str);
        rep (i, 0, 2*n-1) gao.extend (str[i%n] - 'a');
        printf ("%d\n", gao.dfs (gao.rt, n) - n + 1);
    }
    return 0;
}
