//Create Time: 2018-03-18 14:08:18
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
const int N=20010;
int an[N],n;
ll sum[N];
double calc(double e){
    int l=0,r=n-1,mid,pos=n-1;
    while(l<=r){
        mid=(l+r)>>1;
        if(an[mid]>e){
            pos=mid;
            r=mid-1;
        } else l=mid+1;
    }
    return e*pos/n + (sum[pos]+0.0)/n;
}
int main(){
    int _,cas=0;scanf("%d",&_);
    while(_--){
        int K;
        scanf("%d%d",&n,&K);
        rep(i,0,n)scanf("%d",an+i);
        sort(an,an+n);
        sum[n-1]=an[n-1];
        per(i,n-1,0)sum[i]=sum[i+1]+an[i];
        // rep(i,0,n)TST(an[i]);puts("");
        // rep(i,0,n)TST(sum[i]);puts("");
        // OUT(K);
        double e=(sum[0]+0.0)/n;
        while(K--){
            e=calc(e);
            // cout<<e<<endl;
        }
        printf("Case #%d: %.8f\n",++cas,e);
    }
    return 0;
}
