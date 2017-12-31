//Create Time: 2017-12-23 22:50:23
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
char word[N];
set<int> an;
int ans_c;
void ers(int c){
    if(an.find(c)!=an.end()){
        an.erase(c);
    }
}
void ins(char*s){
    set<int> ns;
    while(s[0]>0){
        ns.insert(s[0]-'a');
        ++s;
    }
    auto tmp=an.begin();
    for(auto it=an.begin();it!=an.end();){
        if(ns.find(*it)==ns.end()){
            tmp=it;
            ++it;
            an.erase(tmp);
        } else ++it;
    }
}
int main(){
    int n;scanf("%d",&n);
    int ans=0;
    char op[5];
    ans_c=-1;
    rep(i,0,26)an.insert(i);
    while(n--){
        scanf("%s%s",op,word);
        // printf("%s %s\n",op,word);
        if(op[0]=='.'){
            int L=strlen(word);
            rep(i,0,L)ers(word[i]-'a');
        }else if(op[0]=='!'){
            ins(word);
            if(ans_c!=-1)++ans;
        }else if(op[0]=='?'){
            if(ans_c==-1){
                ers(word[0]-'a');
            }else if(ans_c!=word[0]-'a')++ans;
        }
        if(SZ(an)==1)ans_c=*an.begin();
    }
    cout<<ans<<endl;
    return 0;
}
