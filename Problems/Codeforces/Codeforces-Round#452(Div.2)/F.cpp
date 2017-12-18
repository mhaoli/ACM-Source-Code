//Create Time: 2017-12-17 16:31:52
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
// #define DEBUG
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
const int M=62;
namespace Treap{
    const int Max_N = N;
    //int ran(){
        //static unsigned ranx = 654123789;
        //return ranx += ranx<<2|1;
    //}
    bool random (int a, int b){
        return rand () % (a + b) < a;
    }
    struct Node;
    typedef std::pair<Node*, Node*> Droot;
    struct Node{
        Node *ch[2];
        int sz, v;
        void relax ();
        Node* upd();
        int get_rank(int k);
        Droot split (int k);
        Node* remove_by_val(int _v);
        //int get_rank (int x); //查询key <= x的有多少个
    }Tnull, *null=&Tnull, mem[Max_N<<1], *bat, *rt;
    Node *Node::upd (){
        if (this != null){
            sz = ch[0]->sz + ch[1]->sz + 1;
        }
        return this;
    }
    void Node::relax (){
    }
    Node *merge (Node *x, Node *y){  //max(x) <= min (y)
        if (!x->sz) return y;
        if (!y->sz) return x;
        if (random (x->sz, y->sz)){
            x->relax ();
            x->ch[1] = merge (x->ch[1], y);
            return x->upd ();
        } else{
            y->relax ();
            y->ch[0] = merge (x, y->ch[0]);
            return y->upd ();
        }
    }
    Droot Node::split (int k){   //max (first) <= min (second)
        if (!sz) return std::make_pair (null, null);
        relax ();
        if (k <= ch[0]->sz){
            Droot ret = ch[0]->split (k);
            ch[0] = ret.second;
            ret.second = this->upd ();
            return ret;
        } else{
            Droot ret = ch[1]->split (k - ch[0]->sz - 1);
            ch[1] = ret.first;
            ret.first = this->upd ();
            return ret;
        }
    }
    int Node::get_rank (int x){
        if (!sz) return 0;
        return v <= x ? ch[1]->get_rank (x) + ch[0]->sz + 1 : ch[0]->get_rank (x);
    }
    /*
     * slow version, at least 3 times slower
    Node* find_kth (Node *&r, int k){ //查找第k小, index 1-based
        Droot t1 = r->split (k-1), t2 = t1.second->split (1);
        Node *ret = t2.first;
        r = merge (merge (t1.first, t2.first), t2.second);
        return ret;
    }
    */
    Node* find_kth(Node *r, int K){ //查找第k小, index 1-based
        if(K > r->sz) return null;
        while(1){
            if(r->ch[0]->sz >= K) r = r->ch[0];
            else if(r->ch[0]->sz + 1 < K) {
                K -= r->ch[0]->sz + 1;
                r = r->ch[1];
            } else return r;
        }
    }
    Node* Node::remove_by_val(int _v){  //_v should be in Treap
        if(v == _v){
            return merge(ch[0], ch[1]);
        } else if(v > _v){
            ch[0] = ch[0]->remove_by_val(_v);
        } else {
            ch[1] = ch[1]->remove_by_val(_v);
        }
        return upd();
    }
    /*****************/
    Node *newnod (int v){
        Node *x = bat++;
        x->sz = 1;
        x->v = v;
        x->ch[0] = x->ch[1] = null;
        return x;
    }
    Node *stk[Max_N];
    void build (int *a, int n){
        //0...n
        Node *x, *last;
        int top = 0;
        for (int i = 0; i < n; ++i){
            x = newnod (a[i]);
            last = null;
            while (top && !random (stk[top-1]->sz, x->sz))
                last = stk[--top]->upd ();
            if (top) stk[top-1]->ch[1] = x;
            x->ch[0] = last;
            stk[top++] = x;
        }
        while (top) stk[--top]-> upd ();
        rt = stk[0];
    }
    void init (){
        srand (192737);
        bat = mem; rt = null;
        null->ch[0] = null->ch[1] = null;
    }
    int find_v(int k){
        return find_kth(rt, k)->v;
    }
    void remove(int v){
        rt = rt->remove_by_val(v);
    }
}

char s[N],ans[N];
int an[N],bn[N];
bool fg[N];
set<int> has[M+10];
int gc(char c){
    if(c>='a'&&c<='z')return c-'a';
    if(c>='A'&&c<='Z')return c-'A'+26;
    return c-'0'+52;
}
void remove(int l,int r,int v){
    // clock_t st;
    // double tt=0;
    l = Treap::find_v(l+1);
    r = Treap::find_v(r+1);
    // OUT(l); OUT(r);
    auto it=has[v].lower_bound(l),nxt=it;
    while(it!=has[v].end()&&(*it)<=r){
        // st=clock();
        fg[*it]=1;
        Treap::remove(*it);
        // tt+=clock()-st;
        nxt=it;++nxt;
        // printf("del char:%c\n",s[*it]);
        has[v].erase(it);
        it=nxt;
    }
    // printf("Treap time %f\n",tt/(1000000.0));
}
void output(int n){
    int ans_cnt=0;
    rep(i,0,n)if(!fg[i])ans[ans_cnt++]=s[i];
    ans[ans_cnt]=0;
    puts(ans);
}
int main(){
    // clock_t st;
    // st=clock();
    int n,m;scanf("%d%d%s",&n,&m,s);
    rep(i,0,n){
        an[i]=gc(s[i]);
        has[an[i]].insert(i);
    }

    rep(i,0,n)bn[i]=i;
    Treap::init();
    Treap::build(bn,n);
    // printf("time %f\n",(clock()-st)/(1000000.0));
    char c[5];
    int l,r;
    while(m--){
        rd(l);rd(r);
        scanf("%s",c);
        // printf("%d %d %c\n",l,r,c[0]);
        // st=clock();
        remove(--l,--r,gc(c[0]));
        // printf("%d %d time %f\n",l,r,(clock()-st)/(1000000.0));
    }
    // printf("time %f\n",(clock()-st)/(1000000.0));
    output(n);
    // printf("time %f\n",(clock()-st)/(1000000.0));
    return 0;
}
