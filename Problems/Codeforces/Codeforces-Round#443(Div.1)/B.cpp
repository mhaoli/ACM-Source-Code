//Create Time: 2017-11-03 15:08:50
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
// #define DEBUG
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
typedef pair<int,ll> pil;
const int Max_N = (int)1e5 + 9;
pil stk[Max_N];
int main(){
    int n,K,m; cin>>n>>K>>m;
    int idx=-1;
    rep(i,0,n){
        int t; scanf("%d",&t);
        if(idx==-1 || t!=stk[idx].x){
            stk[++idx]=pii(t,1);
        }else{
            if(++stk[idx].y>=K){
                --idx;
            }
        }
    }
    ++idx;

    ll ans=0;
    int p=0;
    while(p<idx/2 && stk[p].x==stk[idx-p-1].x && stk[p].y+stk[idx-p-1].y==K) ++p;
#ifdef DEBUG
    if(n==1000 && K==2 && m==1000){
        
        OUT(idx); OUT(p);
        ll s=0; rep(i,0,idx) s+=stk[i].y;
        OUT(s);
        OUT(stk[p].x);
        OUT(stk[p].y);
        OUT(stk[idx-p-1].x);
        OUT(stk[idx-p-1].y);
    }
#endif
    if(idx%2==0){
        if(p==idx/2){
            rep(i,0,idx) ans+=stk[i].y;
        }else{
            rep(i,0,p) ans+=stk[i].y;
            rep(i,idx-p,idx) ans+=stk[i].y;
            ll s=0;
            rep(i,p,idx-p) s+=stk[i].y;
            ans+=s*m;
            if(stk[p].x==stk[idx-p-1].x && stk[p].y+stk[idx-p-1].y>K) ans-=(m-1ll)*K;
        }
    }else{
        if(p==idx/2){
            if((stk[p].y*m%K) == 0){
                int tidx=p-1;
                rep(i,p+1,idx){
                    if(tidx==-1 || stk[tidx].x!=stk[i].x){
                        stk[++tidx]=stk[i];
                    }else{
                        stk[tidx].y+=stk[i].y;
                        if(stk[tidx].y==K)--tidx;
                        if(stk[tidx].y>K)stk[tidx].y%=K;
                    }
                }
            }else{
                rep(i,0,p) ans+=stk[i].y;
                rep(i,idx-p,idx) ans+=stk[i].y;
                ans+=stk[p].y*m%K;
            }
        } else{
            rep(i,0,p) ans+=stk[i].y;
            rep(i,idx-p,idx) ans+=stk[i].y;
            ll s=0;
            rep(i,p,idx-p) s+=stk[i].y;
            ans+=s*m;
            if(stk[p].x==stk[idx-p-1].x && stk[p].y+stk[idx-p-1].y>K) ans-=(m-1ll)*K;
        }
    }
    cout<<ans<<endl;
    return 0;
}
