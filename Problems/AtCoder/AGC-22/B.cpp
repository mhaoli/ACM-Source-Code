//Create Time: 2018-04-15 22:57:03
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi > vii;
/****head****/
int main(){
    int n;cin>>n;
    if(n==3){
        puts("2 5 63"); return 0;
    }
    vi a,b,c;
    rep(i,5,30001){
        if(i%2!=0){
            if(i%3==0 && i>9)c.pb(i);
            continue;
        }
        if(i%3==0)b.pb(i);
        else a.pb(i);
    }
    int i=0,j=0,k=0;
    vi ans={2,3,4,9};
    while(SZ(ans)<n){
        if(i+1<SZ(a)){
            if(SZ(ans)+1==n){
                ans.pb(b[j++]);
            }else{
                ans.pb(a[i++]);
                ans.pb(a[i++]);
            }
        }else if(k+1<SZ(c)){
            if(SZ(ans)+1==n){
                ans.pb(b[j++]);
            }else{
                ans.pb(c[k++]);
                ans.pb(c[k++]);
            }
        }else{
            assert(j<SZ(b));
            ans.pb(b[j++]);
        }
    }
    assert(SZ(ans)==n);
    // sort(all(ans));
    // rep(i,1,SZ(ans))if(ans[i]==ans[i-1])TST(ans[i-1]),OUT(ans[i]),assert(false);
    // set<int> tt(all(ans));
    // assert(SZ(tt)==SZ(ans));
    for(int i:ans)printf("%d ",i);
    return 0;
}
