/*
 * Author:  Plumrain
 * Created Time:  2014/8/2 23:04:53
 * File Name: inv.cpp
 * calculate all inv[i], i = 1 to n
 * Time: O(n)
 */
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)

//fac[i]和inv[i]都是i的乘法逆
//by the way，n!的逆元就是1到n所有数逆元之积，因为逆元是完全积性函数
//但是要注意，特判0的阶乘的逆元为1

const int mod = ; //mod is prime

void inv_init(int n){
    inv[1] = 1; fac[1] = 1;
    for (int t, k, i = 2; i <= n; ++ i){
        t = mod / i; k = mod - t * i; 
        inv[i] = ((long long)i * t % mod) * t % mod;
        inv[i] = ((long long)inv[i] * inv[k] % mod) * inv[k] % mod;

        fac[i] = (long long)(mod - mod / i) * fac[mod%i] % mod;
    }
}
