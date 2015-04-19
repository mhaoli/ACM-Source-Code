/*
 * Author:  OpenRainbow
 * Created Time:  2014/8/27 13:38:25
 * File Name: J.cpp
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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

const int maxn = 100;
const int maxs = 26;
struct nod{
    nod *ch[maxs+5], *f;
    nod *jump[maxs+5];
    int v;
    nod *go (int c);
}*bat;

nod *nod::go (int c){
    if (ch[c] == 0) ch[c]=bat++, clr (ch[c]->ch, 0), ch[c]->v = 0;
    return ch[c];
}

map<char, double> has;
double d[1005][22][2];

struct AC{
    nod memo[maxn], *rt, *q[maxn];
    void newnod (nod *&o){
        o = bat++; clr (o->ch, 0); o->v = 0;
    }
    void init (){
        bat = memo; newnod (rt);
    }
    int idx (nod *x){
        return x - memo;
    }
    void insert (char *s, int n, int v){
        nod *x = rt;
        repf (i, 0, n-1) x = x->go (s[i] - 'a');
        x->v += v;
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

        /*repf (i, 1, qr-1){
            nod *x = q[i];
            if (x->f) x->v += x->f->v;
        }*/
    }

    double DP (const vector<char> &vec, int n){
        int mx = bat - memo;
        clr (d, 0);
        d[0][0][0] = 1;
        rep (i, 0, n-1) rep (j, 0, mx-1) rep (k, 0, 1){
            rep (t, 0, sz (vec)-1){
                nod *p = memo[j].jump[vec[t] - 'a'];
                d[i+1][idx (p)][k|(p->v)] += d[i][j][k] * has[vec[t]];
            }
        }

        double ret = 0;
        rep (i, 0, mx-1) ret += d[n][i][1];
        return ret * 100;
    }
}gao;

char str[30];
vector<char> vec;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        if (!n && !m) break;
        gao.init ();
        has.clear ();
        vec.clear ();

        double p;
        rep (i, 0, n-1){
            scanf ("%s%lf", str, &p);
            has[str[0]] = p; vec.pb (str[0]);
        }
        scanf ("%s", str);
        int len = strlen (str);
        gao.insert (str, len, 1);
        gao.build ();

        printf ("%.2f", gao.DP (vec, m));
        char tc; tc = 37;
        printf ("%c\n", tc);
    }
    return 0;
}

