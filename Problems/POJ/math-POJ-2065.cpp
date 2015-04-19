/*
 * Author:  Plumrain
 * Created Time:  2013-10-08 13:36
 * File Name: math-POJ-2065.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

const int N = 70;

int a[N+5][N+5], mod, n, x[N+5];

int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

void init()
{
    CLR (a); CLR (x);
    char s[N+5]; CLR (s);
    scanf ("%d%s", &mod, s);
    n = strlen(s);
    for (int i = 0; i < n; ++ i)
        if (s[i] != '*') a[i][n] = s[i] - 'a' + 1;

    for (int i = 0; i < n; ++ i){
        int tmp = 1, tim = 0;
        while (tim < n){
            a[i][tim++] = tmp;
            tmp = (tmp * (i+1)) % mod; 
        }
    }
}

int gauss()
{
    int row = 0, col = 0;
    while (row < n && col < n){
        int flag = row;
        for (int i = row+1; i < n; ++ i)
            if (abs(a[i][col]) > abs(a[flag][col]))
                flag = i;
        if (flag != row) for (int i = col; i <= n; ++ i)
            swap(a[flag][i], a[row][i]);
        if (!a[row][col]) {++ col; continue;}
        
        for (int i = row+1; i < n; ++ i){
            if (!a[i][col]) continue;
            
            int tmp = lcm(abs(a[i][col]), abs(a[row][col]));
            int ta = tmp / abs(a[i][col]);
            int tb = tmp / abs(a[row][col]);
            if (a[i][col] * a[row][col] < 0) tb = -tb;
            for (int j = col; j <= n; ++ j)
                a[i][j] = ((a[i][j] * ta - a[row][j] * tb)%mod + mod) % mod;
        }
        ++ col; ++ row;
    }

    for (int i = n-1; i >= 0; -- i){
        int tmp = a[i][n];
        for (int j = i+1; j < n; ++ j)
            tmp = ((tmp - a[i][j] * x[j]) % mod + mod) % mod;
        if (a[i][i] < 0){a[i][i] = -a[i][i]; tmp = -tmp;}
        while (tmp % a[i][i]) tmp += mod;
        x[i] = (tmp / a[i][i]) % mod;
        if (x[i] < 0) x[i] += mod;
    }
    return 0;
}

int main()
{
    int T;
    scanf ("%d", &T);
    while (T--){
        init(); 

        int ans = gauss();

        for (int i = 0; i < n; ++ i){
            if (i) printf (" ");
            printf ("%d", x[i]);
        }
        printf ("\n");
    }
    return 0;
}
