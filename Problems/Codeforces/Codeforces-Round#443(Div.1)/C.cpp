//Create Time: 2017-11-10 10:42:48
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
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
int n,m;
struct oo {
    int l[11],r[11],num;
    void input(){
        rep(i,0,m){
            scanf("%d",l+i);
            r[i]=l[i];
        }
        num=1;
    }
    void update(const oo &t){
        rep(i,0,m){
            chmin(l[i],t.l[i]);
            chmax(r[i],t.r[i]);
        }
        num+=t.num;
    }
};
bool operator<(const oo &a, const oo &b){
    return a.l[0]<b.l[0];
}
set<oo> q;
bool is_ins(const oo &a,const oo &b){
    rep(i,0,m){
        if(a.l[i]<b.r[i]) return true;
    }
    return false;
}
void insert(oo temp){
    auto l = q.upper_bound(temp),r=l;
    if(l!=q.begin()){
        --l;
        while(1){
            if(is_ins(temp,*l)){
                temp.update(*l);
            }else break;
            auto it=l;
            if(l==q.begin()){
                q.erase(it);
                break;
            }
            --l;
            q.erase(it);
        }
    }
    while(r!=q.end()){
        if(is_ins(*r,temp)){
            temp.update(*r);
        }else break;
        auto it=r;
        ++r;
        q.erase(it);
    }
    q.insert(temp);
}
int calc(){
    auto it=q.end(); --it;
    return it->num;
}
int main(){
    cin>>n>>m;
    oo temp;
    rep(i,0,n){
        temp.input();
        insert(temp);
        printf("%d\n",calc());
    }
    return 0;
}
