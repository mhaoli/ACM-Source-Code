//Create Time: 2018-04-14 21:58:27
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
const int N=(int)2e5+9;
map<int,int> has[N];
int query(int x,int w){
    int res=0;
    for(;w>0;w-=w&(-w)){
        auto it=has[x].find(w);
        if(it!=has[x].end())chmax(res,it->y);
    }
    return res;
}
void modify(int x,int w,int len){
    for(;w<=100002;w+=w&(-w)){
        // has[x][w]=max(has[x][w],len);
        auto it=has[x].find(w);
        if(it!=has[x].end())has[x][w]=max(it->y,len);
        else has[x][w]=len;
    }
}
int main(){
    int n,m;cin>>n>>m;
    rep(i,0,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w); w+=2; --u;--v;
        modify(v,w,query(u,w-1)+1);
    }
    int ans=0;
    rep(i,0,n)chmax(ans,query(i,100002));
    cout<<ans<<endl;
    return 0;
}
