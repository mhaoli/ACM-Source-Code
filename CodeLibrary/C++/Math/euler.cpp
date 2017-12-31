/*
 * Author:  Plumrain
 * Created Time:  2014/6/11 11:25:32
 * File Name: 102.cpp
 */
// calc euler_table
#include <cstring>
#define clr(x,y) memset(x, y, sizeof(x))
const int maxn = ;

int prm[maxn+5], phi[maxn+5];
bool check[maxn+5];

int phi_table(int n){
    clr (check, 0); phi[1] = 1;
    int tot = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[ tot++ ] = i, phi[i] = i - 1;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            check[ i*prm[j] ] = 1;
            if (i % prm[j] == 0){
                phi[ i*prm[j] ] = phi[i] * prm[j]; break;
            }
            else phi[ i*prm[j] ] = phi[i] * (prm[j] - 1);
        }
    }
    return tot;
}

// calc_phi(x)
const int N = 111111;
bool check[N];
int prm[N];

int primes(int n){
    //memset(check, 0, sizeof check);
    int tot = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[tot++] = i;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            //这里，prm[j]是合数i*prm[j]最小的质因子
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
    return tot;
}
int calc_phi(int n, int np){
    int ans = n;
    for(int i = 0; i < np; ++i){
        if(1ll * prm[i] * prm[i] > n)break;
        if(n % prm[i] == 0){
            while(n % prm[i] == 0) n /= prm[i];
            ans = ans / prm[i] * (prm[i]-1);
        }
    }
    if(n > 1){
        ans = ans / n * (n-1);
    }
    return ans;
}

