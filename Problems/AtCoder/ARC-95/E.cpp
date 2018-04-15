//Create Time: 2018-04-15 22:40:16
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
bool ok;
bool hs[15],st[15];
int n,m,top,sg;
pi an[22];
string s[22],ss[22];
bool eq(const string&a,const string&b){
    for(int i=0,j=SZ(b)-1;i<SZ(a);++i,--j){
        if(a[i]!=b[j])return 0;
    }
    return 1;
}
bool check(bool single){
    if((m&1) && single)return 0;
    rep(i,0,n){
        int j,x,y;
        for(j=0,x=0,y=m-1;j<top;++j,++x,--y){
            ss[i][x]=s[i][an[j].x];
            ss[i][y]=s[i][an[j].y];
        }
        if(m&1) ss[i][x]=s[i][sg];
    }

    memset(st,0,n*sizeof(st[0]));
    int cnt=0;
    rep(i,0,n)if(!st[i]){
        rep(j,i+1,n)if(!st[i]){
            if(eq(ss[i],ss[j])){
                st[i]=st[j]=1;
                cnt+=2;
                break;
            }
        }
    }
    if(cnt==n)return 1;
    if(cnt+1==n){
        rep(i,0,n)if(!st[i]){
            if(eq(ss[i],ss[i])){
                return 1;
            }
            break;
        }
    }
    return 0;
}
void dfs(int p,bool single){
    if(p==m){
        if(check(single))ok=1;
        return;
    }
    if(single){
        sg=p;
        hs[p]=1;
        int t=p+1;while(t<m && hs[t])++t;
        dfs(t,0);
        hs[p]=0;
    }
    rep(i,p+1,m){
        if(hs[i])continue;
        hs[p]=hs[i]=1;
        an[top++]={p,i};
        int t=p+1;while(t<m && hs[t])++t;
        dfs(t,single);
        --top;
        hs[p]=hs[i]=0;
    }
}
int main(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>s[i];
        ss[i].resize(m);
    }
    dfs(0,m&1?1:0);
    puts(ok?"YES":"NO");
    return 0;
}
