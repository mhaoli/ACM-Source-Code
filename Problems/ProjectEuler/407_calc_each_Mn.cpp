// Create Time: 2018-01-01 14:35:10
// calc 48s for all 10^7 calc(n)
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
const int N=(int)1e7+5;

int prm[N+5], phi[N+5];
bool check[N+5];

int phi_table(int n){
    memset(check, 0, n * sizeof(check[0]));
    phi[1] = 1;
    int tot = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[ tot++ ] = i, phi[i] = i - 1;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            check[ i*prm[j] ] = 1;
            if (i % prm[j] == 0){
                phi[ i*prm[j] ] = phi[i] * prm[j]; break;
            }
            else phi[ i*prm[j] ] = phi[i] * (prm[j] - 1);
        }
    }
    return tot;
}
int np,top,ans;
int an[N/10];
void dfs(int p,int u,int v){
    if(p==top){
        // TST(u);OUT(v);
        if(v!=1)
            chmax(ans,int(u*(pow_mod(u,phi[v]-1,v))));
        return;
    }
    dfs(p+1,u*an[p],v);
    dfs(p+1,u,v*an[p]);
}
int calc(int n){
    int t;
    top=0;
    rep(i,0,np){
        if(phi[i]*phi[i]>n)break;
        if(n%prm[i]!=0)continue;
        t=n;
        while(n%prm[i]==0){
            n/=prm[i];
        }
        an[top++]=t/n;
    }
    if(n>1)an[top++]=n;

    ans=0;
    dfs(0,1,1);
    return ans;
}
int main(){
    freopen("407.txt","w",stdout);
    clock_t st=clock();
    np=phi_table(N-5);
    for(int i=1;i<=N-5;++i){
        printf("%d,",calc(i));
        // if(i%10000==0){
            // TST(i);
            // printf("%f seconds\n",(clock()-st)/(1000000.0));
        // }
        // calc(i);
    }
    puts("");
    printf("total %f seconds\n",(clock()-st)/(1000000.0));
    return 0;
}
