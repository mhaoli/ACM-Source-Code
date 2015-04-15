/*
 * Author:  Plumrain
 * Created Time:  2013-10-24 09:16
 * File Name: math-POJ-1811.cpp
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>

using namespace std;

const int MT = 5;
const int TIM = 240;
typedef long long int64;
const int64 SPE = 46856248255981;

int64 ans;
int64 prm[5] = {2, 3, 7, 61, 24251};

int64 min(int64 a, int64 b)
{
    return a < b ? a : b;
}

int64 gcd(int64 a, int64 b)
{
    return b ? gcd(b, a%b) : a;
}

int64 mul_mod(int64 p, int64 q, int64 mod)
{
     int64 ret = 0;
     p %= mod;
     while (q){
         if (q & 1){
             ret += p;
             if (ret >= mod) ret -= mod;
         }
         p <<= 1; q >>= 1;
         if (p >= mod) p -= mod;
     }
     return ret;
}

int64 pow_mod(int64 p, int64 n, int64 mod)
{
    int64 ret = 1;
    p %= mod;
    while (n > 0){
        if (n & 1) ret = mul_mod(ret, p, mod);
        n >>= 1;
        p = mul_mod(p, p, mod);
    }
    return ret;
}

bool Wintess(int64 aa, int64 n, int64 mod)
{
    int t = 0;
    while ((n & 1) == 0){
        n >>= 1;
        ++ t;
    }

    int64 x = pow_mod(aa, n, mod), y;
    while (t --){
        y = mul_mod (x, x, mod);
        if (y == 1 && x != 1 && x != mod-1) return 1;
        x = y;
    }
    return (y != 1);
}

bool miller_rabin(int64 n, int tim)
{
    if (n == 2) return true;
    if (n == 1 || (n & 1) == 0 || n == SPE) return false;

    for (int i = 0; i < tim; ++ i){
        int64 aa = prm[i];
        if (aa == n) return true;
        if (Wintess(aa, n-1, n)) return false;
    }
    return true;
}

int64 pollard(int64 n, int c)
{
    srand(time(NULL));
    int64 i = 1, k = 2, x = rand()%n;
    int64 y = x;
    while (1){
        ++ i;
        x = (mul_mod(x, x, n) + c) % n;
        int64 d = gcd(y-x, n);
        if (d > 1 && d < n) return d;
        if (y == x) return n;
        if (i == k){
            y = x;
            k <<= 1;
        }
    }
}

void get_prime(int64 n, int c)
{
    if (n == 1) return;
    if (miller_rabin(n, MT)){
        ans = min(ans, n);
        return;
    }

    int64 m = n;
    while (m == n) m = pollard(m, c--);
    get_prime(m, c);
    get_prime(n/m, c);
}


int main()
{
    int64 tmp = (int64)1 << 60;
    int T;
    scanf ("%d", &T);
    while (T--){
        int64 a;
        scanf ("%lld", &a);
        if (miller_rabin(a, MT))
            printf ("Prime\n");
        else{
            ans = tmp;
            get_prime(a, TIM);            
            printf ("%lld\n", ans);
        }
    }
    return 0;
}
