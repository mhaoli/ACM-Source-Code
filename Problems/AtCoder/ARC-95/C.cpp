//Create Time: 2018-04-14 23:03:43
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
long long powmod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
const int N=200009;
int n,an[N];
multiset<int> up;
multiset<int,greater<int> > down;
void upd(){
    while(SZ(up)<SZ(down)+1){
        int t=*down.begin();
        up.insert(t);
        down.erase(down.begin());
    }
    while(SZ(up)>SZ(down)+1){
        int t=*up.begin();
        down.insert(t);
        up.erase(up.begin());
    }
}
int main(){
    cin>>n;
    rep(i,0,n)scanf("%d",an+i);
    rep(i,1,n){
        up.insert(an[i]);
    }
    upd();
    printf("%d\n",*up.begin());
    rep(i,1,n){
        auto it=up.find(an[i]);
        if(up.end()==it){
            it=down.find(an[i]);
            down.erase(it);
        }else up.erase(it);
        
        if(an[i-1]>=*up.begin()) up.insert(an[i-1]);
        else down.insert(an[i-1]);
        upd();

        // for(int i:up)TST(i);
        // for(int j:down)TST(j);
        // puts("");

        printf("%d\n",*up.begin());
    }
    return 0;
}
