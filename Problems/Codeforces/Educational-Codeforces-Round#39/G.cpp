//Create Time: 2018-04-03 12:24:09
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
const int N=(int)2e5+9;
int tmp[N];
vector<int> an;
int stk[N],f[N]; // len: top,m
int main(){
    int n;scanf("%d",&n);
    an.resize(n,0);
    rep(i,0,n){
        scanf("%d",&an[i]);
        an[i]-=i;
    }
    int top=0,m=0,last=-1;
    f[m++]=-(1<<30);
    rep(i,0,n){
        // TST(i);OUT(last);
        int pos;
        if(i){
            pos=upper_bound(f,f+m,an[i]+1)-f;
            // TST(i);OUT(pos);
            if(pos==m){
                f[m]=an[i]+1;
                ++m;
            } else{
                chmin(f[pos],an[i]+1);
            }
        }
        // TST(i);TST(last);OUT(m);
        // rep(j,0,m)TST(f[j]);puts("");

        if(last!=-1){
            if(last+1>=m){
                f[last+1]=stk[last];
                ++m;
            }else{
                chmin(f[last+1],stk[last]);
            }
        }
        // TST(i);OUT(m);
        // rep(j,0,m)TST(f[j]);puts("");
        // puts("----------------------------------------------------------------------------------------------------------");
// 
        last=-1;
        pos=upper_bound(stk,stk+top,an[i])-stk;
        if(pos==top){
            stk[top]=an[i];
            last=top;
            ++top;
        } else{
            if(chmin(stk[pos],an[i])){
                last=pos;
            }
        }
    }
    // OUT(m);
    cout<<n-max(m,top)<<endl;
    return 0;
}
