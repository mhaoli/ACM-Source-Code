/*
 * Author:  Plumrain
 * Created Time:  2014/8/26 16:37:08
 * File Name: F.cpp
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
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
const int maxn = 277777;
const int maxs = 26;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct nod{
    nod *ch[maxs+1], *f;
    nod *jump[maxs+1];
    vi v;
    nod *go (int c);
}*bat;

nod *nod::go (int c){
    if (ch[c] == 0) ch[c]=bat++, clr (ch[c]->ch, 0), ch[c]->v.clear ();
    return ch[c];
}

int ann[5100005];
int bnn[5200005];
bool vis_nod[55555];

struct AC{
    bool vis[maxn];
    nod an[maxn], *rt, *q[maxn];
    void newnod (nod *&o){
        o = bat++; clr (o->ch, 0); o->v.clear();
    }
    void init (){
        bat = an; newnod (rt); clr (vis, 0);
    }
    int idx (nod *x){
        return x - an;
    }
    void insert (char *s, int n, int v){
        nod *x = rt;
        repf (i, 0, n-1) x = x->go (s[i] - 'A');
        x->v.pb (v);
    }
    void build(){
        int ql = 0, qr = 0;
        q[qr++] = rt;
        while (ql != qr){
            nod *x = q[ql++];
            repf (c, 0, maxs-1){
                nod *v = x->ch[c];
                if (!v) continue;

                nod *last = x->f;
                while (last && last->ch[c] == 0) last = last->f;
                if (last) v->f = last->ch[c];
                else v->f = rt;
                q[qr++] = v;
            }
        }

        repf (i, 0, maxs-1) rt->jump[i] = rt->ch[i] ? rt->ch[i] : rt;
        repf (i, 1, qr-1){
            nod *x = q[i];
            repf (j, 0, maxs-1)
                if (x->ch[j]) x->jump[j] = x->ch[j];
                else x->jump[j] = x->f->jump[j];
        }
    }

    void calc (const vector<int> &t){
        rep (i, 0, sz (t)-1){
            vis_nod[t[i]] = 1;
        }
    }
    void find (int tot, int sta, int dif){
        nod *p = rt;
        for (int i = sta; i >= 0 && i < tot; i += dif){
            int tmp = ann[i];
            while (ann[i]){
                p = p->jump[bnn[i]];
                vis[idx (p)] = 1;
                -- ann[i];
            }
            ann[i] = tmp;
        }
    }
    void solve (){
        clr (vis_nod, 0);
        vis[idx (rt)] = 1;
        for (nod *p = an+1; p != bat; ++ p){
            if (vis[idx (p)]){
                calc (p->v);
                nod *t = p->f;
                while (!vis[idx(t)]) vis[idx (t)] = 1, calc (t->v), t = t->f;
            }
        }
    }
}gao;

char str[33333];
char s[5100005];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        gao.init ();
        int n; scanf ("%d", &n);
        rep (i, 0, n-1){
            scanf ("%s", str);
            int m = strlen (str);
            gao.insert (str, m, i);
        }

        gao.build ();

        scanf ("%s", s);
        int tot = 0, m = strlen (s);
        rep (i, 0, m-1){
            ann[tot] = 1;
            if (s[i] == '['){
                ann[tot] = 0;
                ++ i;
                while (s[i] >= '0' && s[i] <= '9') ann[tot] = ann[tot] * 10 + s[i] - '0', ++ i;
                bnn[tot++] = s[i] - 'A';
                i ++;
            }
            else bnn[tot++] = s[i] - 'A';
        }
        
        gao.find (tot, 0, 1);
        gao.find (tot, tot-1, -1);
        gao.solve ();

        int ans = 0;
        rep (i, 0, n-1) if (vis_nod[i]) ++ ans;
        printf ("%d\n", ans);
    }
    return 0;
}
