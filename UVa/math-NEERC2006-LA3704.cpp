/*
 * Author:  Plumrain
 * Created Time:  2013-09-13 12:59
 * File Name: math-NEERC2006-LA3704.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

const int N = 500;

typedef long long int64;
typedef int64 matrix[N+5];

int n, mod, d, k;
int64 a[N+5];
int64 A[N+5];

void mtx_mul(matrix& A, matrix B)
{
    matrix ret;
    CLR (ret);
    for (int i = 0; i < n; ++ i)
        for (int j = 0, pos = i; j < n; ++ j, pos=(pos-1+n)%n)
            ret[i] = ((A[j] * B[pos]) % mod + ret[i]) % mod;

    for (int i = 0; i < n; ++ i)
        A[i] = ret[i];
}

void mtx_pow(matrix& A, int num)
{
    if (num == 1) return;

    matrix ret;
    for (int i = 0; i < n; ++ i)
        ret[i] = A[i];
    -- num;

    while (num > 0){
        if (num & 1) mtx_mul (ret, A);
        num >>= 1;
        mtx_mul (A, A);
    }

    for (int i = 0; i < n; ++ i)
        A[i] = ret[i];
}

void gao()
{
    CLR (A);
    int pos1 = 0, pos2 = 0;
    int cnt = 0;
    while (cnt <= d){
        A[pos1] = 1; A[pos2] = 1;

        ++ cnt;
        pos1 = (pos1+1) % n;
        pos2 = (pos2-1+n) % n;
    }

    mtx_pow(A, k);

    for (int i = 0; i < n; ++ i){
        int64 x = 0;
        for (int j = 0; j < n; ++ j)
            x = ((A[(j-i+n)%n]*a[j]) % mod + x) % mod;

        printf ("%lld", x);
        if (i != n-1) printf (" ");
    }
    printf ("\n");
}

int main()
{
    while (scanf ("%d", &n) != EOF){    
        scanf ("%d%d%d", &mod, &d, &k);
        for (int i = 0; i < n; ++ i)
            scanf ("%lld", &a[i]);

        gao ();
    }
    return 0;
}


