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
