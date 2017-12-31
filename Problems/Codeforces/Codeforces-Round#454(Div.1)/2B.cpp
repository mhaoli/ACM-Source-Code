//Create Time: 2017-12-23 22:27:27
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
char s[99][99], ts[10];
void fil_3(int x,int y,char *t){
    rep(i,0,3){
        s[x][y+i]=t[0];
        ++t;
    }
}
void input(){
    rep(i,0,3){
        rep(j,0,3){
            rep(k,0,3){
                scanf("%s",ts);
                fil_3(i*3+j,k*3,ts);
            }
        }
    }
}
bool has_empty(int x,int y){
    x*=3;
    y*=3;
    rep(i,x,x+3)rep(j,y,y+3)if(s[i][j]=='.')return 1;
    return 0;
}
void fil(int x,int y){
    x*=3;
    y*=3;
    rep(i,x,x+3)rep(j,y,y+3)if(s[i][j]=='.')s[i][j]='!';
}
int main(){
    input();
    // rep(i,0,9){
        // rep(j,0,9)printf("%c",s[i][j]);
        // puts("");
    // }
    int x,y;scanf("%d%d",&x,&y);--x;--y;
    x%=3;y%=3;
    // OUT(x);OUT(y);
    if(has_empty(x,y)){
        fil(x,y);
    }else{
        rep(i,0,3)rep(j,0,3){
            if(i==x&&j==y)continue;
            fil(i,j);
        }
    }
    rep(i,0,3){
        rep(j,i*3,i*3+3){
            rep(k,0,3){
                rep(t,k*3,k*3+3){
                    printf("%c",s[j][t]);
                }
                if(k!=2)printf(" ");
            }
            puts("");
        }
        if(i!=2)puts("");
    }
    return 0;
}
