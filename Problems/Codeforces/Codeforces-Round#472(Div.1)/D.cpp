//Create Time: 2018-03-25 01:16:43
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
const int N=(int)1e5+9;
struct oo{
    ll x,y;
    oo():x(0),y(0){ }
    oo(ll _x,ll _y):x(_x),y(_y){ }
    void out(){
        printf("%f ",(x+0.0)/y);
    }
};
bool operator<(const oo&a,const oo&b){
    return a.x*b.y<a.y*b.x;
}
bool operator==(const oo&a,const oo&b){
    return a.x*b.y==a.y*b.x;
}
struct line{
    oo a,b;
    bool neg;
};
bool operator<(const line&a,const line&b){
    if(a.a==b.a)return b.b<a.b;
    return a.a<b.a;
}
line an[(int)1e5+9];
vector<oo> bn;
pii cn[N];
struct BIT{
        //index from 1 to n

#define lowbit(x) ((x)&(-x))
        const static int Max_N = 500005;
        int c[Max_N], n;

        void init(int _n){
            n=_n;
        }
        //an[x] += d;
        void add(int x, int d) {
                while(x <= n) c[x] += d, x += lowbit(x);
        }

        //return the sum of an[1], an[2]...an[x]
        int sum(int x) {
                int ret = 0;
                while(x > 0) ret += c[x], x -= lowbit(x);
                return ret;
        }

        int sum(int l, int r) {
                return l > r ? 0 : sum(r) - sum(l-1);
        }
}bit1,bit2;

int main(){
    int n,w;cin>>n>>w;
    oo tmp;
    rep(i,0,n){
        int x,v;scanf("%d%d",&x,&v);
        an[i].neg=x<0;
        x=abs(x);v=abs(v);
        an[i].a=oo(x,v+w);
        an[i].b=oo(x,v-w);
    }
    sort(an,an+n);
    // rep(i,0,n){
        // an[i].a.out();
        // an[i].b.out();
        // puts("");
    // }
    // puts("a");
    rep(i,0,n){
        bn.pb(an[i].a);
        bn.pb(an[i].b);
    }
    unq(bn);
    int m=SZ(bn);
    map<oo,int> ind;
    rep(i,0,SZ(bn))ind[bn[i]]=i+1;
    rep(i,0,n){
        cn[i]=pii(ind[an[i].a],ind[an[i].b]);
    }

    // rep(i,0,n){
        // TST(cn[i].x); OUT(cn[i].y);
    // }

    ll cnt=0;
    bit1.init(m);
    bit2.init(m);
    rep(i,0,n){
        if(an[i].neg){
            cnt+=bit1.sum(cn[i].y,m);
            cnt+=bit2.sum(cn[i].x,m);
            bit1.add(cn[i].y,1);
        } else{
            cnt+=bit2.sum(cn[i].y,m);
            cnt+=bit1.sum(cn[i].x,m);
            bit2.add(cn[i].y,1);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
