//Create Time: 2017-11-22 11:20:37
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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
// special: index 1-based
const int Max=(int)1e9;
const int Max_N=(int)1e6+9;
int c[Max_N],clk,d[Max_N*20],*ds[Max_N],*de[Max_N],*bat;
ll sum[Max_N*20];
int dfs1(int x,int n){
    if(x>n)return 0;
    int l1=dfs1(x<<1,n),l2=dfs1(x<<1|1,n);
    ds[x]=bat;
    bat+=1+l1+l2;
    de[x]=bat;
    return l1+1+l2;
}
void merge(int*of,int l1,int s1,int l2,int s2){
    int i1=0,i2=0,v1,v2;
    // TST(l1);OUT(l1);
    while(i1<l1 || i2<l2){
        v1=v2=Max;
        if(i1<l1)v1=*(ds[s1]+i1)+c[s1];
        if(i2<l2)v2=*(ds[s2]+i2)+c[s2];
        if(v1<v2){
            *of=v1;++of;++i1;
        }else{
            *of=v2;++of;++i2;
        }
    }
}
int dfs2(int x,int n){
    if(x>n)return 0;
    int l1=dfs2(x<<1,n),l2=dfs2(x<<1|1,n);
    *ds[x]=0;
    // puts("-----------");
    // if(x==1)OUT(l1),OUT(l2);
    merge(ds[x]+1,l1,x<<1,l2,x<<1|1);
    // puts("-----------");
    return l1+l2+1;
}
ll get_sum(int x,int l){
    int *p=lower_bound(ds[x],de[x],l);
    if(p==ds[x]) return 0;
    int num=p-ds[x];
    return 1ll*l*num-sum[p-d-1];
}
ll calc(int x,int l){
    ll s=0;
    int last=-1;
    while(x>0&&l>=0){
        s+=get_sum(x,l);
        if(~last){
            s-=get_sum(last,l-c[last]);
        }
        last=x;
        l-=c[last];
        x>>=1;
    }
    return s;
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    rep(i,2,n+1)scanf("%d",c+i);

    bat=d;
    dfs1(1,n);
    dfs2(1,n);
    rep(i,1,n+1){
        int *p=ds[i];
        ll *is=&sum[p-d];
        *is=*p;++is;++p;
        for(;p!=de[i];++p,++is){
            *is=*(is-1)+(*p);
        }
    }

    // OUT(c[2]);
    // OUT(calc(1,8));
    // OUT(get_sum(1,8));
    // for(int*p=ds[1];p!=de[1];++p)
        // OUT((*p));

    while(m--){
        int x,q;
        scanf("%d%d",&x,&q);
        ll ans=calc(x,q);
        printf("%lld\n",ans);
    }
    return 0;
}
