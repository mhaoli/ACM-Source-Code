//Miller_Rabin素数测试法，质数返回1，否则返回0
//若用下面prm[]里的数进行测试，10^16以内只有唯一强伪素数46,856,248,255,981

/*#include <ctime>*/
const int MT = 5;      /*prm[]的元素个数，也即是需要测试的底的个数*/    
const int64 SPE = 46856248255981;             //强伪素数
typedef long long int64;
int64 prm[5] = {2, 3, 7, 61, 24251};

//要判断n是不是质数时，调用语句为miller_rabin(n, MT);

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

bool Wintess(int64 aa, int64 n, int64 mod)      /*是以aa为底的伪质数返回0,是合数返回1*/
{
    int t = 0;
    while ((n & 1) == 0){               /*n = d * 2^t; n = d;*/
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
        int64 aa = prm[i];           /*也可以用随机化的aa，在前面写srand(time(NULL));在这里写int64 aa=rand()%(n-1)+1;*/
        if (aa == n) return true;
        if (Wintess(aa, n-1, n)) return false;
    }
    return true;
}
