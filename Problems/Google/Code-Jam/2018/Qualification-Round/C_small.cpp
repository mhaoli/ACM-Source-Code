//Create Time: 2018-04-07 14:19:02
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
int dx[4]={ 0,1,0,-1 },dy[4]={1,0,-1,0};
bool bd[1002][1002];
struct pnt{
    int x,y;
    void out(){
        printf("(%d,%d)",x,y);
    }
};
pnt idx[11][11];
int main(){
    rep(i,1,6)rep(j,1,6)idx[i][j]=pnt{i,j};
    idx[1][1]=pnt{2,2};
    idx[5][4]=pnt{4,3};
    idx[5][1]=pnt{4,2};
    idx[1][4]=pnt{2,3};
    rep(i,2,4) {
        idx[1][i]=pnt{2,i};
        idx[5][i]=pnt{4,i};
    }
    rep(i,2,5) {
        idx[i][1]=pnt{i,2};
        idx[i][4]=pnt{i,3};
    }
    // rep(i,1,6){
        // rep(j,1,6){
            // idx[i][j].out();
            // printf(" ");
        // }
        // puts("");
    // }

    int _,cas=0;scanf("%d",&_);
    while(_--){
        rep(i,1,6)rep(j,1,5)bd[i][j]=0;
        int K;scanf("%d",&K);
        int x,y;
        bool ok=0;
        rep(i,1,6)rep(j,1,5){
            if(ok)break;
            while(!bd[i][j]){
                printf("%d %d\n",idx[i][j].x,idx[i][j].y);
                fflush(stdout);
                scanf("%d%d",&x,&y);
                if(x==0 && y==0){
                    ok=1;break;
                }
                if(x==-1 && y==-1){
                    assert(false);
                }
                bd[x][y]=1;
            }
        }
    }
    return 0;
}
