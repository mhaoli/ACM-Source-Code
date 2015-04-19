/*
 * Author:  Plumrain
 * Created Time:  2014/8/25 16:25:37
 * File Name: LA5792.cpp
 */
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

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define two(x) (1<<(x))
#define twol(x) (1ll<<(x))
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = (int)1e5 + 5;
const int maxs = 26;

struct Node{
    Node *ch[maxs];
    Node *go (int w);
}*rt0, *rt1;

Node memo[maxn<<1], *bat;

void newnod (Node *&o){
    o = bat++; clr (o->ch, 0);
}

Node *Node::go (int w){
    if (!ch[w]) newnod (ch[w]);
    return ch[w];
}

void insert (Node *x, char *str){
    int n = strlen (str);
    rep (i, 0, n-1) x = x->go(str[i] - 'a');
}

int64 ans;
char str[maxn];
int num[30], single[30];

void dfs (Node *x){
    rep (i, 0, maxs-1) if (x->ch[i])
        ++ num[i], dfs (x->ch[i]);
}

void dfs2 (Node *x){
    rep (i, 0, maxs-1)
        if (x->ch[i]){
            dfs2 (x->ch[i]);
            if (x != rt0) ans += single[i];
        }
        else if (x != rt0) ans += num[i];
}

int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m;
    while (scanf ("%d%d", &n, &m), n + m){
        bat = memo;
        newnod (rt0);
        rep (i, 0, n-1){
            scanf ("%s", str);
            insert (rt0, str);
        }

        clr (single, 0);
        newnod (rt1);
        rep (i, 0, m-1){
            scanf ("%s", str);
            int tlen = strlen (str);
            reverse (str, str + tlen);
            single[str[0] - 'a'] = 1;
            insert (rt1, str);
        }

        clr (num, 0);
        dfs (rt1);
        ans = 0;
        dfs2 (rt0);
        printf ("%I64d\n", ans);
    }
    return 0;
}
