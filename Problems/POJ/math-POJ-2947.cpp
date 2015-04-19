/*
 * Author:  Plumrain
 * Created Time:  2013-10-07 16:41
 * File Name: math-POJ-2947.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

const int N = 300;

int a[N+5][N+5], x[N+5];
char ann[7] = {'O', 'U', 'E', 'H', 'R', 'A', 'U'};

inline int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

inline int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int change(char a, char b)
{
    for (int i = 0; i < 7; ++ i)
        if (i != 1 && i != 6 && ann[i] == b) return i;
    if (a == 'T') return 1;
    return 6;
}

void init(int equ, int var)
{
    CLR (a);
    char s1[10], s2[10];
    int k;
    for (int i = 0; i < equ; ++ i){
        scanf ("%d%s%s", &k, s1, s2);
        a[i][var] = (change(s2[0], s2[1]) - change(s1[0], s1[1]) + 1) % 7;
        if (a[i][var] < 0) a[i][var] += 7;
        int tmp;
        while (k--){
            scanf ("%d", &tmp);
            ++ a[i][tmp-1];
            if (a[i][tmp-1] == 7) a[i][tmp-1] = 0;
        }
    }
}

int gauss(int equ, int var)
{
    int row = 0, col = 0;
    while (row < equ && col < var){
        int flag = row;
        for (int i = row+1; i < equ; ++ i)
            if (abs(a[i][col]) > abs(a[flag][col]))
                flag = i;
        if (flag != row) for (int i = col; i <= var; ++ i)
            swap (a[row][i], a[flag][i]);
        if (!a[row][col]){ ++ col; continue;}

        for (int i = row+1; i < equ; ++ i){
            if (a[i][col] == 0) continue;

            int tmp = lcm(abs(a[i][col]), abs(a[row][col]));
            int ta = tmp / abs(a[i][col]);
            int tb = tmp / abs(a[row][col]);
            if (a[i][col] * a[row][col] < 0) tb = -tb;
            for (int j = col; j <= var; ++ j){
                a[i][j] = (a[i][j] * ta - a[row][j]*tb) % 7;
                if (a[i][j] < 0) a[i][j] += 7;
            }
        }
        ++ row; ++ col;
    }
    
    for (int i = row; i < equ; ++ i)
        if (a[i][var]) return -1;
    if (row < var) return var - row;
    for (int i = var-1; i >= 0; -- i){
        int tmp = a[i][var];
        for (int j = i+1; j < var; ++ j)
            tmp = ((tmp - a[i][j]*x[j])%7 + 7) % 7;
        while (tmp % a[i][i] != 0) tmp += 7;
        x[i] = (tmp / a[i][i]) % 7;
    }
    return 0;
}

int main()
{
    int equ, var;
    while (scanf ("%d%d", &var, &equ) != EOF && equ){
        init(equ, var);

        int ans = gauss(equ, var);
        if (!ans){
            for (int i = 0; i < var; ++ i)
                if (x[i] <= 2) x[i] += 7;
            for (int i = 0; i < var-1; ++ i)
                printf ("%d ", x[i]);
            printf ("%d\n", x[var-1]);
        }
        else if (ans == -1)
            printf ("Inconsistent data.\n");
        else
            printf ("Multiple solutions.\n");
    }
    return 0;
}
