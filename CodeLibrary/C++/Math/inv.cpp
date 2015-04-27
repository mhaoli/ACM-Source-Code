/*
 * Author:  Plumrain
 * File Name: inv.cpp
 * Time: O(n)
 */

//要注意，特判0的阶乘的逆元为1
//fac[] 阶乘
//inv[i] i的逆元
//fac_inv[i] = i!的逆元

int fac[Max_N], inv[Max_N], fac_inv[Max_N];

void init(int n) {
        fac_inv[0] = fac_inv[1] = inv[1] = fac[1] = 1;
        for(int i = 2; i <= n; ++i) {
                fac[i] = (long long)fac[i-1] * i % mod;
                inv[i] = (long long)(mod - mod / i) * inv[mod%i] % mod;
                fac_inv[i] = (long long)fac_inv[i-1] * inv[i] % mod;
        }
}

