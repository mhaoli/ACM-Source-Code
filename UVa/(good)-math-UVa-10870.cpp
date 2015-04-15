/*
 * Author:  Plumrain
 * Created Time:  2013-09-10 21:16
 * File Name: math-UVa-10870.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl

typedef int matrix[20][20];

const int N = 15;
int mod;
int a[N+5], f[N+5];

void mtx_init (matrix& A, int n)
{
    CLR (A);
    for (int i = 0; i < (n-1); ++ i)
        A[i][i+1] = 1;
    for (int i = 0; i < n; ++ i)
        A[n-1][i] = a[n-i];
}

void mtx_mul (matrix& A, matrix B, int n)
{
    matrix ret;
    CLR (ret);
    for (int i = 0; i < n; ++ i)
        for (int k = 0; k < n; ++ k)
            for (int j = 0; j < n; ++ j)
                ret[i][k] = (((A[i][j] * B[j][k]) % mod) + ret[i][k]) % mod;

    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            A[i][j] = ret[i][j];
}
void mtx_pow (matrix& A, int num, int n)
{
    matrix ret;
    CLR (ret);
    for (int i = 0; i < n; ++ i)
        ret[i][i] = 1; 
    while (num > 0){
        if (num & 1) 
            mtx_mul (ret, A, n);
        num >>= 1;
        mtx_mul (A, A, n);
    }

    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            A[i][j] = ret[i][j];
}

int gao (int m, int n)
{
    matrix A;
    mtx_init (A, n);
    
    mtx_pow (A, m-n, n); 
    int ret = 0;
    for (int i = 0; i < n; ++ i)
        ret = (((A[n-1][i] * f[i+1]) % mod) + ret) % mod;
    if (ret < 0) ret += mod;
    return ret;
}

int main()
{
    int n, m; 
    while (scanf ("%d%d%d", &n, &m, &mod) != EOF && n){
        for (int i = 1; i <= n; ++ i){
            scanf ("%d", &a[i]);
            a[i] %= mod;
        }
        for (int i = 1; i <= n; ++ i){
            scanf ("%d", &f[i]);
            f[i] %= mod;
        }

        if (m <= n) printf ("%d\n", f[m]);
        else printf ("%d\n", gao (m, n));
    }
    return 0;
}
