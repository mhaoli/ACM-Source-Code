//Create Time: 2017-12-26 11:42:50
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
const int N=100010;
int x[N],n,m;
int pos(int x,int y){
    return x*m+y;
}
int get_item(int x,int y,bool rev){
    if(!rev)return x*m+y;
    return y*n+x;
}
int main(){
    cin>>n>>m;
    if(n<=3&&m<=3){
        if(n==1&&m==1)puts("YES\n1");
        else if(n==3&m==3)puts("YES\n8 1 6\n3 5 7\n4 9 2");
        else puts("NO");
        return 0;
    }
    bool rev=0;
    if(m<=3){
        swap(n,m);
        rev=1;
    }
    rep(i,0,n){
        int t=1;
        rep(j,0,m){
            x[pos(i,j)]=get_item(i,t,rev);
            t+=2;
            if(t>=m)t=0;
        }
        if(i&1){
            if(m==4){
                swap(x[pos(i,0)],x[pos(i,3)]);
                swap(x[pos(i,1)],x[pos(i,2)]);
            }else{
                int tl=x[pos(i,m-1)];
                per(j,m,1)x[pos(i,j)]=x[pos(i,j-1)];
                x[pos(i,0)]=tl;
            }
        }
    }
    puts("YES");
    if(rev){
        rep(j,0,m){
            rep(i,0,n) printf("%d ",x[pos(i,j)]+1);
            puts("");
        }
    }else{
        rep(i,0,n){
            rep(j,0,m) printf("%d ",x[pos(i,j)]+1);
            puts("");
        }
    }
    return 0;
}
