//Create Time: 2018-01-06 23:28:17
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
const int N=(int)1e5+9;
int mn[N],sn[N],rn[N];
vii ev[N];
int main(){
    int n,m;
    rd(n);rd(m);
    int b,inc,dg;
    rd(b);rd(inc);rd(dg);
    rep(i,0,n){
        rd(mn[i]),rd(sn[i]),rd(rn[i]);
        if(mn[i]<=dg && inc>0){
            puts("-1");return 0;
        }
    }
    rep(i,0,m){
        int t1,t2,t3;
        rd(t1);rd(t2);rd(t3);--t2;
        ev[t2].pb(pii(t1,t3));
    }
    // time,+/-1
    vii event;
    int nxt,always=0;
    rep(i,0,n){
        if(mn[i]<=dg){
            always+=1;
            continue;
        }
        bool ok=1;
        if(dg<sn[i])nxt=INT_MAX,ok=0;
        else {
            if(rn[i]==0) nxt=-1;
            else nxt=(dg-sn[i]+rn[i])/rn[i];
        }
        sort(all(ev[i]));
        for(auto j: ev[i]){
            if(j.x>nxt){
                if(nxt!=-1){
                    event.pb(pii(nxt,-1));
                    ok=0;
                }
            }
            if(ok && j.y>dg)event.pb(pii(j.x,-1));
            if(!ok && j.y<=dg)event.pb(pii(j.x,1));

            if(j.y<=dg){
                ok=1;
                if(rn[i]==0)nxt=-1;
                else nxt=j.x+(dg-j.y+rn[i])/rn[i];
            }else{
                ok=0;nxt=INT_MAX;
            }
        }
        if(ok){
            if(nxt==-1){
                if(inc==0) nxt=INT_MAX;
                else{
                    puts("-1");return 0;
                }
            }
            event.pb(pii(nxt,-1));
        }
    }
    sort(all(event));
    int cnt=always;
    rep(i,0,n)if(sn[i]<=dg && mn[i]>dg)++cnt;
    ll ans=1ll*cnt*b;
    for(auto i: event){
        // TST(i.x);OUT(i.y);
        chmax(ans, 1ll*cnt*(b+(i.x-1ll)*inc));
        cnt+=i.y;
    }
    cout<<ans<<endl;
    return 0;
}
