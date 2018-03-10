//Create Time: 2018-03-09 16:17:03
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
const int N=(int)200009;
char st[N];
int main(){
    scanf("%s",st);
    string s(st);
    set<int> has[2];
    rep(i,0,SZ(s)){
        if(s[i]=='0')has[0].insert(i);
        else has[1].insert(i);
    }
    vector<vi > ans;
    vi tmp;
    set<int>::iterator it;
    int p,sta;
    while(1){
        if(SZ(has[0])==0)break;
        sta=0;
        p=*has[0].begin();
        has[0].erase(has[0].begin());
        tmp.pb(p);
        while(1){
            sta^=1;
            it=has[sta].upper_bound(p);
            if(it==has[sta].end())break;
            p=*it;
            tmp.pb(p);
            has[sta].erase(it);
        }
        if(sta==0) {
            puts("-1");
            return 0;
        }
        ans.pb(tmp);
        tmp.clear();
    }
    if(SZ(has[0])>0 || SZ(has[1])>0){
            puts("-1");
            return 0;
    }
    printf("%d\n",SZ(ans));
    for(auto &i: ans){
        printf("%d",SZ(i));
        for(int &j: i){
            printf(" %d",j+1);
        }
        puts("");
    }
    return 0;
}
