/*
 * Author:  Plumrain
 * Created Time:  2014-02-12 13:23
 * File Name: G.cpp
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
#define lowbit(v) ((v)&(-v))
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
//#define out(x) cout<<#x<<":"<<(x)<<endl
//#define tst(a) cout<<a<<" "
//#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 100005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int n, k;
int c[N], num[N];
char s[10];

int sum (int x)
{
    int ret = 0;
    while (x > 0){
        ret += c[x]; x -= lowbit(x);
    }
    return ret;
}

void add(int x, int d)
{
    while (x <= n){
        c[x] += d; x += lowbit(x);
    }
}

void gao1()
{
    int t1, t2;
    scanf ("%d%d", &t1, &t2);
    add(t1, t2 - num[t1]);
    num[t1] = t2;
}

int bin_sch(int x)
{
    int l = 1, r = n;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (sum(mid) < x) l = mid + 1;
        else r = mid - 1;
    }
    l -= 2;
    while (l <= n && sum (l) < x) ++ l;
    return l;
}

void gao2()
{
    int t;
    scanf ("%d", &t);
    printf ("%d\n", bin_sch(t));
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d", &n) != EOF){
        clr (c);
        for (int i = 1; i <= n; ++ i){
            scanf ("%d", &num[i]); add (i, num[i]);
        }
        scanf ("%d", &k);
        while (k--){
            scanf ("%s", s);
            if (s[0] == 'p') gao1();
            else gao2();
        }
    }
    return 0;
}
