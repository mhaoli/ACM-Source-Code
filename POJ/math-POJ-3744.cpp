/*
 * Author:  Plumrain
 * Created Time:  2013-10-29 13:27
 * File Name: math-POJ-3744.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define CLR(x) memset(x, 0.0, sizeof(x))
typedef double matrix[10][10];

int a[50], n;
double p;
matrix cnt, A;

void mtx_init()
{
    cnt[0][0] = p; cnt[1][0] = 1.0 - p;
    cnt[0][1] = 1.0; cnt[1][1] = 0.0;

    A[0][0] = p*p + 1.0 - p; A[1][1] = 1.0;
    A[0][1] = A[1][0] = p;
}

inline void mtx_equ(matrix& A, matrix ret)
{
    for (int i = 0; i < 2; ++ i)
        for (int j = 0; j < 2; ++ j)
            A[i][j] = ret[i][j];
}

void mtx_mul(matrix& A, matrix B)
{
    matrix ret;
    for (int i = 0; i < 2; ++ i)
        for (int j = 0; j < 2; ++ j){
            ret[i][j] = 0;
            for (int k = 0; k < 2; ++ k)
                ret[i][j] += A[i][k] * B[k][j];
        }

    mtx_equ(A, ret);
}

void mtx_pow(matrix& A, int n)
{
    matrix ret;
    CLR (ret); ret[0][0] = ret[1][1] = 1;
    while (n){
        if (n & 1) mtx_mul(ret, A);
        n >>= 1;
        mtx_mul(A, A);
    }

    mtx_equ(A, ret);
}

double cal(int n)
{
    if (!n || n == 1) return 1;
    mtx_init(); 
    mtx_pow(cnt, n-2);
    mtx_mul(A, cnt);
    return A[0][1];
}

double gao()
{
    double ret = 1.0 - cal(a[0]);
    for (int i = 1; i < n; ++ i)
        ret *= (1.0 - cal(a[i] - a[i-1]));
    return ret;
}

int main()
{
    while (scanf ("%d", &n) != EOF){
        cin >> p;
        for (int i = 0; i < n; ++ i)
            scanf ("%d", &a[i]);
        sort (a, a+n);
        printf ("%.7f\n", gao());
    }
    return 0;
}
