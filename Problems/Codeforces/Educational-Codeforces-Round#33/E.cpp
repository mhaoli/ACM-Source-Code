//Create Time: 2017-12-10 00:15:12
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
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
const int N=(int)1e6+9;;
const int mod=(int)1e9+7;
bool check[N];
int prm[N];
int primes(int n){
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
    // OUT(tot);
    return tot;
}
long long C(int n,int m){
    long long rs=1;
    if(m*2>n)m=n-m;
    for(int i=1,j=n;i<=m;++i,--j)rs=(rs*j%mod)*pow_mod(i,mod-2,mod)%mod;
    return rs;
}
int main(){
    int tn=primes(N-9);
    int _;cin>>_;
    ll as;
    while(_--){
        int x,y;
        scanf("%d%d",&x,&y);
        as=1;
        rep(i,0,tn){
            if(1ll*prm[i]*prm[i]>x)break;
            int c=0;
            while(x%prm[i]==0){
                ++c; x/=prm[i];
            }
            as=as*C(c+y-1,y-1)%mod;
        }
        if(x>1){
            as=as*C(y,1)%mod;
        }
        as=as*pow_mod(2,y-1,mod)%mod;
        printf("%lld\n",as);
    }
    return 0;
}
