#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define x first
#define y second
#define out(x) cout << (#x) << ":" << (x) << endl;
typedef long long ll;
template<class T> bool chmin (T&a, const T&b){return b < a ? a = b, 1 : 0;}
template<class T> bool chmax (T&a, const T&b){return b > a ? a = b, 1 : 0;}

const int inf = ~0u>>1;
const int N = int(1e4) + 109;
bool check[N + 5];
int prm[N + 5], prm_tot, idx[N + 5];

int fac_dev (int x, int *a, int *b){
    int tot = -1;
    for (int i = 0; i < prm_tot && prm[i]*prm[i] <= x; ++ i){
        if (x % prm[i]) continue;
        a[++tot] = i; b[tot] = 0;
        while (!(x % prm[i])){
            ++ b[tot]; x /= prm[i];
        }
    }
    if (x != 1) a[++tot] = idx[x], b[tot] = 1;
    return ++tot;
}

int primes (int n){
    memset (check, 0, sizeof check);
    int tot = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[tot++] = i;
        for (int j = 0; j < tot && i*prm[j] <= n; ++ j){
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
    return tot;
}

int cnt[N];
int faca[N][20], facb[N][20], fac[N];
int ans_x[N<<1], ans_y[N<<1];

void calc (int x, int fg){
    for (int i = 0; i < prm_tot && prm[i] <= x; ++ i){
        for (int j = prm[i]; j <= x; j *= prm[i]){
            cnt[i] += fg * (x / j);
        }
    }
}

int ok (int x){
    bool ans = 1;
    for (int i = 0; i < fac[x]; ++ i){
        cnt[faca[x][i]] -= facb[x][i];
        if (cnt[faca[x][i]] < 0){
            ans = 0; break;
        }
    }
    if (!ans){
        for (int i = 0; i < fac[x]; ++ i){
            cnt[faca[x][i]] += facb[x][i];
            if (cnt[faca[x][i]] < facb[x][i]) break;
        }
    }
    return ans;
}

int main(){
    prm_tot = primes (N-5);
    for (int i = 0; i < prm_tot; ++ i) idx[prm[i]] = i;
    for (int i = 2; i < N-5; ++ i)
       fac[i] = fac_dev (i, faca[i], facb[i]);

    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        int t;
        memset (cnt, 0, sizeof cnt);
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &t);
            calc (t, 1);
        }
        for (int i = 0; i < m; ++ i){
            scanf ("%d", &t);
            calc (t, -1);
        }
        
        bool ans_u = 1;
        for (int i = 0; i < prm_tot; ++ i) if (cnt[i] < 0){
            ans_u = 0; break;
        }

        if (!ans_u){
            puts ("-1"); continue;
        }

        //cout << "fuck" << endl;
        //for (int i = 0; i < 10; ++ i) cout << prm[i] << " " << cnt[i] << endl;
        //puts ("");

        int ans_cnt = 0;
        while (1){
            int i;
            for (i = 2; ; ++ i){
                if (!ok (i)) break;
            }
            if (--i == 1) break;

            if (ans_cnt && i == ans_x[ans_cnt-1]){
                ++ ans_y[ans_cnt-1];
            } else{
                ans_x[ans_cnt] = i;
                ans_y[ans_cnt++] = 1;
            }
        }
        printf ("%d\n", ans_cnt);
        for (int i = 0; i < ans_cnt; ++ i)
            printf ("%d %d\n", ans_x[i], ans_y[i]);
    }
    return 0;
}
