#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

const int mod = 1000000007;

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

int find_fac(int x, int *idx, int *a){
    int cnt = 0;
    for (int i = 1; i <= x; ++ i) if (x % i == 0){
        idx[i] = cnt;
        a[cnt++] = i;
    }
    return cnt;
}

int a[1001], idx[1111];
int d[101][1001][40], L, n, tot;

int dfs (int p, int s, int l){
    if (p < n){
        int &ret = d[p][s][l];
        if (~ret) return ret;
        ret = 0;
        for (int i = 0; i < tot && s >= a[i]; ++ i){
            int t = a[i]; 
            t /= __gcd (t, a[l]); t *= a[l];
            add (ret, dfs (p+1, s-a[i], idx[t]));
        }
        return ret;
    } else return (!s && a[l] == L);
}

int main(){
    int s, l;
    while (scanf ("%d%d%d", &s, &l, &n) != EOF){
        L = l;
        for (int i = 0; i < n; ++ i){
            if (s > 200) memset (d[i], -1, sizeof d[i]);
            else for (int j = 0; j <= s; ++ j)
                memset (d[i][j], -1, sizeof d[i][j]);
        }
        tot = find_fac (l, idx, a);
        int ans = 0;
        for (int i = 0; i < tot && a[i] <= s; ++ i){
            add (ans, dfs (1, s - a[i], i));
        }
        printf ("%d\n", ans);
    }
    return 0;
}
