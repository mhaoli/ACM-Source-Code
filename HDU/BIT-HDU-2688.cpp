/*
 * Author:  Plumrain
 * Created Time:  2014-02-17 22:26
 * File Name: AAAAA.cpp
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
#define lowbit(x) ((x)&(-x))
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 3000005;
const int M = 10005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

char s[1000];
int64 ans;
int n, lim, an[N], c[M];

int64 sum(int x)
{
    int64 ret = 0;
    if (!x) return 0;
    while (x > 0) ret += c[x], x -= lowbit(x);
    return ret;
}

void add(int x, int d)
{
    while (x < M) c[x] += d, x += lowbit(x);
}

void gao(int s, int e)
{
    int tmp;
    for (int i = s+1; i <= e; ++ i){
        if (an[i-1] < an[i]) -- ans;
        if (an[i-1] > an[i]) ++ ans;
        tmp = an[i-1]; an[i-1] = an[i]; an[i] = tmp;
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d", &n) != EOF){
        ans = 0;
        clr (c);
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &an[i]);
            ans += sum(an[i] - 1);
            add (an[i], 1);
        }

        int m, t1, t2;
        scanf ("%d", &m);
        while (m --){
            scanf ("%s", s);
            if (s[0] == 'Q') printf ("%I64d\n", ans);
            else{
                scanf ("%d%d", &t1, &t2);
                gao (min(t1, t2), max(t1, t2));
            }
        }
    }
    return 0;
}
