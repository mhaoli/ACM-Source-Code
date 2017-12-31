//Create Time: 2017-12-30 23:16:46
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
const int N = 111111;
bool check[N];
int prm[N];

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
int calc_phi(int n, int np){
    int ans = n;
    for(int i = 0; i < np; ++i){
        if(1ll * prm[i] * prm[i] > n)break;
        if(n % prm[i] == 0){
            while(n % prm[i] == 0) n /= prm[i];
            ans = ans / prm[i] * (prm[i]-1);
        }
    }
    if(n > 1){
        ans = ans / n * (n-1);
    }
    return ans;
}
vi pm;
int an[N];
int gao(int l,int r,int it){
    if(l==r)return min(an[l],an[l]%pm[it]+pm[it]);
    if(pm[it]==1)return 1;
    int c=gao(l+1,r,it+1);
    int t=pm[it],v=1;
    if(an[l]==1)return 1;
    rep(i,0,c){
        t/=an[l];
        v*=an[l];
        if(!t)break;
    }
    if(!t)return pow_mod(an[l],c,pm[it])+pm[it];
    else return v;
}
int main(){
    int np=primes(N-5);
    int n,mod,t;
    cin>>n>>mod;
    t=mod;
    while(1){
        pm.pb(t);
        if(t==1)break;
        t=calc_phi(t,np);
    }

    rep(i,0,n)scanf("%d",an+i);

    int _,l,r;cin>>_;
    while(_--){
        scanf("%d%d",&l,&r);--l;--r;
        printf("%d\n",gao(l,r,0)%mod);
    }
    return 0;
}
