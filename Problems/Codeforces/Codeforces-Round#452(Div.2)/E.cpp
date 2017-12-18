//Create Time: 2017-12-17 15:54:45
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
typedef pair<int,pair<int, int> > piii;
const int N=(int)2e5+9;
// pos, x, len
set<piii> pos;
// -len, pos, x
set<piii> len;
int an[N];
void add(int p, int x,int l){
    pos.insert(piii(p,pii(x,l)));
    len.insert(piii(-l,pii(p,x)));
}
void remove(piii a){
    int p=a.x,x=a.y.x,l=a.y.y;
    pos.erase(a);
    len.erase(piii(-l,pii(p,x)));
}
void step(){
    piii a=*len.begin();
    int p=a.y.x;
    // TST(p); TST(a.y.y); OUT(-a.x);
    auto it=pos.upper_bound(piii(p,pii(-1,-1)));
    auto nxt=it;++nxt;
    auto pre=it;
    bool fg=0;
    if(it!=pos.begin() && nxt!=pos.end()){
        --pre;
        if((*pre).y.x==(*nxt).y.x){
            fg=1;
        }
    }
    remove(*it);
    if(fg){
        int p=(*pre).x, x=(*pre).y.x, l=(*pre).y.y+(*nxt).y.y;
        remove(*pre);
        remove(*nxt);
        add(p,x,l);
    }
}
int main(){
    int n;scanf("%d",&n);
    rep(i,0,n)scanf("%d",an+i);
    int last=-1,cnt=0,last_pos=-1;
    rep(i,0,n){
        if(an[i]!=last){
            if(~last_pos){
                add(last_pos,an[i-1],cnt);
            }
            cnt=1;last=an[i];last_pos=i;
        }else{
            ++cnt;
        }
    }
    add(last_pos,an[n-1],cnt);
    int ans=0;
    while(SZ(len)){
        step();
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}
