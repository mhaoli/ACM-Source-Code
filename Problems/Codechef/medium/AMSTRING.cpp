#include<bits/stdc++.h>
const int N = 1111;
int a[N], K, n;
char s1[N], s2[N];
int calc (int p, char *s1, char *s2){
    int cnt = 0, ret = 0;
    for (int i = 0; i + p < n; ++ i){
        if (s1[i] != s2[i+p]) a[cnt++] = i;
        if (cnt <= K) ret += i + 1;
        else ret += i - a[cnt-K-1];
    }
    return ret;
}
int main(){
    int _; scanf ("%d", &_);
    while (_--){
        scanf ("%d%d%s%s", &n, &K, s1, s2);
        int ans = 0;
        for (int i = 0; i < n; ++ i) ans += calc (i, s1, s2);
        for (int i = 1; i < n; ++ i) ans += calc (i, s2, s1);
        printf ("%d\n", ans);
    }
    return 0;
}
