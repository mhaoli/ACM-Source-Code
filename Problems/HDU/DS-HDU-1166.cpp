/*
 * Author:  Plumrain
 * Created Time:  2014-02-24 03:08
 * File Name: DS-HDU-1166.cpp
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

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

char s[10];
int sum[400005];

int query (int ql, int qr, int o, int l, int r)
{
    //tst (ql), tst (qr), tst (o); tst (l); out (r);
    int m = l + (r-l)/2, ans = 0;
    if (ql <= l && r <= qr) return sum[o];
    if (ql <= m) ans += query (ql, qr, 2*o, l, m);
    if (qr > m) ans += query (ql, qr, 2*o+1, m+1, r);
    return ans;
}

void add(int t1, int t2, int o, int l, int r)
{
    int m = l + (r - l) / 2;
    if (l == r) sum[o] += t2;
    else{
        if (t1 <= m) add (t1, t2, 2*o, l, m);
        else add (t1, t2, 2*o+1, m+1, r);
        sum[o] = sum[2*o] + sum[2*o+1];
    }
}

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int cas = 0, n, T;
    scanf ("%d", &T);
    while (T --){
        scanf ("%d", &n);
        printf ("Case %d:\n", ++ cas);
        clr (sum); int tmp;
        for (int i = 0; i < n; ++ i) scanf ("%d", &tmp), add(i+1, tmp, 1, 1, n);
        
        s[0] = 'A';
        while (s[0] != 'E'){
            scanf ("%s", s);
            int t1, t2;
            if (s[0] == 'A'){
                scanf ("%d%d", &t1, &t2); add (t1, t2, 1, 1, n);
            }
            else if (s[0] == 'S'){
                scanf ("%d%d", &t1, &t2); add (t1, -t2, 1, 1, n);
            }
            else if (s[0] == 'Q'){
                scanf ("%d%d", &t1, &t2); printf ("%d\n", query(t1, t2, 1, 1, n));
            }
        }
    }
    return 0;
}
