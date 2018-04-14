//Create Time: 2018-04-07 13:25:48
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
const int N=(int)1e5+9;
int an[2][N],bn[N];
int top[2];
int main(){
    int _,cas=0;cin>>_;
    while(_--){
        int n;scanf("%d",&n);
        top[0]=top[1]=0;
        rep(i,0,n){
            int t=i&1;
            scanf("%d",&an[t][top[t]++]);
        }
        sort(an[0],an[0]+top[0]);
        sort(an[1],an[1]+top[1]);
        for(int i=0,j=0,k=0;i<n;++i){
            if(i&1){
                bn[i]=an[1][k++];
            } else {
                bn[i]=an[0][j++];
            }
        }
        // rep(i,0,n)TST(bn[i]);puts("");
        int pos=-1;
        rep(i,0,n-1)if(bn[i]>bn[i+1]){
            pos=i;
            break;
        }
        printf("Case #%d: ",++cas);
        if(~pos)printf("%d\n",pos);
        else puts("OK");
    }
    return 0;
}
