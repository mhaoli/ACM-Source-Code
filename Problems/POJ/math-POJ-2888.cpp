/*
 * Author:  Plumrain
 * Created Time:  2013-10-17 18:26
 * File Name: math-POJ-2888.cpp
 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int mod = 9973;
typedef int matrix[15][15];

matrix pat;
int n, m, k;

void init()
{
    scanf ("%d%d%d", &n, &m, &k);
    
    for (int i = 0; i < m; ++ i)
        for (int j = 0; j < m; ++ j)
            pat[i][j] = 1;
    while (k--){
        int ta, tb;
        scanf ("%d%d", &ta, &tb);
        -- ta; -- tb;
        pat[ta][tb] = 0;
        pat[tb][ta] = 0;
    }
}

int euler_phi(int n)
{
    int m = (int)sqrt(n + 0.5);
    int ans = n;
    for (int i = 2; i <= m; ++ i)
        if (!(n % i)){
            ans = ans / i * (i-1);
            while (!(n % i)) n /= i;
        }
    if (n > 1) ans = ans / n * (n-1);
    return (ans % mod);
}

void mtx_mul(matrix& A, matrix B)
{
    matrix ret;
    for (int i = 0; i < m; ++ i)
        for (int j = 0; j < m; ++ j){
            ret[i][j] = 0;
            for (int k = 0; k < m; ++ k)
                ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]) % mod;
            if (ret[i][j] < 0) ret[i][j] += mod;
        }

    for (int i = 0; i < m; ++ i)
        for (int j = 0; j < m; ++ j)
            A[i][j] = ret[i][j];
}

void mtx_pow(matrix& A, int n)
{
    -- n;
    if (!n) return;
    
    matrix ret;
    for (int i = 0; i < m; ++ i)
        for (int j = 0; j < m; ++ j)
            ret[i][j] = A[i][j];
    while (n > 0){
        if (n & 1) mtx_mul(ret, A);
        n >>= 1;
        mtx_mul(A, A);
    }

    for (int i = 0; i < m; ++ i)
        for (int j = 0; j < m; ++ j)
            A[i][j] = ret[i][j];
}

int pow_mod(int n, int p)
{
    n %= mod;
    int ret = 1;
    while (p > 0){
        if (p & 1) ret = (ret * n) % mod;
        p >>= 1;
        n = (n * n) % mod;
    }
    return ret;
}

int solve(int n)
{
    matrix A;
    for (int i = 0; i < m; ++ i)
        for (int j = 0; j < m; ++ j)
            A[i][j] = pat[i][j];
    mtx_pow(A, n);
    int ret = 0;
    for (int i = 0; i < m; ++ i)
        ret = (ret + A[i][i]) % mod;
    if (ret < 0) ret += mod;
    return ret;
}

int Polya()
{
    int ret = 0;
    for (int i = 1; i*i <= n; ++ i) if (n % i == 0){
        if (i*i < n) ret = (ret + solve(i)*euler_phi(n/i) + solve(n/i)*euler_phi(i)) % mod;
        else ret = (ret + solve(i) * euler_phi(i)) % mod;
    }
    return (ret * pow_mod(n%mod, mod-2)) % mod;
}

int main()
{
    int T;
    scanf ("%d", &T);
    while (T--){
        init(); 
        printf ("%d\n", Polya());
    }
    return 0;
}
