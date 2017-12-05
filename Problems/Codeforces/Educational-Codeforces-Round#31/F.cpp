//Create Time: 2017-12-05 11:48:52
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
namespace costflow {
        typedef int Tf;
        typedef int Tc;
        const static int Max_N = 111;  //max node number
        const static int Max_E = 3333;  //max edge number
        const static Tc Max_C = 5e8;  //max cost
        //3 * Max_C < max_int
        //template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
        template <class T> int sgn(T x) { return x == 0 ? 0 : x < 0 ? -1 : 1; }

        struct Edge{
                int v;
                Edge *nxt;
                Tf f, cap;
                Tc c;
                void add(int _v, Tf cp, Tc _c, Edge*n){
                        v = _v; cap = cp; c = _c; nxt = n; f = 0;
                }
                Tf flow(){ return cap - f; }
        };

        Edge *head[Max_N], e[Max_E], *bat, *pre[Max_N];
        int vis[Max_N];
        int n, m, s, t;
        Tc dis[Max_N];
        void add(int u, int v, Tf f, Tc c){
                // cout<<"add edge:"<<u<<" to "<<v<<" cost:"<<c<<endl;
                bat->add(v, f, c, head[u]); head[u] = bat++;
                bat->add(u, 0, -c, head[v]); head[v] = bat++;
        }
        void init(){
                bat = e; m = 0; memset(head, 0, sizeof head);
        }
        int spfa(){
                for (int i = 0; i < n; ++i) dis[i] = Max_C; dis[s] = 0;
                memset(vis, 0, sizeof(vis)); vis[s] = 1;
                memset(pre, 0, sizeof(pre));
                queue<int> q; q.push(s); 
                int u, v;
                Edge *p;
                while (!q.empty()){
                        p = head[u=q.front()]; q.pop();
                        for (; p; p = p->nxt){
                                v = p->v;
                                if (sgn(dis[v] - dis[u] - p->c) > 0 && sgn(p->flow()) > 0){
                                        dis[v] = dis[u] + p->c;
                                        pre[v] = p;
                                        if (!vis[v]) vis[v] = 1, q.push(v);
                                }   
                        }
                        vis[u] = 0; 
                }
                return sgn(Max_C - dis[t]) > 0;  
        }
        pair<Tf, Tc> solve(int _n, int _s, int _t){
                n = _n; s = _s; t = _t;
                Tc cost = 0; Tf flow = 0;
                while (spfa()){
                        Tf f = Max_C;
                        for (Edge *p = pre[t]; p; p = pre[e[(p-e)^1].v]) chmin(f, p->flow());
                        flow += f;
                        cost += f * dis[t];
                        for (Edge *p = pre[t]; p; p = pre[e[(p-e)^1].v])
                                p->f += f, e[(p-e)^1].f -= f;     
                }
                return make_pair(flow, cost);
        }
}
int an[111],cnt[111];
int main(){
    int n;scanf("%d",&n);
    string s;cin>>s;
    rep(i,0,n)scanf("%d",an+i);
    rep(i,0,n)cnt[s[i]-'a']++;
    costflow::init();
    int st=0,tg=1;
    rep(i,0,26){
        costflow::add(st,2+i,cnt[i],0);
    }
    rep(i,0,26){
        rep(j,0,n/2){
            int c=0;
            if(i+'a'==s[j])c=an[j];
            if(i+'a'==s[n-1-j])chmax(c,an[n-1-j]);
            // if(c) cout<<char(i+'a')<<" to ("<<s[j]<<","<<s[n-1-j]<<") cost:"<<c<<endl;
            costflow::add(2+i,28+j,1,-c);
        }
    }
    rep(j,0,n/2){
        costflow::add(28+j,tg,2,0);
    }
    // puts("run");
    cout<<-costflow::solve(28+n/2,st,tg).y<<endl;
    return 0;
}
