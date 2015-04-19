/*
 * Author:  Plumrain
 * Created Time:  2013-10-28 14:32
 * File Name: nath-HDU-3221.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, (int64)0, sizeof(x))
const int N = 2000000;
typedef long long int64;
typedef int64 matrix[10][10];

int64 a, b, mod, n;
int64 phi[N+5];
bool xxx;
matrix at, bt, cnt;

int64 pow_mod(int64 p, int64 num, int64 mod)
{
    p %= mod;
    int64 ret = 1;
    while (num){
        if (num & 1) ret = (ret * p) % mod;
        num >>= 1;
        p = (p * p) % mod;
    }
    return ret;
}

void phi_table(int n)
{
    CLR (phi);
    phi[1] = 1;
    for (int i = 2; i <= n; ++ i)
        if (!phi[i]){
            for (int j = i; j <= n; j += i){
                if (!phi[j]) phi[j] = j;
                phi[j] -= phi[j]/i;
            }
        }
}

void mtx_init()
{
    at[0][0] = 2;
    at[1][1] = at[0][1] = at[1][0] = 1;
    cnt[1][1] = 0;
    cnt[0][0] = cnt[0][1] = cnt[1][0] = 1;
    bt[0][0] = 3;
    bt[0][1] = bt[1][0] = 2;
    bt[1][1] = 1;
}

void mtx_mul(matrix& A, matrix B)
{
    matrix ret;
    for (int i = 0; i < 2; ++ i)
        for (int j = 0; j < 2; ++ j){
            ret[i][j] = 0;
            for (int k = 0; k < 2; ++ k){
                ret[i][j] += A[i][k] * B[k][j];
                if (xxx || ret[i][j] > N*10){
                    xxx = 1;
                    ret[i][j] %= mod;
                }
            }
        }

    for (int i = 0; i < 2; ++ i)
        for (int j = 0; j < 2; ++ j)
            A[i][j] = ret[i][j];
}

void mtx_pow(matrix& A, int64 n)
{
    matrix ret; CLR (ret);
    ret[0][0] = ret[1][1] = 1;
    while (n){
        if (n & 1) mtx_mul(ret, A);
        n >>= 1;
        mtx_mul(A, A);
    }

    for (int i = 0; i < 2; ++ i)
        for (int j = 0; j < 2; ++ j)
            A[i][j] = ret[i][j];
}

int main()
{
    phi_table(N);

    int T, test = 0;
    scanf ("%d", &T);
    while (T--){
        mtx_init();
        xxx = false;
        
        int64 p;
        scanf ("%lld%lld%lld%lld", &a, &b, &p, &n);
        mod = phi[p];
        printf ("Case #%d: ", ++test);
        int64 ans;
        if (n == 1)
            ans = a%p;
        else if (n == 2)
            ans = b%p;
        else if (n == 3)
            ans = (a*b)%p;
        else{
            mtx_pow(cnt, n-4);
            mtx_mul(at, cnt);
            mtx_mul(bt, cnt);

            int64 tmp1, tmp2;
            if (xxx){
                tmp1 = pow_mod(a, at[0][1] + mod, p) % p; 
                tmp2 = pow_mod(b, bt[0][1] + mod, p) % p;
            }
            else{
                tmp1 = pow_mod(a, at[0][1], p) % p; 
                tmp2 = pow_mod(b, bt[0][1], p) % p;
            }
            ans = (tmp1 * tmp2) % p;
        }
        printf ("%lld\n", ans);
    }
    return 0;
}
