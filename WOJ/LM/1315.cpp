//
//  main.c
//  1315
//
//  Created by 罗梦 on 15/2/28.
//  Copyright (c) 2015年 罗梦. All rights reserved.
//
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

template<class T> T mabs(T a){return a>0?a:-a;}
template<class T> T mmin(T a,T b){return a<b?a:b;}
template<class T> T mmax(T a,T b){return a>b?a:b;}

#define MIMIN 0xffffffff
#define MIMAX 0x7fffffff

typedef unsigned long long ulli;
typedef vector<vector<int> > mint;

long long mul(long long p, long long t, long long mod) {
        return (p % mod) * (t % mod) % mod;
}

void solve() 
{
        long long p, n, mod;
        if(scanf("%lld%lld%lld", &p, &n, &mod), !(p + n + mod)) return;
        long long ret = 1;
        for(; n; n /= 2) {
                if(n % 2 == 1) ret = mul(ret, p, mod);
                p = mul(p, p, mod);
        }
        printf("%d\n", (int)ret);
        solve();
}

int main() 
{
        return solve(), 0;
}
