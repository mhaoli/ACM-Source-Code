#include<cstdio>
#include<algorithm>
const int N = 9 + (int)1e7;
const long long mod = 20101009;
bool check[N];
int prm[N/10], g[N], s[N];
void add (int &a, int b){
    if (b < 0) b += mod;
    a += b; if (a >= mod) a -= mod;
}
void init (int n){
    int tot = 0;
    g[1] = 1; 
    for (int j, i = 2; i <= n; ++ i){
        if (!check[i]) prm[tot++] = i, g[i] = 1 - i;
        for (j = 0; j < tot && prm[j]*i <= n; ++ j){
            check[prm[j] * i] = 1;
            if (i % prm[j] == 0){
                g[prm[j] * i] = g[i];
                break;
            } else g[prm[j] * i] = g[i] * (1 - prm[j]) % mod;
        }
    }
    for (int i = n; i > 1; -- i) g[i] = (long long)i * g[i] % mod;
    for (int i = 1; i <= n; ++ i) s[i] = s[i-1], add (s[i], g[i]);
}
int main(){
    int n, m; scanf ("%d%d", &n, &m);
    init (std::max (n, m));
    int ans = 0, up = n<m ? n : m;
    for (int i = 1, t1, t2, ti, tj, nxt; i <= up; i = nxt + 1){
        t1 = n / i; t2 = m / i; ti = n / t1; tj = m / t2;
        nxt = ti<tj ? ti : tj;
        add (ans, (t1 + 1ll) * (t2 + 1) % mod * t1 % mod * t2 % mod * (s[nxt] - s[i-1]) % mod);
    }
    long long t = mod / 4, inv4 = t * t * 4 % mod;
    printf ("%d\n", (int)(ans * inv4 % mod));
    return 0;
}
