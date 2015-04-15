/*
 * Author:  Plumrain
 * Created Time:  2014/8/10 17:11:21
 * File Name: J.cpp
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
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
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
const int maxn = 30005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct edge{
    int a, b, r, c, id;
    bool operator<(const edge &a)const{
        return r == a.r ? c < a.c : r < a.r;
    }
    edge(){ }
    edge(int _a, int _b, int _r, int _c, int i) : a(_a), b(_b), r(_r), c(_c), id(i){ }
}an[maxn];

int f[maxn*5];
map<int, int> has;

int find (int x){
    return x == f[x] ? f[x] : f[x] = find (f[x]);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n; scanf ("%d", &n);
    int tot = 0;
    has.clear();
    repf (i, 0, n-1){
        int a, b, r, c;
        scanf ("%d%d%d%d", &a, &b, &r, &c);
        if (!has.count (a)) has[a] = tot++;
        if (!has.count (b)) has[b] = tot++;
        an[i] = edge(has[a], has[b], r, c, i);
    }

    sort (an, an+n);

    repf (i, 0, tot-1) f[i] = i;

    int64 ans = 0;
    repd (i, n-1, 0){
        int t1 = an[i].a, t2 = an[i].b;
        int f1 = find (t1), f2 = find (t2);
        if (f1 != f2) f[f1] = f2, ans += an[i].c;
    }
    cout << ans << endl;
    repf (i, 0, n-1){
        if (i) printf (" ");
        printf ("%d", an[i].id + 1);
    }
    puts ("");
    return 0;
}
