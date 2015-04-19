/*
 * Author:  Plumrain
 * Created Time:  2013-09-17 20:58
 * File Name: math-UVa-10828.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())

const double eps = 1e-8;
const double zer = 0.0;
const int N = 100;

typedef vector<int> VI;
typedef double matrix[N+5][N+5];

matrix A;
VI pre[N+5];
int num[N+5];
bool inf[N+5];

void gauss_jordan(int n)
{
    for (int i = 0; i < n; ++ i){
        int r = i;
        for (int j = i+1; j < n; ++ j)
            if (fabs(A[j][i]) > fabs(A[r][i])) r = j;

        if (A[r][i] < eps) continue;

        if (r != i) 
            for (int j = 0; j <= n; ++ j) 
                swap(A[i][j], A[r][j]);
                    
        for (int j = 0; j < n; ++ j) if (j != i)
            for (int k = n; k >= i; -- k) 
                A[j][k] -= A[j][i] / A[i][i] * A[i][k];
    }
}

int main()
{
    //freopen("tst.in", "r", stdin); 
    //freopen("my.out", "w", stdout); 
    int n, test = 0;
    while (scanf ("%d", &n) != EOF && n){
        CLR (num);
        for (int i = 0; i < n; ++ i)
            pre[i].clear();
        int a, b;
        while (scanf ("%d%d", &a, &b) != EOF && a){
            -- a; -- b;
            ++ num[a]; 
            pre[b].PB(a);
        }

        CLR (A);
        A[0][n] = 1;
        for (int i = 0; i < n; ++ i){
            A[i][i] = 1;
            for (int j = 0; j < SZ(pre[i]); ++ j){
                int flag = pre[i][j];
                A[i][flag] -= 1.0 / (num[flag] + 0.0);
            }
        }

        gauss_jordan(n);
        CLR (inf);
        for (int i = n-1; i >= 0; -- i){
            if (fabs(A[i][i]) < eps && fabs(A[i][n]) > eps) inf[i] = 1;
            for (int j = i+1; j < n; ++ j)
                if (fabs(A[i][j]) > eps && inf[j]) inf[i] = 1;
        }

        int q;
        scanf ("%d", &q);
        printf ("Case #%d:\n", ++test);
        while (q--){
            int t;
            scanf ("%d", &t); -- t;
            if (inf[t]) printf ("infinity\n");
            else printf ("%.3lf\n", fabs(A[t][t])<eps ? 0.0 : (A[t][n]/A[t][t]));
        }
    }
    return 0;
}


