//Create Time: 2018-04-12 14:12:22
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
const ll mod=998244353;
const int N=(int)2e5+9;
template<int sz> struct combo{
    const ll mod = ::mod;
    ll *fac, *ifac;
    ll mem_fac[sz+5],mem_ifac[sz+5];
   
    // long long powmod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}

    combo(ll *fa=0,ll *ifa=0){
        fac=fa?fa:mem_fac;
        ifac=ifa?ifa:mem_ifac;
        fac[0]=ifac[0]=1;
        for(int i=1;i<=sz;++i){
            fac[i]=i*fac[i-1]%mod;
            ifac[i]=powmod(fac[i],mod-2,mod);
        }
    }
    ll comb(ll n,ll m){  // n >= m
        if(n<m)return 0;
        return (fac[n]*ifac[m]%mod)*ifac[n-m]%mod;
    }
};
namespace ntt{
    const int N=::N;
    const long long mod=::mod,rt=3;
    // (mod-1, rt, mod) && mod < 1e9:
        // (5 << 25, 3, 167772161)
        // (7 << 26, 3, 469762049)
        // (119 << 23, 3, 998244353)
    // (mod-1, rt, mod) && 2^30 > mod > 1e9: 
        // (479 << 21, 3, 1004535809)
        // (483 << 21, 5, 1012924417)
    
    // typedef long long T;  // only support long long, or you should replace all a*b with 1ll*a*b
    
    // long long powmod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}

    ll G[55],iG[55],itwo[55];

    void add(int &a,int b){a+=b;if(a>=mod)a-=mod;}

    void init(){
        int now=(mod-1)/2,len=1,irt=powmod(rt,mod-2,mod);
        while(now%2==0){
            G[len]=powmod(rt,now,mod);
            iG[len]=powmod(irt,now,mod);
            itwo[len]=powmod(1<<len,mod-2,mod);
            now>>=1;len++;
        }
    }
    void dft(ll *x,int n,int fg=1){  // fg=1 for dft, fg=-1 for inverse dft
        for(int i=(n>>1),j=1,k;j<n;++j){
            if(i<j)swap(x[i],x[j]);
            for(k=(n>>1);k&i;i^=k,k>>=1);i^=k;
        }
        ll r,tr,u,v;
        for(int m=2,now=1;m<=n;m<<=1,now++){
            r = fg>0 ? G[now] : iG[now];
            for(int i=0,j;i<n;i+=m){
                tr=1,u,v;
                for(j=i;j<i+(m>>1);++j){
                    u=x[j];v=x[j+(m>>1)]*tr%mod;
                    x[j]=(u+v)%mod;
                    x[j+(m>>1)]=(u+mod-v)%mod;
                    tr=tr*r%mod;
                }
            }
        }
    }
    void brute(ll *a,ll *b,int n,int m){
        static ll c[N];
        for(int k=0,t;k<n+m-1;++k){
            t=0;
            for(int i=max(k-m+1,0);i<n && i<=k;++i){add(t,a[i]*b[k-i]%mod);
                // if(k==2&&i==1)OUT(a[i]),OUT(b[k-i]);
            }
            c[k]=t;
        }
        for(int k=0;k<n+m-1;++k)a[k]=c[k];
    }
    void mul(ll *a,ll *b,int n,int m){   // a: 0,1,2,...,n-1; b: 0,1,2,...,m-1
        if(n+m<=100){
            brute(a,b,n,m);
            return;
        }
        int nn=n+m-1;
        if(n==0||m==0){
            memset(a,0,nn*sizeof(a[0]));
            return;
        }
        int L,len;for(L=1,len=0;L<nn;++len,L<<=1);
        if(n<L)memset(a+n,0,(L-n)*sizeof(a[0]));
        if(m<L)memset(b+m,0,(L-m)*sizeof(b[0]));
        dft(a,L,1);dft(b,L,1);
        for(int i=0;i<L;++i)a[i]=a[i]*b[i]%mod;
        dft(a,L,-1);
        for(int i=0;i<L;++i)a[i]=a[i]*itwo[len]%mod;
    }
}
ll a[N],b[N],fac[N],fnv[N],u[N],v[N],pw[N],ct[N],c[N];
combo<100005> C(fac,fnv);
void solve(int n){
    if(n==1){
        c[0]=0;
        c[1]=1;
    } else if(n&1){
        solve(n-1);
        per(i,n+1,1) c[i]=(c[i-1]+(ll)(n-1)*c[i])%mod;
        c[0]=0;
    } else{
        solve(n/2);
        int t=n/2;
        pw[0]=1;rep(i,1,t+1) pw[i]=pw[i-1]*t%mod;
        rep(i,0,t+1) u[i]=c[i]*fac[i]%mod;
        rep(i,0,t+1) v[i]=pw[i]*fnv[i]%mod;
        reverse(v,v+t+1);
        ntt::mul(u,v,t+1,t+1);
        rep(i,0,t+1) ct[i]=u[i+t]*fnv[i]%mod;
        ntt::mul(c,ct,t+1,t+1);
    }
}
int main(){
    int n,a,b;cin>>n>>a>>b;
    --a;--b;
    if(a<0||b<0){
        puts("0");return 0;
    }
    if(n==1){
        puts(a==0&&b==0?"1":"0");return 0;
    }
    if(a+b>=n){
        puts("0");return 0;
    }

    ntt::init();
    solve(n-1);
    cout<<C.comb(a+b,a) * c[a+b] % mod;
    return 0;
}
