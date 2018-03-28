//Create Time: 2018-03-22 15:52:32
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
typedef unsigned long long ull;
const ull seed=257;
string sn[20010];
char s[(int)1e6+9];
int cnt[(int)1e6+9][28];
vector<int> pos[30];
ull pp[55];
struct oo{
    int st,ed,cn[27];
    ull hash;
    oo(){ clr(cn); }
    void calc(string &s){
        st=s[0]-'a';
        ed=s.back()-'a';
        clr(cn);
        for(char c:s){
            cn[c-'a']++;
        }
        calc_hash(cn);
    }
    void calc_hash(int*cnt){
        hash=0;
        rep(i,0,26)hash+=cnt[i]*pp[i];
    }
    void add(int p){
        hash+=pp[p];
        cn[p]+=1;
    }
    void minus(int p){
        hash-=pp[p];
        cn[p]-=1;
    }
    void output() {
        TST(char(st+'a'));TST(char(ed+'a'));OUT(hash);
        rep(i,0,26)cout<<cn[i]<<" ";
        puts("");
    }
};
bool operator==(const oo &a,const oo &b){
    if(a.hash!=b.hash)return 0;
    if(a.st!=b.st || a.ed!=b.ed)return 0;
    rep(i,0,26)if(a.cn[i]!=b.cn[i])return 0;
    return 1;
}
bool operator<(const oo &a,const oo &b){
    if(a.hash!=b.hash)return a.hash<b.hash;
    if(a.st!=b.st)return a.st<b.st;
    if(a.ed!=b.ed)return a.ed<b.ed;
    rep(i,0,26)if(a.cn[i]!=b.cn[i])return a.cn[i]<b.cn[i];
    return 0;
}
bool cmp(const string &a,const string &b){
    if(SZ(a)!=SZ(b))return SZ(a)<SZ(b);
    if(a[0]!=b[0])return a[0]<b[0];
    return a.back()<b.back();
}
void init(char *s,int n){
    rep(i,0,n){
        pos[s[i]-'a'].pb(i);
    }
    rep(i,0,26)cnt[0][i]=0;
    cnt[0][s[0]-'a']++;
    rep(i,1,n){
        rep(j,0,26)cnt[i][j]=cnt[i-1][j];
        cnt[i][s[i]-'a']++;
    }
}
int gao(multiset<oo> &has,char *s,int n,int l){
    oo tmp;
    int before=SZ(has);
    rep(i,0,n-l+1){
        tmp.st=s[i]-'a';
        tmp.ed=s[i+l-1]-'a';
        if(!i){
            tmp.hash=0;
            rep(j,0,l)tmp.add(s[j]-'a');
            // rep(i,0,26)tmp.hash+=cnt[l-1][i]*pp[i];
        }
        else {
            tmp.minus(s[i-1]-'a');
            tmp.add(s[i+l-1]-'a');
        }
        // OUT((has.find(tmp)==has.end()));
        has.erase(tmp);
    }
    return before-SZ(has);
}
int main(){
    rep(i,0,30)pp[i]=i?pp[i-1]*seed:1;

    int _,cas=0;scanf("%d",&_);
    char s1[5],s2[5];
    while(_--){
        int l;scanf("%d",&l);
        rep(i,0,l)cin>>sn[i];
        scanf("%s%s",s1,s2);
        int a,b,c,d,n;
        ll t,x1,x2;
        cin>>n>>a>>b>>c>>d;
        s[0]=s1[0];s[1]=s2[0];
        x1=s1[0];x2=s2[0];
        rep(i,2,n){
            t=(a*x2+b*x1+c)%d;
            s[i]=97+(t%26);
            x1=x2;x2=t;
        }
        s[n]=0;
        // puts(s);
        
        int ans=0;
        init(s,n);
        sort(sn,sn+l,cmp);
        oo tmp;
        multiset<oo> has;
        rep(i,0,l){
            if(i && SZ(sn[i])!=SZ(sn[i-1])){
                ans+=gao(has,s,n,SZ(sn[i-1]));
                has.clear();
            }
            tmp.calc(sn[i]);
            has.insert(tmp);
        }
        if(SZ(has)) ans+=gao(has,s,n,SZ(sn[l-1]));
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
