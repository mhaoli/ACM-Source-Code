/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 10.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

#define clr0(x) memset(x, 0, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl

typedef long long int64;
const int N = 2000000;
bool v[N+1];
void sieve(int n)
{
    int m = (int)sqrt(n + 0.5);
    clr0 (v); v[0] = v[1] = 1;
    for (int i = 2; i <= m; ++ i) if (!v[i])
        for (int j = i*i; j <= n; j += i) v[j] = 1;
}
int main()
{
    sieve(N);
    int64 ans = 0;
    for (int i = 2; i < N; ++ i) if (!v[i]) ans += i;
    out (ans);
    return 0;
}
