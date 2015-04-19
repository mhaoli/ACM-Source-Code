/*
 * Author:  Plumrain
 * Created Time:  2014-02-20 22:47
 * File Name: BIT-POJ-3321.cpp
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
const int N = 100005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<int > INT; 

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int cnt, bgn[N], end[N];
int c[N], an[N];
bool v[N];
//vi pat[N];
vector<INT > pat(N);

void dfs (int x)
{
    bgn[x] = ++ cnt; v[x] = 1;
    int num = sz(pat[x]);
    for (int i = 0; i < num; ++ i){
        int y = pat[x][i];
        if (!v[y]) dfs (y);
    }
    end[x] = cnt;
}

void add(int x, int d)
{
    while (x <= cnt) c[x] += d, x += lowbit(x);
}

int sum(int x)
{
    int ret = 0;
    while (x > 0) ret += c[x], x -= lowbit(x);
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d", &n) != EOF){
        for (int i = 1; i <= n; ++ i) pat[i].clear();
        int t1, t2;
        for (int i = 0; i < n-1; ++ i){
            scanf ("%d%d", &t1, &t2);
            pat[t1].pb (t2); pat[t2].pb (t1);
        }

        cnt = 0; clr (v); dfs (1);

        clr (c);
        for (int i = 1; i <= n; ++ i){
            add (bgn[i], 1);
            an[i] = 1;
        }

        char s[10]; int tmp;
        scanf ("%d", &m);
        while (m--){
            scanf ("%s%d", s, &tmp);
            if (s[0] == 'Q') printf ("%d\n", sum(end[tmp]) - sum(bgn[tmp]-1));
            else{
                if (!an[tmp]) add (bgn[tmp], 1);
                else add (bgn[tmp], -1);
                an[tmp] ^= 1;
            }
        }
    }
    return 0;
}
