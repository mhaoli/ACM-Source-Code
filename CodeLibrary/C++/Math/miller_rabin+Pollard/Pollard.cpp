#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define MAX (pow(2.0, 60))                               //标记最大值
#define C 240
#define TIME 12                                                 //Miller测试次数
using namespace std;
__int64 MIN;
__int64 gcd(__int64 a, __int64 b) //计算a和b的最大公约数
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
__int64 mod_mult(__int64 a, __int64 b, __int64 n) //计算(a*b) mod n
{
    __int64 s = 0;
    a = a % n;
    while (b) {
        if (b & 1) {
            s += a;
            if (s >= n)
                s -= n;
        }
        a = a << 1;
        if (a >= n)
            a -= n;
        b = b >> 1;
    }
    return s;
}
__int64 mod_exp(__int64 a, __int64 b, __int64 n) //计算(a^b) mod n
{
    __int64 d = 1;
    a = a % n;
    while (b >= 1) {
        if (b & 1)
            d = mod_mult(d, a, n);
        a = mod_mult(a, a, n);
        b = b >> 1;
    }
    return d;
}
bool Wintess(__int64 a, __int64 n) //以a为基对n进行Miller测试并实现二次探测
{
    __int64 m, x, y;
    int i, j = 0;
    m = n - 1;
    while (m % 2 == 0) //计算(n-1)=m*(2^j)中的j和m,j=0时m=n-1,不断的除以2直至n为奇数
    {
        m = m >> 1;
        j++;
    }
    x = mod_exp(a, m, n);
    for (i = 1; i <= j; i++) {
        y = mod_exp(x, 2, n);
        if ((y == 1) && (x != 1) && (x != n - 1)) //二次探测
            return true; //返回true时,n是合数
        x = y;
    }
    if (y != 1)
        return true;
    return false;
}
bool miller_rabin(int times, __int64 n) //对n进行s次的Miller测试
{
    __int64 a;
    int i;
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    srand(time(NULL));
    for (i = 1; i <= times; i++) {
        a = rand() % (n - 1) + 1;
        if (Wintess(a, n))
            return false;
    }
    return true;
}
__int64 Pollard(__int64 n, int c) //对n进行因字分解,找出n的一个因子,注意该因子不一定是最小的
{
    __int64 i, k, x, y, d;
    srand(time(NULL));
    i = 1;
    k = 2;
    x = rand() % n;
    y = x;
    while (true) {
        i++;
        x = (mod_mult(x, x, n) + c) % n;
        d = gcd(y - x, n);
        if (d > 1 && d < n)
            return d;
        if (y == x) //该数已经出现过,直接返回即可
            return n;
        if (i == k) {
            y = x;
            k = k << 1;
        }
    }
}
void get_small(__int64 n, int c) //找出最小的素数因子
{
    __int64 m;
    if (n == 1)
        return;
    if (miller_rabin(TIME, n)) //判断是否为素数
    {
        if (n < MIN)
            MIN = n;
        return;
    }
    m = n;
    while (m == n) //找出n的一个因子
        m = Pollard(n, c--);
    get_small(m, c); //二分查找
    get_small(n / m, c);
}
int main() {
    int total;
    __int64 n;
    scanf("%d", &total);
    while (total--) {
        scanf("%I64d", &n);
        MIN = MAX;
        if (miller_rabin(TIME, n))
            printf("Prime\n");
        else {
            get_small(n, C);
            printf("%I64d\n", MIN);
        }
    }
    return 0;
}
