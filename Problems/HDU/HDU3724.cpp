/*
 * Author:  Plumrain
 * Created Time:  2014/8/29 14:15:23
 * File Name: E.cpp
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
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
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

const int maxs = 26;
const int maxn = 300005;

struct nod{
    nod *ch[maxs];
    int v;
    nod *go (int c);
}*bat;

nod memo[maxn], *rt;

void newnod (nod *&o){
    o = bat ++; o->v = 0; clr (o->ch, 0);
}

nod *nod::go (int c){
    if (ch[c] == 0) newnod (ch[c]);
    return ch[c];
}

void init (nod *&rt){
    bat = memo; newnod (rt);
}

void insert (char *s, const int &n){
    nod *x = rt; ++ x->v;
    rep (i, 0, n-1) x = x->go (s[i] - 'a'), ++ x->v;
}

double dig[10];
char str[33];

void calc (int &t){
    scanf ("%lf", &dig[0]);
    double mi = dig[0];
    rep (i, 1, 7){
        scanf ("%lf", &dig[i]);
        chmin (mi, dig[i]);
    }

    t = 0;
    rep (i, 0, 7){
        if (dig[i] < 1.5 * mi) t <<= 1;
        else t = t << 1 | 1;
    }
}

/*
void debug (nod *x){
    cout << x->v << " ";
    out (x - memo);
    rep (i, 0, maxs-1) if (x->ch[i]) tst (i), tst (x->ch[i] - memo);
    cout << endl;
    rep (i, 0, maxs-1) if (x->ch[i]) debug (x->ch[i]);
}
*/

int main()
{
    //freopen("3724.in","r",stdin);
    //freopen("wa.out","w",stdout);
    nod *x;
    bool flag;
    int n, m, len, sum, k, tc;
    while (scanf ("%d%d", &n, &m) != EOF){
        init (rt);
        gets (str);
        rep (i, 0, n-1){
            //scanf ("%s", str);
            gets (str);
            len = strlen (str);
            insert (str, len);
        }
        
        sum = 0;
        while (m--){
            scanf ("%d", &k);
            x = rt;
            flag = 0;
            while (k--){
                calc (tc); tc = tc - 'a';
                if (!flag && x->ch[tc]) x = x->ch[tc];
                else flag = 1;
            }
            if (!flag) sum += x->v;
        }
        printf ("%d\n", sum);
    }
    return 0;
}
