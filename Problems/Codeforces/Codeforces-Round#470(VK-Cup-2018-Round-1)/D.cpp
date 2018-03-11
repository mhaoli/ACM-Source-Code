//Create Time: 2018-03-11 01:12:10
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
const int N=(int)1e5+9;
char s[N],t[N],ans[N];
int an[N],bn[N],last1[N],last2[N];
int id(char c){
    if(c=='A')return 0;
    return 1;
}
int get_cnt(int *sum,int l,int r){
    if(l==0)return sum[r];
    return sum[r]-sum[l-1];
}
char gao(int a,int b,int c,int d){
    int cnt1,cnt2,L1,L2;
    // TST(a),TST(b),TST(an[a]),OUT(an[b]);
    cnt1=get_cnt(an,a,b);
    cnt2=get_cnt(bn,c,d);
    L1=min(b-last1[b],b-a+1);
    L2=min(d-last2[d],d-c+1);
    // if(a==5&&c==16)
    // TST(L1),TST(L2),TST(cnt1),OUT(cnt2);
    if(cnt1>cnt2)return '0';
    if((cnt2-cnt1)%2)return '0';
    if(L1<L2)return '0';
    if((L1-L2)%3 && cnt1+2>cnt2)return '0';
    if(cnt1==0 && cnt2>0 && L1==L2)return '0';
    return '1';
}
int main(){
    scanf("%s",s);
    scanf("%s",t);
    // rep(i,5,13)printf("%c ",s[i]); puts("");
    // rep(i,16,17)printf("%c ",t[i]); puts("");

    int n=strlen(s),m=strlen(t);
    an[0]=id(s[0]);
    rep(i,1,n){
        an[i]=an[i-1]+id(s[i]);
    }
    // rep(i,0,n)TST(an[i]);
    // puts("");
    bn[0]=id(t[0]);
    rep(i,1,m){
        bn[i]=bn[i-1]+id(t[i]);
    }
    // rep(i,0,m)TST(bn[i]);
    // puts("");

    int last=-1;
    rep(i,0,n){
        if(s[i]!='A')last=i;
        last1[i]=last;
    }
    last=-1;
    rep(i,0,m){
        if(t[i]!='A')last=i;
        last2[i]=last;
    }

    int _;scanf("%d",&_);
    int a,b,c,d,top=0;
    while(_--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        ans[top++]=gao(a-1,b-1,c-1,d-1);
    }
    ans[top]=0;
    puts(ans);
    return 0;
}
