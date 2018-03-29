//Create Time: 2018-03-11 00:23:34
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
const int N=(int)3e5+9;
const int maxn = N*30;
const int maxs = 2;
struct nod{
    nod *ch[maxs+5];
    int v,sz,val;
    nod *go (int c);
}*bat, memo[maxn],*rt;
void newnod (nod *&o){
    o=bat++; clr(o->ch); o->v=0, o->sz=0;
}
void init (){
    bat = memo; newnod(rt);
}
nod *nod::go (int c){
    if (ch[c] == 0) ch[c]=bat++, clr(ch[c]->ch), ch[c]->v=0, ch[c]->sz=0;
    return ch[c];
}
void ins(int val, int t){
    nod *x=rt;
    x->sz+=t;
    per(i,30,0){
        x=x->go((val>>i)&1);
        x->sz+=t;
    }
    x->v+=t;
    x->val=val;
}
int find(int v){
    nod *x=rt;
    int t;
    per(i,30,0){
        assert(x!=0);
        assert(x->ch[0] != 0 || x->ch[1] != 0);
        t=(v>>i)&1;
        if(x->ch[t]!=0 && x->ch[t]->sz>0){
            x=x->ch[t];
        } else{
            x=x->ch[t^1];
        }
    }
    return x->val;
}
int an[N];
int main(){
    init();
    int n;
    scanf("%d",&n);
    rep(i,0,n)scanf("%d",an+i);
    int t;
    rep(i,0,n){
        scanf("%d",&t);
        ins(t,1);
    }
    bool fg=0;
    rep(i,0,n){
        t=find(an[i]);
        ins(t,-1);
        if(fg)printf(" ");
        fg=1;
        printf("%d",t^an[i]);
    }
    puts("");
    return 0;
}
