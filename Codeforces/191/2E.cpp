#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
const int mod = 1000000007;
int a[10];
long long dis[1<<24];
int d[1<<24];
void add (int &a, int b){
        a += b; if (a >= mod) a -= mod;
}
int main(){
        int n, m;
        scanf ("%d", &n);
        for (int i = 0; i < n; ++i) scanf ("%I64d", &dis[1<<i]);
        for (int i = 0; i < (1<<n); ++i) dis[i] = dis[i-lowbit(i)] + dis[lowbit(i)];
        scanf ("%d", &m);
        for (int i = 0; i < m; ++i) scanf ("%d", &a[i]);
        d[0] = 1;
        for (int i = 0, j; i < (1<<n); ++i){
                for (j = 0; j < m; ++j) if (a[j] == dis[i]) break;
                if (j == m){
                        for (j = i; j; j ^= lowbit(j)){
                                add (d[i], d[i ^ lowbit(j)]);
                        }
                }
        }
        printf ("%d\n", d[(1<<n) - 1]);
        return 0;
}
