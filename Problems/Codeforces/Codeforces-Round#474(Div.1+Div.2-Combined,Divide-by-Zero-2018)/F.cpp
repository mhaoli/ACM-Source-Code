//Create Time: 2018-04-13 15:05:08
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
set<pii> dp[N];  //(value, len)
int main(){
    int n,m;scanf("%d%d",&n,&m);
    rep(i,0,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);--u;--v;
        int len=1;
        auto it=dp[u].begin();
        if(SZ(dp[u])){
            it=dp[u].lower_bound(pii(w,-1));
            if(it==dp[u].begin())len=1;
            else{
                --it;
                len=it->y+1;
            }
        }

        it=dp[v].lower_bound(pii(w,-1));
        if(it!=dp[v].begin()){
            auto t=it;--t;
            if(len<=t->y)continue;
        }
        while(it!=dp[v].end() && len>=it->y){
            auto t=it;++it;
            dp[v].erase(t);
        }
        dp[v].insert(pii(w,len));
    }
    int ans=0;
    rep(i,0,n)if(SZ(dp[i])){
        auto it=dp[i].end();--it;
        chmax(ans,it->y);
    }
    cout<<ans<<endl;
    return 0;
}
