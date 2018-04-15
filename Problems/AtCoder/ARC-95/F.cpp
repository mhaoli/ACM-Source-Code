//Create Time: 2018-04-15 15:41:17
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
#define TST(x) std::cout<<(#x)<<":"<<(x)<<" "
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define DEBUG
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long powmod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
const int N=(int)1e5+9;
vi eg[N];
int dep[N];
int top,value;
bool has_ans;
void dfs1(int u,int fa){
    dep[u]=fa==-1?0:dep[fa]+1;
    for(int v: eg[u])if(v!=fa)dfs1(v,u);
}
void gao(int u,int fa,int end,vi &res){
    while(has_ans){
        int v,hv=-1,t=value++;
        rep(i,0,SZ(eg[u])){
            v=eg[u][i];
            if(v==fa)continue;
            if(SZ(eg[v])>1||v==end){
                if(hv==-1){
                    hv=v;continue;
                } else {
                    has_ans=0;return;
                }
            }
            res[top++]=value++;
        }
        // if(u==0)OUT(hv),OUT(t),OUT(top);
        res[top++]=t;
        fa=u;u=hv;
        if(hv==-1)break;
    }
}
int main(){
    int n; scanf("%d",&n);
    rep(i,0,n-1){
        int u,v;scanf("%d%d",&u,&v);--u;--v;
        eg[u].pb(v);eg[v].pb(u);
    }
    dfs1(0,-1);
    int l=max_element(dep,dep+n)-dep;
    dfs1(l,-1);
    int r=max_element(dep,dep+n)-dep;
    // OUT(l);OUT(r);

    vi res1(n),res2(n);
    has_ans=1;
    top=0;
    value=1;
    gao(l,-1,r,res1);
    if(!has_ans){
        puts("-1");return 0;
    }
    // for(int i:res1)TST(i);puts("");
    top=0;
    value=1;
    gao(r,-1,l,res2);
    // for(int i:res2)TST(i);puts("");
    int t=-1;
    rep(i,0,SZ(res1)){
        if(res1[i]==res2[i])continue;
        if(res1[i]<res2[i])t=1;
        else t=2;
        if(t!=-1)break;
    }
    if(t==1)for(int i:res1)printf("%d ",i);
    else for(int i:res2)printf("%d ",i);
    return 0;
}
