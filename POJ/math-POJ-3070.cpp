/*
 * Author:  Plumrain
 * Created Time:  2013-10-14 15:42
 * File Name: math-POJ-3070.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int mod = 10000;
typedef int matrix[10][10];

void mtx_mul(matrix& A, matrix B)
{
    matrix ret; CLR (ret);
    for (int i = 0; i < 2; ++ i)
        for (int j = 0; j < 2; ++ j){
            ret[i][j] = 0;
            for (int k = 0; k < 2; ++ k)
                ret[i][j] = (A[i][k] * B[k][j] + ret[i][j]) % mod;
        }

    for (int i = 0; i < 2; ++ i)
        for (int j = 0; j < 2; ++ j)
            A[i][j] = ret[i][j];
}

void mtx_pow(matrix& A, int n)
{
    -- n;
    matrix ret; CLR (ret);
    for (int i = 0; i < 2; ++ i)
        for (int j = 0; j < 2; ++ j)
            ret[i][j] = A[i][j];
    while (n > 0){
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
    int n;
    while (scanf ("%d", &n) != EOF && n != -1){
        matrix A; CLR (A);
        A[0][0] = 1; A[0][1] = 1; A[1][0] = 1;
        if (n < 4){
            if (!n) printf ("0\n");
            if (n == 1 || n == 2) printf ("1\n");
            if (n == 3) printf ("2\n");
            continue;
        }
        mtx_pow(A, n);
        printf ("%d\n", A[0][1] % mod);     
    }
    return 0;
}
