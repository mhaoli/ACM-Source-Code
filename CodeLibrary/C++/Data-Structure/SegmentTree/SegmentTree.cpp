//Problem: CF620E New Year Tree
//Create Time: 2017-10-31 19:35:05
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
using namespace std;
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define debug
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<pair<int,pii > > viii;
/****head****/
const int Max_N=(int)4e5+9;
namespace SegmentTree{
    const int Max_N=(int)4e5+9;
    #define lson l,m,rt<<1
    #define rson m+1,r,rt<<1|1
    /****************head*************/
    int n;
    ll val[Max_N<<2];
    int lazy[Max_N<<2];
    void update(int l,int r,int rt){
        val[rt]=val[rt<<1]|val[rt<<1|1];
    }
    void relax(int l,int r,int rt){
        if(lazy[rt]!=-1){
            val[rt<<1]=val[rt<<1|1]=1ll<<lazy[rt];
            lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
            lazy[rt]=-1;
        }
    }
    void _build(int *value,int l=0,int r=n-1,int rt=1){
        lazy[rt]=-1;
        if(l==r){
            val[rt]=1ll<<value[l];
            // if(l == 6 || (l>=13&&l<=15)) cout<<"l="<<l<<":"<<value[l]<<" "<<val[rt]<<"rt="<<rt<<endl;
        }else{
            int m=l+r>>1;
            _build(value,lson); _build(value,rson);
            update(l,r,rt);
        }
    }
    void build(int _n, int *value){
        n=_n;
        // memset(lazy,-1,sizeof lazy);
        _build(value);
    }
    void modify(int ql,int qr,int qv,int l=0,int r=n-1,int rt=1){
        if(ql<=l && qr>=r){
            lazy[rt]=qv;
            val[rt]=1ll<<qv;
        }else{
            int m=l+r>>1;
            relax(l,r,rt);
            if(ql<=m) modify(ql,qr,qv,lson);
            if(qr>m) modify(ql,qr,qv,rson);
            update(l,r,rt);
        }
    }
    ll query(int ql,int qr,int l=0,int r=n-1,int rt=1){
        if(ql<=l && qr>=r){
            // printf("ql=%d, qr=%d, l=%d, r=%d, rt=%d, val[rt]=%lld\n",ql,qr,l,r,rt,val[rt]);
            return val[rt];
        } else{
            int m=l+r>>1;
            relax(l,r,rt);
            ll s1=0,s2=0;
            if(ql<=m) s1=query(ql,qr,lson);
            if(qr>m) s2=query(ql,qr,rson);
            update(l,r,rt);
            return s1|s2;
        }
    }
}
int clk,n;
int color[Max_N],L[Max_N],R[Max_N],color_clk_style[Max_N];
vector<int> son[Max_N];
void dfs(int x,int f){
    L[x]=clk++;
    for(int s:son[x])if(s!=f){
        dfs(s,x);
    }
    R[x]=clk;
}
void build(){
    rep(i,0,n) color_clk_style[L[i]]=color[i];
    SegmentTree::build(n,color_clk_style);
}
void modify(int v,int c){
    SegmentTree::modify(L[v],R[v]-1,c);
}
int query(int v){
    // return SegmentTree::query(L[v],R[v]-1);
    return __builtin_popcountll(SegmentTree::query(L[v],R[v]-1));
}
int main(){
    int _;cin>>n>>_;
    rep(i,0,n){
        scanf("%d",color+i);--color[i];
    }
    rep(i,0,n-1){
        int x,y; scanf("%d%d",&x,&y);--x;--y;
        son[x].pb(y);
        son[y].pb(x);
    }
    clk=0; dfs(0,-1);

    // rep(i,0,n) cout<<"Node "<<i<<":"<<L[i]<<" "<<R[i]<<endl;
   //  
    build();
    // printf("%d\n",query(6));
    rep(i,0,_){
        int opt,v,c;scanf("%d",&opt);
        if(opt==1){
            scanf("%d%d",&v,&c);--v;--c;
            modify(v,c);
            // rep(i,0,n) cout<<query(i)<<" ";
            // cout<<endl;
        } else{
            scanf("%d",&v);--v;
            // cout<<"v="<<v<<" :";
            printf("%d\n",query(v));
        }
    }
    return 0;
}
