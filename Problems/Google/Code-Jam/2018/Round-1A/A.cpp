//Create Time: 2018-04-14 09:08:06
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
string s[111];
bool check(int n,int m,int h,int v,int tot){
    if(tot==0)return 1;
    if(tot%((h+1)*(v+1))!=0)return 0;
    int c=tot/(h+1)/(v+1);
    vector<pii> hn,vn;
    int last=0,tmp=0,up=c*(v+1);
    rep(i,0,n){
        rep(j,0,m)if(s[i][j]=='@')++tmp;
        if(tmp==up){
            hn.pb(pii(last,i));
            last=i+1;
            tmp=0;
        }else if(tmp>up) return 0;
    }
    if(SZ(hn)!=h+1)return 0;

    tmp=0;up=c*(h+1);
    last=0;
    rep(j,0,m){
        rep(i,0,n)if(s[i][j]=='@')++tmp;
        if(tmp==up){
            vn.pb(pii(last,j));
            last=j+1;
            tmp=0;
        } else if(tmp>up)return 0;
    }
    if(SZ(vn)!=v+1)return 0;

    for(pii i:hn) for(pii j: vn){
        int cnt=0;
        rep(x,i.x,i.y+1) rep(y,j.x,j.y+1) {
            if(s[x][y]=='@')++cnt;
        }
        if(cnt!=c)return 0;
    }
    return 1;
}
int main(){
    int _,cas=0;scanf("%d",&_);
    while(_--){
        int n,m,h,c;scanf("%d%d%d%d",&n,&m,&h,&c);
        int tot=0;
        rep(i,0,n){
            cin>>s[i];
            rep(j,0,m)if(s[i][j]=='@')++tot;
        }
        printf("Case #%d: ",++cas);
        puts(check(n,m,h,c,tot)?"POSSIBLE":"IMPOSSIBLE");
    }
    return 0;
}
