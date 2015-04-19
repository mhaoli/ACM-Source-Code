/*
 * Author:  Plumrain
 * Created Time:  2014-02-24 21:53
 * File Name: DS-HDU-2795.cpp
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define lson 2*rt, l, m
#define rson 2*rt+1, m+1, r
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 200005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int n, w, num[maxn<<2];

void pushup(int rt)
{
    num[rt] = max(num[rt*2], num[rt*2+1]);
}

void build (int rt, int l, int r)
{
    if (l == r){
        num[rt] = w; return;
    }
    int m = (l + r) >> 1;
    build (lson); build (rson); pushup(rt);
}

int update(int v, int rt, int l, int r)
{
    if (num[rt] < v) return -1;
    if (l == r){
        num[rt] -= v;
        return l;
    }

    int m = (l + r) >> 1;
    int ret;
    if (num[2*rt] >= v) ret = update (v, lson);
    else ret = update (v, rson);
    pushup (rt);
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int m, tmp;
    while (scanf ("%d%d%d", &n, &w, &m) != EOF){
        n = min(n, m);
        build (1, 1, n);
        while (m --){
            scanf ("%d", &tmp);
            printf ("%d\n", update (tmp, 1, 1, n));
        }
    }
    return 0;
}
