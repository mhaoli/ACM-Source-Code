/*
 * Author:  Plumrain
 * Created Time:  2014/8/21 15:03:14
 * File Name: 1003.cpp
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
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
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
const int maxn = 50005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 sum[maxn<<2], flag[maxn<<2], mx[maxn<<2];

void R(int64 &ret){
    ret = 0;
    bool ok = 0;
    for( ; ;){
        int c = getchar();
        if (c >= '0' && c <= '9') ret = (ret << 3) + (ret << 1) + c - '0', ok = 1;
        else if (ok) return;
    }
}

void Up (int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    mx[rt] = mx[rt<<1]; chmax (mx[rt], mx[rt<<1|1]);
}

void Down (int rt){
    if (flag[rt]){
        sum[rt<<1] <<= flag[rt];
        sum[rt<<1|1] <<= flag[rt];

        flag[rt<<1] += flag[rt];
        flag[rt<<1|1] += flag[rt];

        mx[rt<<1] <<= flag[rt];
        mx[rt<<1|1] <<= flag[rt];
        flag[rt] = 0;
    }
}

void build (int l, int r, int rt){
    flag[rt] = 0;
    if (l == r){
        mx[rt] = sum[rt] = 1; return;
    }
    int m = (l + r) >> 1;
    build (lson); build (rson);
    Up (rt);
}

int64 query (int ql, int qr, int l, int r, int rt){
    if (ql > qr) return 0;
    if (ql <= l && r <= qr) return sum[rt];
    
    Down (rt);
    int64 ret = 0;
    int m = (l + r) >> 1;
    if (ql <= m) ret += query (ql, qr, lson);
    if (qr > m) ret += query (ql, qr, rson);
    Up (rt);
    return ret;
}

int64 query_mx (int ql, int qr, int l, int r, int rt){
    if (ql > qr) return 0;
    if (ql <= l && r <= qr) return mx[rt];

    Down (rt);
    int64 ret = 0;
    int m = (l + r) >> 1;
    if (ql <= m) chmax (ret, query_mx (ql, qr, lson));
    if (qr > m) chmax (ret, query_mx (ql, qr, rson));
    Up (rt);
    return ret;
}

int query_nod (int64 num, int l, int r, int rt){
    if (l == r) return l;
    Down (rt);
    int m = (l + r) >> 1, ret;
    if (sum[rt<<1] >= num) ret = query_nod (num, lson);
    else ret = query_nod (num-sum[rt<<1], rson);
    Up (rt);
    return ret;
}

void add (int p, int64 s, int l, int r, int rt){
    if (l == r){
        sum[rt] += s; mx[rt] += s; return;
    }

    Down (rt);
    int m = (l + r) >> 1;
    if (p <= m) add (p, s, lson);
    else add (p, s, rson);
    Up (rt);
}

void modify (int ql, int qr, int l, int r, int rt){
    if (ql > qr) return;
    if (ql <= l && qr >= r){
        sum[rt] <<= 1; flag[rt] ++; mx[rt] <<= 1; return;
    }

    Down (rt);
    int m = (l + r) >> 1;
    if (ql <= m) modify (ql, qr, lson);
    if (qr > m) modify (ql, qr, rson);
    Up (rt);
}

int64 calc_left (int64 x, int p, const int &n){
    int64 sum = query (1, p, 1, n, 1);
    return sum - x + 1;
}

int64 calc_right (int64 x, int p, const int &n){
    int64 sum = query (1, p-1, 1, n, 1);
    return x - sum;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("my.out","w",stdout);
    repcase{
        printf ("Case #%d:\n", ++ cas);
        int64 n, m;
        //scanf ("%d%d", &n, &m);
        R (n); R (m);
        
        mx[0] = sum[0] = flag[0] = 0;
        build (1, n, 1);

        int64 l, r;
        char op[10];
        while (m --){
            //tst1 (a);
            //cout << query_mx (1, n, 1, n, 1) << endl;
            //tst1 (b);
            //scanf ("%s%I64d%I64d", op, &l, &r);
            scanf ("%s", op);
            R (l); R (r);
            int lp = query_nod (l, 1, n, 1), rp = query_nod (r, 1, n, 1);
            if (op[0] == 'Q'){
                if (lp == rp) printf ("%I64d\n", r - l + 1);
                else if (lp == rp - 1){
                    int64 sum = query (1, lp, 1, n, 1);
                    int64 ans = sum - l + 1; chmax (ans, r - sum);
                    printf ("%I64d\n", ans);
                }
                else{
                    int64 ans = calc_left (l, lp, n); 
                    chmax (ans, calc_right (r, rp, n));
                    chmax (ans, query_mx (lp+1, rp-1, 1, n, 1));
                    printf ("%I64d\n", ans);
                }
            }
            else{
                if (lp == rp) add (lp, r-l+1, 1, n, 1);
                else if (lp == rp - 1){
                    int64 sum = query (1, lp, 1, n, 1);
                    add (lp, sum-l+1, 1, n, 1);
                    add (rp, r - sum, 1, n, 1);
                }
                else{
                    int64 s1 = calc_left (l, lp, n); 
                    int64 s2 = calc_right (r, rp, n);
                    modify (lp+1, rp-1, 1, n, 1);
                    add (lp, s1, 1, n, 1);
                    add (rp, s2, 1, n, 1);
                }
            }
        }
    }
    return 0;
}
