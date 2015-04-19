#include<bits/stdc++.h>
using namespace std;
const int N = 9 + (int)2e5;
char s[2][N];
int a[N], b[N], c[N], len[N], last[N], n;
int calc (int u, int v){
    return (v%n) - (u%n) + (u/n != v/n);
}
int main(){
    int m;
    scanf ("%d%d", &n, &m);
    scanf ("%s%s", s[0], s[1]);
    int t1 = 0, t3 = 0;
    for (int i = 0; i < n; ++ i){
        if (s[0][i] == s[1][i]){
            if (s[0][i] == 'X') a[t1++] = i;
        } else c[t3++] = i;
    }
    len[0] = last[0] = 0;
    for (int i = 1; i < t3; ++ i){
        if (c[i-1] == c[i] - 1 && s[0][c[i-1]] != s[0][c[i]]) len[i] = 0, last[i] = i;
        else len[i] = len[i-1] + c[i] - c[i-1] + (s[0][c[i-1]] != s[0][c[i]]), last[i] = last[i-1];
    }
    for (int u, uu, v, vv, p, pp, p2, ans; m; --m){
        scanf ("%d%d", &uu, &vv);
        u = --uu % n;
        v = --vv % n;
        if (v == u) ans = vv != uu;
        else{
            if (u > v) swap (u, v), swap (uu, vv);
            p2 = upper_bound (a, a + t1, v) - a;
            if (p2 > 0 && a[p2-1] >= u) ans = -1;
            else{
                p = upper_bound (c, c + t3, v) - c;
                if (--p >= 0 && last[p] && c[last[p]] > u) ans = -1;
                else if (p < 0 || c[p] < u){
                    ans = calc (uu, vv);
                } else{
                    pp = lower_bound (c, c + t3, u) - c;
                    ans = calc (uu, (s[0][c[pp]] == 'X') * n + c[pp]) + len[p] - len[pp] + calc ((s[0][c[p]]=='X')*n + c[p], vv);
                }
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}
