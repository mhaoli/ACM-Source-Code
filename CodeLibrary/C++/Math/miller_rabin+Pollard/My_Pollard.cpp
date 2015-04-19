//Pollard分解质因数方法
//分解后的质因数全部存在
//时间复杂度一般为O(n^(1/4))

        /*调用miller_rabin*/
const int MT = 5;
int64 mul_mod(int64 p, int64 q, int64 mod)
int64 pow_mod(int64 p, int64 n, int64 mod)
bool miller_rabin(n, MT)
            /*end*/

#include<ctime>
typedef long long int64;
const int TIM = 240;       /*控制循环次数*/
int cnt;                /*分解后质因数的个数*/
int64 fac[];            /*存分解后的所有质因数*/

//要分解n，调用语句为cnt = 0; get_prime(n, TIM);
//调用完成以后，一般要加一句sort(fac, fac+cnt, cmp);

int64 gcd(int64 a, int64 b)
{
    return b ? gcd(b, a%b) : a;
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
        fac[cnt++] = n;
        return;
    }

    int64 m = n;
    while (m == n) m = pollard(m, c--);
    get_prime(m, c);
    get_prime(n/m, c);
}

