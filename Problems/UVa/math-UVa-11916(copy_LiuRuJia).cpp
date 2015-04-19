/*
 * Author:  Plumrain
 * Created Time:  2013-09-05 00:18
 * File Name: math-UVa-119162.cpp
 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#include<set>

using namespace std;

#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl

typedef long long int64;

const int mod = 100000007;

int64 n, m, k, b, r, x[510], y[510];
set<pair<int64, int64> > bset;

int64 pow_mod(int64 p, int64 n, int mod)
{
    int64 ret = 1;
    while (n > 0){
        if (n & 1)
            ret = (ret * p) % mod;
        n >>= 1;
        p = (p * p) % mod;
    }
    return ret;
}

void ext_gcd(int64 a,int64 b, int64& d, int64& x, int64& y)
{
    if (!b) d = a, x = 1, y = 0;
    else{
        ext_gcd(b, a%b, d, y, x);
        y -= x * (a / b);
    }
}

int64 inv(int64 a, int n)
{
    int64 d, x, y;
    ext_gcd (a, n, d, x, y);
    return d == 1 ? (x+n)%n : -1;
}

int64 log_mod(int64 a, int64 b, int n)
{
    int64 m = (int64)sqrt(n + 0.5);
    int64 v = inv(pow_mod(a, m, n), n);
    int64 e = 1;
    map<int64, int64> x;
    x[1] = 0;
    for (int i = 1; i < m; ++ i){
        e = (e * a) % n;
        if (!x.count(e)) x[e] = i;
    }
    for (int i = 0; i < m; ++ i){
        if (x.count(b)) return i*m + x[b];
        b = (b * v) % n;
    }
    return -1;
}

int64 count()
{
    int64 c = 0;
    for (int i = 0; i < b; ++ i)
        if (x[i] != m && !bset.count (make_pair(x[i]+1, y[i])))
            ++ c;
    c += n;
    for (int i = 0; i < b; ++ i) 
        if (x[i] == 1) -- c;
    
    return (pow_mod (k, c, mod) * pow_mod (k-1, m*n-b-c, mod)) % mod;
}

int64 doit()
{
    int64 cnt = count();
    if (cnt == r) return m;
    
    int64 c = 0;
    for (int i = 0; i < b; ++ i)
        if (x[i] == m) ++ c;
    ++ m;
    cnt = (cnt * pow_mod(k, c, mod)) % mod;
    cnt = (cnt * pow_mod(k-1, n-c, mod)) % mod;
    if (cnt == r) return m;
    
    return log_mod(pow_mod(k-1, n, mod), (r * inv(cnt, mod)) % mod, mod) + m;
}

int main()
{
    int T;
    scanf ("%d", &T);
    int test = 0;
    while (T--){
        scanf ("%lld%lld%lld%lld", &n, &k, &b, &r);
        bset.clear();
        m = 1;
        for (int i = 0; i < b; ++ i){
            scanf ("%lld%lld", &x[i], &y[i]);
            if (x[i] > m) m = x[i];
            bset.insert (make_pair(x[i], y[i]));
        }
        
        printf ("Case %d: %lld\n", ++test, doit ());
    }
    return 0;
}
