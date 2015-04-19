/*
 * Author:  Plumrain
 * Created Time:  2014/8/4 16:01:47
 * File Name: BZOJ-1588.cpp
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
//const int inf = 2147483647 / 2;
const int inf = (int)1e6;
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct nod{
    int a[2], n;
    int q(int x){
        if (x == n) return -1;
        return x < n ? 0 : 1;
    }
    nod(){
        a[0] = a[1] = -1;
    }
};

struct Splay{
    const static int maxn = 40005;

    int r, tot;
    nod an[maxn];
    void init (){
        tot = 0; r = -1;
    }
    void newnod (int &r, int x){
        an[r=tot++].n = x;
    }
    bool insert (int &t, int x){
        if (t == -1){
            newnod (t, x); splay (r, x); return 1;
        }
        int q = an[t].q(x);
        if(q == -1){
            splay (t, x); return 0;
        }
        return insert (an[t].a[q], x);
    }
    int find (int t, int x){
        while (~an[t].a[x]) t = an[t].a[x];
        return an[t].n;
    }
    void rotate (int &t, int q){
        int k = an[t].a[q];
        an[t].a[q] = an[k].a[q^1];
        an[k].a[q^1] = t;
        t = k;
    }
    void splay (int &t, int x){
        int q = an[t].q(x);
        if (q == -1) return;
        int p = an[t].a[q], q2 = an[p].q(x);
        if (~q2){
            splay (an[p].a[q2], x);
            if (q == q2) rotate (t, q);
            else rotate (an[t].a[q], q2);
        }
        rotate (t, q);
    }
}gao;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, ans; scanf ("%d%d", &n, &ans);
    gao.init ();
    int &r = gao.r;
    //gao.newnod (r, ans);
    gao.insert (r, ans);
    gao.insert (r, 3*inf);
    gao.insert (r, -3*inf);
    repf (i, 1, n-1){
        int t; 
        if (scanf ("%d", &t) == EOF) t = 0;
        if (!gao.insert (r, t)) continue;
        int t1 = gao.find (gao.an[r].a[0], 1), t2 = gao.find (gao.an[r].a[1], 0);
        ans += min (t - t1, t2 - t);
    }
    printf ("%d\n", ans);
    return 0;
}
