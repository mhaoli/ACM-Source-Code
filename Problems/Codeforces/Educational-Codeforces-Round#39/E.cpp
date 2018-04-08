//Create Time: 2018-04-03 11:32:53
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
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
const int N=(int)2e5+9;
bool is_ok;
char s[N];
int cnt[20],n;
bool ok(int l,int st){
    int t=0;
    rep(i,0,10)if(cnt[i]&1)++t;
    if(t>l)return 0;
    // OUT(l);OUT(st);
    int i,j;
    for(i=n-1,j=0;i>=st;--i){
        while(j<10 && !(cnt[j]&1))++j;
        if(j<10) {
            s[i]='0'+j;
            ++j;
        } else break;
    }
    while(i>=st){
        s[i]='9';
        --i;
    }
    return 1;
}
bool calc(){
    per(i,n,0){
        char c=s[i];
        --cnt[c-'0'];
        per(j,s[i],'0'){
            if(i==0&j=='0')break;
            s[i]=j;
            ++cnt[j-'0']; if(ok(n-1-i,i+1)){
                puts(s);
                return 1;
            }
            --cnt[j-'0'];
        }
    }
    return 0;
}
int main(){
    int _;scanf("%d",&_);
    while(_--){
        scanf("%s",s);
        n=strlen(s);
        clr(cnt);
        rep(i,0,n)cnt[s[i]-'0']++;
        if(!calc()){
            rep(i,0,n-2)s[i]='9';
            s[n-2]=0;
            puts(s);
        }
    }
    return 0;
}
