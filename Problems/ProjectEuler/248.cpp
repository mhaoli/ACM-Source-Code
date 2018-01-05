//Create Time: 2018-01-05 00:01:52
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
const int N=1010000;
typedef pair<long long, long long> pll;
namespace Factor{
    long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
    const int N=1010000;
    int tot,top,size;
    int prm[N],least_prm[N],_phi[N];
    long long stk_p[111],stk_k[111];
    void prime_table(){
        int i,j,t1;
        tot=0;
        _phi[1]=1;
		for(i=1;i<=size;i++) least_prm[i]=i;
		for(i=2;i<=size;i++){
			if(least_prm[i]==i) prm[tot++]=i,_phi[i]=i-1;
			for(j=0;j<tot && (t1=prm[j]*i)<=size;j++){
				least_prm[t1]=prm[j];
				if(i%prm[j]==0){
                    _phi[i*prm[j]] = _phi[i]*prm[j]; break;
                }else{
                    _phi[i*prm[j]] = _phi[i]*(prm[j]-1);
                }
			}
		}
    }
    void _factor(long long n){
        int i,t;
        for(i=0;i<tot && n>size && 1ll*prm[i]*prm[i]<=n;++i){
            if(n%prm[i]==0){
                stk_k[top]=0;
                stk_p[top]=prm[i];
                while(n%prm[i]==0){
                    stk_k[top]++;
                    n/=prm[i];
                }
                ++top;
            }
        }
        if(n>size){
            stk_k[top]=1;
            stk_p[top++]=n;
            return;
        }
        while(n>1){
            t=least_prm[n];
            if(!top || stk_p[top-1]!=t){
                stk_k[top]=1;
                stk_p[top++]=t;
            }else ++stk_k[top-1];
            n/=t;
        }
    }
    bool is_prime(long long p){
        if(p==1)return 0;
        if(p<=size)return least_prm[p]==p;
        for(int i=0;i<tot && p>size && 1ll*prm[i]*prm[i]<=p;++i){
            if(p%prm[i]==0)return 0;
        }
        return 1;
    }
    /****************************************************/
    // return prime num
    int init(int n){
        size=n;
        prime_table();
        return tot;
    }
    vector<pll> factorG(long long n){
        top=0;
        _factor(n);
        vector<pll> d;
        for(int i=0;i<top;++i)d.pb(pll(stk_p[i],stk_k[i]));
        return d;
    }
    long long phi(long long x){
        if(x<=size)return _phi[x];
        vector<pll> d=factorG(x);
        for(auto p:d) x=x/p.x*(p.x-1);
        return x;
    }
    bool is_primitive(long long a,long long p){
        if(a>=p)return 0;
        assert(is_prime(p));
        vector<pll> d=factorG(p-1);
        for(auto i:d) if(pow_mod(a,(p-1)/i.x,p)==1)return 0;
        return 1;
    }
}
// for 13!
int an[6]={10,5,2,1,1,1};
int pn[6]={2,3,5,7,11,13};
int dn[6][6];
int bn[10],cn[10];
vector<ll> ans,prm;
map<ll,vector<ll> > has;
ll fac13,pre;
void dfs1(int p,ll a){
    if(a == 1){
        ans.pb(pre);
        return;
    }
    if(p == SZ(prm))return;
    if(a < prm[p]-1)return;
    if(a%(prm[p]-1)==0){
        pre*=prm[p];
        dfs1(p+1,a/(prm[p]-1));
        pre/=prm[p];
    }
    dfs1(p+1,a);
}
int cnt;
void calc(){
    ll t=1;
    pre=1;
    rep(i,0,6){
        cn[i]=bn[i];
        if(bn[i]>0){
            --cn[i];
            if(i==1){
                ++cn[0];
            } else if(i==2){
                cn[0]+=2;
            } else if(i==3){
                ++cn[0]; ++cn[1];
            } else if(i==4){
                ++cn[0]; ++cn[2];
            } else if(i==5){
                cn[0]+=2;++cn[1];
            }
        }
        // t*=pow(pn[i],an[i]-cn[i]);
        // pre*=pow(pn[i],bn[i]);
        // t2*=pow(pn[i],bn[i]);
    }
    rep(i,0,6){
        if(cn[i]>an[i])return;
        t*=pow(pn[i],an[i]-cn[i]);
        pre*=pow(pn[i],bn[i]);
    }
    dfs1(0, t);
}
void dfs(int p){
    if(p==6){
        calc();
        return ;
    }
    rep(i,0,an[p]+2){
        bn[p]=i;
        dfs(p+1);
    }
}
void dfs0(int p){
    if(p==6){
        ll t=1;
        rep(i,0,6) t*=pow(pn[i],bn[i]);
        t+=1;
        rep(i,0,6)if(t%pn[i]==0)return;
        if(!Factor::is_prime(t))return;
        prm.pb(t);
        return;
    }
    rep(i,0,an[p]+1){
        bn[p]=i;
        dfs0(p+1);
    }
}
int main(){
    clock_t st=clock();
    Factor::init(N-5);
    fac13=1;
    rep(i,1,14)fac13*=i;
    OUT(fac13);

    dfs0(0);
    sort(all(prm));
    // rep(i,0,10)TST(prm[i]);
    // puts("");
    OUT(SZ(prm));
    OUT(SZ(set<ll>(all(prm))));
    printf("%f seconds\n",(clock()-st)/(1000000.0));
    st=clock();

    cnt=0;
    dfs(0);
    OUT(SZ(ans));
    OUT(SZ(set<ll>(all(ans))));
    printf("%f seconds\n",(clock()-st)/(1000000.0));

    sort(all(ans));
    int n = 150000;
    n-=1;
    if(n<SZ(ans)) OUT(ans[n]);
    return 0;
}
