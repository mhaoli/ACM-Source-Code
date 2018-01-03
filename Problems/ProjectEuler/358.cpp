//Create Time: 2018-01-02 23:19:04
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
namespace Factor{
    long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
    const int N=1010000;
    int tot,top,size;
    int prm[N],least_prm[N],_phi[N];
    int stk_p[111],stk_k[111];
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
    void _factor(int n){
        int i,t;
        for(i=0;i<tot && n>size && prm[i]*prm[i]<=n;++i){
            if(n%prm[i]==0){
                stk_k[top]=1;
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
    bool is_prime(int p){
        if(p==1)return 0;
        if(p<=size)return least_prm[p]==p;
        for(int i=0;i<tot && p>size && prm[i]*prm[i]<=p;++i){
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
    vector<pii> factorG(int n){
        top=0;
        _factor(n);
        vector<pii> d;
        for(int i=0;i<top;++i)d.pb(pii(stk_p[i],stk_k[i]));
        return d;
    }
    int phi(int x){
        if(x<=size)return _phi[x];
        vector<pii> d=factorG(x);
        for(auto p:d) x=x/p.x*(p.x-1);
        return x;
    }
    bool is_primitive(int a,int p){
        if(a>=p)return 0;
        assert(is_prime(p));
        vector<pii> d=factorG(p-1);
        for(auto i:d) if(pow_mod(a,(p-1)/i.x,p)==1)return 0;
        return 1;
    }
}
bool endswith56789(int p){
    int mod = 100000;
    if((p % mod) * 56789ll % 100000 == 99999) return 1;
    return 0;
}
int main(){
    // freopen("358.txt","w",stdout);
    int n=(int)3e4;
    int tot=Factor::init(n);
    OUT(tot);
    int l=100000000000ll/138+1, r=100000000000ll/137+1;
    n=r-l;
    rep(i,l,r){
        // printf("process %.8f\n",(i-l+0.0)/n);
        if(endswith56789(i) && Factor::is_prime(i) && Factor::is_primitive(10,i)){
            printf("p = %d\n",i); 
            printf("ans = %lld\n",(i-1ll)*9/2);
        }
    }
    puts("");
    return 0;
}
