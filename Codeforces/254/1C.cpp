/*
 * Author:  Plumrain
 * Created Time:  2014/9/2 20:29:34
 * File Name: C.cpp
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

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
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
const int inf = ~0U >> 1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

#define lson l, (l+r)>>1, rt<<1
#define rson ((l+r)>>1)+1, r, rt<<1|1
const int maxn = int(1e5) + 9;
int L, R, w;
int mark[maxn<<2];
int64 sum[maxn<<2], delta[maxn<<2];

void Up (int l, int r, int rt){
    int m = (l + r) >> 1;
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    sum[rt] += (m - l + 1) * delta[rt<<1] + (r - m) * delta[rt<<1|1];
}

void Down (int rt){
    if (delta[rt]){
        delta[rt<<1] += delta[rt];
        delta[rt<<1|1] += delta[rt];
        delta[rt] = 0;
    }
    if (mark[rt]){
        mark[rt<<1] = mark[rt];
        mark[rt<<1|1] = mark[rt];
        mark[rt] = 0;
    }
}

void build (int l, int r, int rt){
    if (l < r){
        sum[rt] = delta[rt] = mark[rt] = 0;
        build (lson); build (rson);
    } else mark[rt] = l;
}

int64 query (int l, int r, int rt){
    if (L <= l && r <= R){
        return sum[rt] + (r - l + 1) * delta[rt];
    }

    int m = (l + r) >> 1;
    int64 ret = 0;
    Down (rt);
    if (L <= m) ret += query (lson);
    if (R > m) ret += query (rson);
    Up (l, r, rt);
    return ret;
}

void Clear (int l, int r, int rt){
    if (mark[rt]){
        delta[rt] += abs (w - mark[rt]);
    } else{
        Down (rt);
        Clear (lson); Clear (rson);
        Up (l, r, rt);
    }
}

void modify (int l, int r, int rt){
    if (L <= l && r <= R){
        if (mark[rt]){
            delta[rt] += abs (mark[rt] - w);
        } else{
            Clear (l, r, rt);
        }
        mark[rt] = w;
        return;
    }

    int m = (l + r) >> 1;
    Down (rt);
    if (L <= m) modify (lson);
    if (R > m) modify (rson);
    Up (l, r, rt);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m; scanf ("%d%d", &n, &m);
    build (1, n, 1);
    while (m--){
        int op;
        scanf ("%d%d%d", &op, &L, &R);
        if (op == 1){
            scanf ("%d", &w);
            modify (1, n, 1);
        } else{
            printf ("%I64d\n", query (1, n, 1));
        }
    }
    return 0;
}
