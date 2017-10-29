//Create Time: 2017-10-27 14:36:00
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
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define debug
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<pair<int,pii > > viii;
/****head****/
#define right right___t
typedef pair<ll,pii > plii;
const int Max_N = (int)6e5 + 9;
struct DS{
    set<plii> has;
    void init(){
        has.clear();
    }
    void erase(ll c,int l,int r){
        has.erase(plii(-c,pii(l,r)));
    }
    void insert(ll c,int l,int r){
        has.insert(plii(-c,pii(l,r)));
    }
    ll get_max(){
        if(has.empty()) return 0;
        return -(has.begin()->x);
    }
}ds;

//initial: init()
struct RMQ{
    int mx[Max_N][30], lg2[Max_N];
    void init (int n, int *a){ //a: 0...n-1
        for (int i = 0; i < n; ++ i){
            mx[i][0] = a[i];
            lg2[i] = (!i ? -1 : lg2[i>>1] + 1);
        }
        lg2[n] = lg2[n>>1] + 1;
        for (int j = 1, l = 2; l <= n; ++ j, l <<= 1){
            for (int i = 0; i + l - 1 < n; ++ i)
                mx[i][j] = std::min(mx[i][j-1], mx[i+(l>>1)][j-1]);
        }
    }
    int query(int a, int b) { //[a, b]
        int k = lg2[b - a + 1];
        return std::min(mx[a][k], mx[b-(1<<k)+1][k]);
    }
};

struct SA{
    //array index form 0 to n-1
    //r[i] != 0 should be guaranteed
    int n;
    int sa[Max_N];       //sa[i] = j: suffix(j)'s rank = i
    int rank[Max_N];     //rank[i] = j: suffix(i)'s rank = j
    int h[Max_N];        //hei[i] = LCP(suffix(sa[i-1], sa[i]))
    int wa[Max_N], wb[Max_N], wv[Max_N], wt[Max_N];

    RMQ rmq;

    int cmp(int *r, int a, int b, int l){
        return r[a]==r[b] && r[a+l]==r[b+l];
    }

    //1 <= r[i] < m, i from 0 to n-1
    void init(int *r, int n, int m)
    {
        r[n] = 0; this -> n = n ++;

        int i, j, p, *x=wa, *y=wb, *t;
        for (i = 0; i < m; ++ i) wt[i] = 0;
        for (i = 0; i < n; ++ i) wt[x[i]=r[i]] ++;
        for (i = 1; i < m; ++ i) wt[i] += wt[i-1];
        for (i = n-1; i >= 0; -- i) sa[--wt[x[i]]] = i;
        for(j = 1, p = 1; p < n; j *= 2, m = p)
        {
            for (p = 0, i = n-j; i < n; i++) y[p++] = i;
            for (i = 0; i < n; ++ i) if (sa[i] >= j) y[p++] = sa[i] - j;
            for (i = 0; i < n; ++ i) wv[i] = x[y[i]];
            for (i = 0; i < m; ++ i) wt[i] = 0;
            for (i = 0; i < n; ++ i) wt[wv[i]] ++;
            for (i = 1; i < m; ++ i) wt[i] += wt[i-1];
            for (i = n-1; i >= 0; -- i) sa[--wt[wv[i]]] = y[i];
            for (t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i < n; i++)
                x[sa[i]] = cmp (y, sa[i-1], sa[i], j) ? p-1 : p++;
        }
        calhei(r);
        return;
    }

    void calhei(int *r){
        int i, j, k = 0;
        for (i = 1; i <= n; ++ i) rank[sa[i]] = i;
        for (i = 0; i < n; h[rank[i++]] = k)
            for(k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);

        for(int i = 0; i < n; ++i) {
            sa[i] = sa[i+1];
            h[i] = h[i+1];
            rank[i]--;
        }
        rmq.init(n, h);
        return;
    }

    int lcp(int a, int b){
        if(a == b) return n - a;
        a = rank[a]; b = rank[b];
        if(a > b) std::swap(a, b);
        return rmq.query(a+1, b);
    }
}sa;
ll ans;
int L;
pii bn[Max_N];
int lens[Max_N], an[Max_N], cost[Max_N], suffix_cost[Max_N], right[Max_N];
int len_per_suffix[Max_N];
ll suffix_cost_pre_sum[Max_N];
char s[Max_N];
int get_len(int p){
    return len_per_suffix[sa.sa[p]];
}
ll get_cost_sum(int l, int r){
    if(l) return suffix_cost_pre_sum[r]-suffix_cost_pre_sum[l-1];
    return suffix_cost_pre_sum[r];
}
void erase(int l,int r,set<pii> &pos){
    pos.erase(pii(l,r));
    ds.erase(get_cost_sum(l,r),l,r);
}
void insert(int l,int r,set<pii> &pos){
    if(l==r){
        bool flag=1;
        int leng=get_len(l);
        if(l && leng==sa.h[l]) flag=0;
        if(l<L-1 && leng==sa.h[l+1]) flag=0;
        if(flag){
            chmax(ans,1ll*leng*suffix_cost[l]);
        }
    }else{
        pos.insert(pii(l,r));
        ds.insert(get_cost_sum(l,r),l,r);
    }
}
void partition(int l,int r,int m,set<pii> &pos){
    erase(l,r,pos);
    insert(l,m-1,pos); insert(m,r,pos);
}
int main(){
    int n; cin>>n;
    L=0;
    rep(i,0,n){
        scanf("%s",s);
        int l=strlen(s);
        lens[i]=l;
        rep(j,0,l){
            an[L+j]=s[j]-'a'+1;
            len_per_suffix[L+j]=l-j;
        }
        an[L+l]=27+i;
        len_per_suffix[L+l]=0;
        L+=l+1;
    }
    rep(i,0,n){
        scanf("%d",cost+i);
    }

    sa.init(an, L, 27+n);

    // calc cost for every suffix
    for(int idx=0,i=0;i<n;++i){
        rep(j,0,lens[i]){
            suffix_cost[sa.rank[idx++]]=cost[i];
        }
        suffix_cost[sa.rank[idx++]]=0;
    }
    suffix_cost_pre_sum[0] = suffix_cost[0];
    rep(i,1,L) suffix_cost_pre_sum[i]=suffix_cost_pre_sum[i-1]+suffix_cost[i];

    rep(i,1,L) bn[i-1]=pii(sa.h[i],i);
    sort(bn,bn+L-1);

    ans = 0;
    ds.init();
    set<pii> pos;
    insert(0,L-1,pos);
    int last=-1;
    rep(i,0,L-1){
        if(bn[i].x!=last){
            chmax(ans,1ll*bn[i].x*ds.get_max());
            last=bn[i].x;
        }
        auto p=--(pos.upper_bound(pii(bn[i].y,-1)));
        int l=p->x,r=p->y;
        partition(l,r,bn[i].y,pos);
    }

    cout<<ans<<endl;
    return 0;
}
