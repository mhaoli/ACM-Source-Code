/*
 * Author:  Plumrain
 * Created Time:  2013-11-29 23:53
 * File Name: B.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
int num[1000005];

void gao(int n, int s, int xa, int xb, int& a, int& b)
{
    for (int i = 0; i <= n; ++ i){
        int sum = xa * i + xb * (n-i);
        if (sum == s){
            a = i; b = n - i;
            return;
        }
    }
}

int main()
{
    int n, k, l, r, s, sk;
    while (scanf ("%d%d%d%d%d%d", &n, &k, &l, &r, &s, &sk) != EOF){
        CLR (num);
        for (int i = 0; i < 2; ++ i){
            if (sk % k == 0) num[sk/k] += k; 
            else{
                int a, b;
                gao(k, sk, sk/k, sk/k+1, a, b);
                num[sk/k] += a; num[sk/k+1] += b;
            }
            k = n - k; sk = s - sk;
            if (!k) break;
        }
        bool xxx = 0;
        for (int i = 0; i < 1000005; ++ i){
            while (num[i]){
                -- num[i];
                if (xxx) printf (" ");
                printf ("%d", i);
                xxx = 1;
            }
        }
        printf ("\n");
    }
    return 0;
}
