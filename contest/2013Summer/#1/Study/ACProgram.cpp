/*
 * Author:  chlxyd
 * Created Time:  2013/7/16 13:57:10
 * File Name: I.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repf(i, a, b) for (long long i = (a); i <= (b); ++i)
#define repd(i, a, b) for (long long i = (a); i >= (b); --i)
#define clrs( x , y ) memset( x , y , sizeof(x) )
const long long maxn = 10 + 10;
const long long maxmark = 1024 + 100;
long long f[maxn][maxmark];
long long n, m;

long long two(long long w) { 
    return 1 << w;
}

long long have(long long mark, long long w) { 
    return (mark & two(w)) != 0; 
}

long long add(long long mark, long long w) {
    return (mark | two(w));
}

void dfs(long long w, long long k, long long now, long long blow, long long v) {
    if (k == m) {
        f[w][blow] += v;
        //if (w == 1) printf("%I64d\n", now);
        return;
    }
    else {
        if (have(now, k) == 1) { 
            dfs(w, k + 1, now, blow, v);
        } 
        else {
            if (k < m - 1) {
                if (have(now, k + 1) == 0) {
                    dfs(w, k + 2, now, blow, v);
                    if (have(blow, k) == 0) 
                        dfs(w, k + 2, now, add(blow, k), v);
                    if (have(blow, k + 1) == 0) 
                        dfs(w, k + 2, now, add(blow, k + 1), v); 
                }
                if (have(blow, k) == 0 && have(blow, k + 1) == 0) 
                    dfs(w, k + 1, now, add(blow, k) | add(blow, k + 1), v); 
            }
            if (have(blow, k) == 0) 
                dfs(w, k + 1, now, add(blow, k), v);
            if (k > 0) {
                if (have(blow, k) == 0 && have(blow, k - 1) == 0) {
                    dfs(w, k + 1, now, add(blow, k - 1) | add(blow, k), v);
                }
            }
        }
    }
}

int main(){
    while (scanf("%I64d%I64d", &n, &m) == 2) {
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        rep (i, n) {
           rep (j, two(m)) {
               if (f[i][j] != 0) {
                   dfs(i + 1, 0, j, 0, f[i][j]);
               }
           } 
        }
        //repf (i, 0, n)  {
            //rep (j, two(m)) {
                //printf("%I64d ", f[i][j]);
            //}
            //printf("\n");
        //}
        printf("%I64d\n", f[n][0]);
    }
    return 0;
}

