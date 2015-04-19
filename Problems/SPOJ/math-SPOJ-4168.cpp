/*
 * Author:  Plumrain
 * Created Time:  2014-03-28 19:27
 * File Name: math-SPOJ-4168.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
const int maxn = 10000000;

int tot;
bool v[maxn+5];
int cnt[maxn+5];
int64 prm[maxn/10];

void sieve (int n){
    int m = sqrt (n + 0.5);
    repf (i, 2, m) if (!v[i])
        for (int j = i*i; j <= n; j += i) v[j] = 1;
}

int primes (int n){
    sieve (n);
    int ret = 0;
    repf (i, 2, n) if (!v[i]) prm[ret++] = i;
    return ret;
}

void dfs (int p, int64 val, int t){
    if (val > maxn) return;
    cnt[val] = t & 1 ? 1 : -1;
    repf (i, p, tot-1){
        if (val * prm[i] > maxn) break;
        dfs (i+1, val*prm[i], t+1);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    tot = primes (maxn);
    clr (cnt, 0);
    dfs(0, 1LL, 0);

    int T;
    scanf ("%d", &T);
    while (T --){
        int64 n;
        cin >> n;
        int m = sqrt (n + 0.5);
        int64 ans = 0;
        repf (i, 2, m) if (cnt[i])
            ans += cnt[i] * n / ((int64)i*i);
        cout << n - ans << endl;
    }
    return 0;
}
