//Create Time: 2018-03-09 18:24:14
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
const int N=100009;
int an[N];
int n,b;
ll d;
bool ok(int m){
    if((n+1)/2==m)return 1;
    int s1=0,s2=0;
    for(int i=0;i<m+d*(m+1)+1;++i){
        if(i>=n)break;
        s1+=an[i];
    }
    for(int i=n-1;i>=n-m-1-d*(m+1);--i){
        if(i<0)break;
        s2+=an[i];
    }
    int l=m,r=n-m-1;
    ll lp=l+d*(m+1),rp=r-d*(m+1);
    // OUT(lp);OUT(rp);OUT(s1);OUT(s2);
    // OUT(l);OUT(r);
    while(l<r && lp<n && rp>=0){
        // TST(l);TST(r);TST(s1);OUT(s2);
        if(s1<b || s2<b)return 0;
        ++l;--r;
        s1-=b;s2-=b;
        for(int i=lp+1;i<=lp+d+1;++i){
            if(i>=n)break;
            s1+=an[i];
        }
        lp=lp+d+1;
        for(int i=rp-1;i>=rp-d-1;--i){
            if(i<0)break;
            s2+=an[i];
        }
        rp=rp-d-1;
    }
    return 1;
}
int main(){
    scanf("%d%lld%d",&n,&d,&b);
    rep(i,0,n)scanf("%d",an+i);
    int l=0,r=(n+1)/2,mid,ans=r;
    // ok(0);
    // return 0;
    while(l<=r){
        mid=(l+r)>>1;
        if(ok(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
