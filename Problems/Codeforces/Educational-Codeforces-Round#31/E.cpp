//Create Time: 2017-11-28 15:49:15
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
int an[2][1<<14],now[1<<14],f[1<<15],new_idx[1<<15];
char s[1<<12];
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
int get_int(char c){
    if('0'<=c && c<='9')return c-'0';
    return 10+c-'A';
}
void gao(char c,int *x){
    x+=3;
    int t=get_int(c);
    rep(i,0,4){
        *x=t&1;
        t>>=1;
        x--;
    }
}
int main(){
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    int pos=0,idx,t1,t2,t;
    memset(an,-1,sizeof an);
    map<int,int> has;
    map<int,int>::iterator it;
    // set<int> has;
    rep(i,0,n){
        scanf("%s",s);
        if(strlen(s)!=(m/4)) assert(false);
        rep(j,0,m/4){
            gao(s[j],now+j*4);
        }

        // rep(j,0,m){
            // TST(now[j]);
        // }
        // puts("\n");

        idx=m;
        rep(j,0,m){
            if(now[j]==0){
                an[pos][j]=-1;
            }else{
                ++ans;
                an[pos][j]=idx++;
            }
        }

        // rep(j,0,m){
            // TST(an[pos][j]);
        // }
        // puts("\n");

        rep(j,0,m*2)f[j]=j;

        rep(j,0,m){
            if(an[pos^1][j]>=0&&an[pos][j]>=0){
                t1=find(an[pos^1][j]);
                t2=find(an[pos][j]);
                if(t1!=t2){
                    f[t1]=t2;
                    --ans;
                }
            }
            if(j<m-1&&an[pos][j]>=0&&an[pos][j+1]>=0){
                t1=find(an[pos][j]);
                t2=find(an[pos][j+1]);
                if(t1!=t2){
                    f[t1]=t2;
                    --ans;
                }
            }
        }

        // rep(j,0,m){
            // if(an[pos][j]>=0){
                // an[pos][j]=find(an[pos][j]);
            // }
            // TST(an[pos][j]);
        // }
        // puts("\n");

        idx=0;
        memset(new_idx,-1,sizeof new_idx);
        rep(j,0,m)if(an[pos][j]>=0){
            an[pos][j]=find(an[pos][j]);
            if(new_idx[an[pos][j]]==-1){
                new_idx[an[pos][j]]=idx++;
            }
            an[pos][j]=new_idx[an[pos][j]];
        }
        pos^=1;
    }
    cout<<ans<<endl;
    return 0;
}
