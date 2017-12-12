// new template
// problem: CF 893F, http://codeforces.com/contest/893/problem/F
//Create Time: 2017-12-12 10:50:04
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
#include <functional>
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
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define TST(x) std::cout<<(x)<<" "
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define DEBUG
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
const int Max_N=(int)1e5+9;
namespace SegmentTree{
    struct Node{
        Node *ls, *rs;
        int l, r, v, version;
        Node* init(){
            ls = rs = NULL;
            l = r = 0;
            version = -1;
            v = INT_MAX;
            return this;
        }
        Node* init(Node*x){
            ls=x->ls; rs=x->rs;
            l=x->l; r=x->r;
            v=x->v; 
            version=x->version;
            return this;
        }
        Node* build(int ql, int qr);
        Node* insert(int pos, int _v, int vs);
        int query(int ql, int qr);
    }memo[Max_N*17+Max_N*4],*bat,*heads[Max_N];
    Node* newnode(){
        bat->init();
        return bat++;
    }
    Node* Node::build(int ql,int qr){
        l = ql; r = qr;
        if(l==r) return this;
        int m = (l+r)>>1;
        ls = newnode()->build(l, m);
        rs = newnode()->build(m+1, r);
        return this;
    }
    Node* Node::insert(int p, int _v, int vs){
        if(l>p || r<p) return this;
        if(vs > version){
            Node *x = newnode()->init(this);
            x->version=vs;
            return x->insert(p, _v, vs);
        }
        if(l==r){
            v=_v;
            return this;
        }
        ls = ls->insert(p, _v, vs);
        rs = rs->insert(p, _v, vs);
        v = min(v, _v);
        return this;
    }
    int Node::query(int ql, int qr){
        // TST(ql); OUT(qr);
        if(ql>r || qr<l) return INT_MAX;
        if(ql<=l && r<=qr) return v;
        return min(ls->query(ql,qr), rs->query(ql,qr));
    }
    void init(){
        memset(heads, 0, sizeof heads);
        bat=memo;
    }
}
int c[Max_N],dfs_clk,l[Max_N],r[Max_N],DEP,dep[Max_N];
vi e[Max_N],dep_nodes[Max_N];
void build_tree(int n){
    SegmentTree::init();
    SegmentTree::heads[0] = SegmentTree::newnode()->build(0, n-1);
    rep(i, 0, Max_N){
        if(SZ(dep_nodes[i]) == 0)break;
        DEP=i;
        bool fg = 1;
        for(int j: dep_nodes[i]){
            // TST(i); OUT(j);
            if(fg && i) SegmentTree::heads[i] = SegmentTree::heads[i-1]->insert(l[j], c[j], i);
            else SegmentTree::heads[i] = SegmentTree::heads[i]->insert(l[j], c[j], i);
            fg=0;
        }
    }
}
int query_tree(int x, int K){
    return SegmentTree::heads[min(DEP,dep[x]+K)]->query(l[x],r[x]-1);
}
void dfs(int x,int f){
    dep[x]=((~f)?dep[f]+1:0);
    dep_nodes[dep[x]].pb(x);
    l[x]=dfs_clk++;
    for(int y: e[x]){
        if(y==f)continue;
        dfs(y,x);
    }
    r[x]=dfs_clk;
}
int main(){
    int n,r;scanf("%d%d",&n,&r);--r;
    rep(i,0,n)scanf("%d",c+i);
    int x,y;
    rep(i,0,n-1){
        scanf("%d%d",&x,&y);--x;--y;
        e[x].pb(y); e[y].pb(x);
    }
    dfs_clk=0;
    dfs(r,-1);
    build_tree(n);
    int _,K,lt=0;scanf("%d",&_);
    while(_--){
        scanf("%d%d",&x,&K);
        x=((x+lt)%n);
        K=(K+lt)%n;
        lt=query_tree(x,K);
        printf("%d\n",lt);
    }
    return 0;
}

/*------------------------------------------------------------------------------------------*/

// old template
// problem: BZOJ2120
const int N = 9 + (int)1e4;
const int M = 9 + (int)1e4;
struct DS{
#define lowbit(x) ((x)&(-x))
    struct nod{
        nod *ls, *rs;
        int v;
    }memo[N*30 + M*200], *bat, *rt0[N], *rt[N], Tnull, *null;
    bool FG;
    int n, up, last[N+M];
    void init (){
        bat = memo;
        null = &Tnull;
        null->ls = null->rs = null;
        null->v = 0;
        for (int i = 0; i <= n; ++ i) rt[i] = null;
        rt0[0] = null;
    }
    void build (int _n, int _up, int *a){
        n = _n; up = _up;
        init ();
        FG = 1;
        nod *x;
        //memset (last, 0, sizeof last);
        for (int i = 1; i <= n; ++ i){
            if (last[a[i]]){
                insert (last[a[i]], -1, 0, up, x = rt0[i-1]);
                insert (i, 1, 0, up, rt0[i] = x);
            } else{
                //puts ("b");
                insert (i, 1, 0, up, rt0[i] = rt0[i-1]);
            }
            last[a[i]] = i;
        }
        FG = 0;
    }
    void insert (int v, int t, int l, int r, nod *&x){
        if (FG || x == null){
            *bat = *x; x = bat++;
        }
        x->v += t;
        if (l == r) return;
        int m = l + r >> 1;
        if (v <= m) insert (v, t, l, m, x->ls);
        else insert (v, t, m+1, r, x->rs);
    }
    int query (int ql, int qr, int l, int r, nod *x){
        if ((ql <= l && r <= qr) || x == null) return x->v;
        int m = l + r >> 1, ret = 0;
        if (ql <= m) ret = query (ql, qr, l, m, x->ls);
        if (qr > m) ret += query (ql, qr, m+1, r, x->rs);
        return ret;
    }
    int solve (int l, int r){
        int ret = query (l, r, 0, up, rt0[r]);
        for (int i = r; i <= n; i += lowbit(i)){
            ret += query (l, r, 0, up, rt[i]);
        }
        return ret;
    }
    void modify (int p, int v, int l, int r){
        //printf ("l:%d r:%d p:%d v:%d\n", l, r, p, v);
        for (; r; r -= lowbit(r)) insert (p, v, 0, up, rt[r]);
        for (-- l; l; l -= lowbit(l)) insert (p, -v, 0, up, rt[l]);
    }
}T;
int main(){
    T.build (n, tot, a);        //tot is the max value in Segment Tree
    T.modify (p, v, l, r);
    T.solve (l, r);
    return 0;
}
