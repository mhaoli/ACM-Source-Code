/*
 * Author:  Plumrain
 * Created Time:  2014/6/11 11:25:32
 * File Name: 102.cpp
 */
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
