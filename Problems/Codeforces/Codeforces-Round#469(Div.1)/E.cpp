//Create Time: 2018-03-17 13:00:44
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
bool hasp[N],hasn[N];
ll ans,temp_ans;
void output_ans(){
    cout<<__builtin_popcountll(ans)<<endl;
    while(ans){
        int t=__builtin_ctzll(ans);
        if(t<21)printf("%d ",1<<t);
        else printf("-%d ",1<<(t-21));
        ans^=1ll<<t;
    }
}
void add(const int& t,vector<int>&tn,bool &odd){
    if(!t)return;
    if(t&1)odd=1;
    if(tn.empty() || tn.back()<t) tn.pb(t);
}
void dfs(int p,const vector<int> &pn, const vector<int> &nn,bool odd){
    int mx=0;
    if(SZ(pn))chmax(mx,pn.back());
    if(SZ(nn))chmax(mx,nn.back());
    /*
    if(mx==0){
        OUT(p);
        cout<<bitset<20>(temp_ans)<<endl;
        cout<<bitset<20>(temp_ans>>21)<<endl;
        return;
    }
    */
    if(mx==1){
        if(SZ(pn))temp_ans|=(1ll<<p);
        if(SZ(nn))temp_ans|=(1ll<<(p+21));
        if(__builtin_popcountll(ans)>__builtin_popcountll(temp_ans))ans=temp_ans;
        if(SZ(pn))temp_ans^=(1ll<<p);
        if(SZ(nn))temp_ans^=(1ll<<(p+21));
        return;
    }

    bool new_odd=0;
    vector<int> npn,nnn;
    if(!odd){
        int t;
        for(int i:pn){
            t=i/2;
            add(t,npn,new_odd);
        }
        for(int i:nn){
            t=i/2;
            add(t,nnn,new_odd);
        }
        dfs(p+1,npn,nnn,new_odd);
    } else{
        int d=1,t;
        for(int i:pn){
            if(i&1) t=(i-d)/2;
            else t=i/2;
            add(t,npn,new_odd);
        }
        for(int i:nn){
            if(i&1) t=(i+d)/2;
            else t=i/2;
            add(t,nnn,new_odd);
        }
        temp_ans|=(1ll<<p);
        dfs(p+1,npn,nnn,new_odd);

        temp_ans^=(1ll<<p);
        new_odd=0;
        npn.clear();
        nnn.clear();
        d=-1;
        for(int i:pn){
            if(i&1) t=(i-d)/2;
            else t=i/2;
            add(t,npn,new_odd);
        }
        for(int i:nn){
            if(i&1)t=(i+d)/2;
            else t=i/2;
            add(t,nnn,new_odd);
        }
        temp_ans|=(1ll<<(21+p));
        dfs(p+1,npn,nnn,new_odd);
        temp_ans^=(1ll<<(21+p));
    }
}
int main(){
    int n;cin>>n;
    bool odd=0;
    rep(i,0,n){
        int t; scanf("%d",&t);
        if(t>0){
            hasp[t]=1;
            if(t&1)odd=1;
        } else if(t<0){
            hasn[-t]=1;
            if((-t)&1)odd=1;
        }
    }
    vector<int> pn,nn;
    rep(i,1,N-1){
        if(hasp[i])pn.pb(i);
        if(hasn[i])nn.pb(i);
    }
    temp_ans=0;
    ans=(1ll<<50)-1;
    if(SZ(pn) || SZ(nn)) dfs(0,pn,nn,odd);
    else ans=0;
    output_ans();
    return 0;
}
