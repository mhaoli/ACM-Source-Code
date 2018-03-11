//Create Time: 2018-03-10 23:40:31
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
const int maxn = (int)1e6;
bool check[maxn+5];
int prm[maxn+5];

int primes(int n){
    //memset(check, 0, sizeof check);
    int tot = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[tot++] = i;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            //这里，prm[j]是合数i*prm[j]最小的质因子
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
    return tot;
}
int pn[100];
int calc(int p1,int p2,int x2){
    int t=(x2-p2+1)/p1;
    if(t*p1!=(x2-p2+1))++t;
    if(t==1)++t;
    if(t*p1>x2)return INT_MAX;
    int ans=t*p1-p1+1;
    if(ans<3)return INT_MAX;
    return ans;
}
int main(){
    int tot=primes(maxn);
    int x2;
    scanf("%d",&x2);

    int m=0,t=x2;
    for(int i=0;i<tot && prm[i]*prm[i]<=t;++i){
        if(t%prm[i]>0)continue;
        pn[m++]=prm[i];
        while(t%prm[i]==0)t/=prm[i];
    }
    if(t>1)pn[m++]=t;

    int ans=x2;
    rep(i,0,tot)rep(j,0,m){
        chmin(ans,calc(prm[i],pn[j],x2));
    }
    cout<<ans<<endl;
    return 0;
}
