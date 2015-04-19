/*
 * Author:  Plumrain
 * Created Time:  2013-09-08 14:00
 * File Name: 1010.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl

const int N = 5000000;

bool vis[N+1];
int prm[N+1];
int pos[N/5+1];

void sieve(int n)
{
    int m = (int)sqrt(n + 0.5);
    CLR (vis);
    for (int i = 2; i <= m; ++ i) if (!vis[i])
        for (int j = i*i; j <= n; j += i) vis[j] = 1;
}

int primes(int n)
{
    sieve(n);
    int ret = 0;
    for (int i = 2; i <= n; ++ i)
        if (!vis[i]) prm[ret++] = i;
    return ret;
}

int main()
{
    int all = primes(N);
    vis[1] = 1;

    int tmp = 78498;
    for (int i = N/5; i >= 1; -- i){
        if (vis[i]) pos[i] = tmp; 
        else pos[i] = tmp--;
    }

    int T;
    scanf ("%d", &T);
    while (T--){
        int n;
        bool flag = true;
        scanf ("%d", &n);
        if (n == 0){ 
            printf ("2 2\n"); 
            continue;
        }
        if (n < 0){
            flag = false;
            n = 0 - n;
        }
        int x = pos[n], ans = -1;
        while (x < all){
            int q = prm[x] - n;
            if (!vis[q]){
                ans = q;
                break; 
            }
            ++ x;
        }
        if (ans == -1) printf ("FAIL\n");
        else{
            if (flag) printf ("%d %d\n", ans+n, ans);
            else printf ("%d %d\n", ans, ans+n);
        }
    }
    return 0;
}
