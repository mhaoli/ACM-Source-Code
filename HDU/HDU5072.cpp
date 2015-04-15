#include <cstdio>
#include <cstring>
void Read(int &ret){
    ret=0; int c,ok=0;
    for(;;) if ((c=getchar()) >= '0' && c <= '9') ret=(ret<<3)+(ret<<1)+c-'0',ok=1; else if (ok) return;
}
const int N = 9 + (int)1e5;
bool check[N];
int prm[N], mo[N];
void mobius (int n){
    mo[1] = 1;
    int tot = 0;
    for (int i = 2, j; i <= n; ++ i){
        if (!check[i]) prm[tot++] = i, mo[i] = -1;
        for (j = 0; j < tot && i*prm[j] <= n; ++ j){
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0){
                mo[i*prm[j]] = 0; break;
            } else mo[i*prm[j]] = -mo[i];
        }
    }
}
int a[N], cnt[N], f[N];
int main(){
    mobius (N - 5);
    int _; Read (_);
    while (_--){
        int n, i, j, t; Read (n);
        memset (cnt, 0, sizeof cnt);
        memset (f, 0, sizeof f);
        for (i = 0; i < n; ++ i)
            Read (a[i]), ++ cnt[a[i]];
        for (i = 1; i < N; ++ i)
            for (j = i<<1; j < N; j += i)
                cnt[i] += cnt[j];
        for (i = 1; i < N; ++ i) if (mo[i] && cnt[i] > 1)
            for (j = i, t = mo[i]*(cnt[i]-1); j < N; j += i) f[j] += t;
        long long ans = 0;
        for (i = 0; i < n; ++ i)
            ans += (long long)f[a[i]] * (n - 1 - f[a[i]]);
        ans = (long long)n * (n - 1) * (n - 2) / 6 - ans / 2;
        printf ("%I64d\n", ans);
    }
    return 0;
}
