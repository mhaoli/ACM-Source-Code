//Create Time: 2018-03-10 23:56:19
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
ll sum[N],pref[N];
int dif[N],vn[N],tn[N];
int day;
ll lef;
int main(){
    int n;
    scanf("%d",&n);
    rep(i,0,n)scanf("%d",vn+i);
    rep(i,0,n)scanf("%d",tn+i);
    pref[0]=tn[0];
    rep(i,1,n)pref[i]=pref[i-1]+tn[i];
    ll cnt=0,ps=0;
    bool fg=0;
    rep(i,0,n){
        if(vn[i]){
            cnt++;
            day=lower_bound(pref,pref+n,vn[i]+ps)-pref;
            if(day<n){
                dif[day]++;
                if(day==0)lef=vn[i];
                else lef=vn[i]+ps-pref[day-1];
                sum[day]+=lef;
            }
        }
        cnt-=dif[i];
        if(fg)printf(" ");
        fg=1;
        printf("%lld",sum[i]+cnt*tn[i]);
        ps+=tn[i];
    }
    puts("");
    return 0;
}
