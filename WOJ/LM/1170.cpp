//
//  main.c
//  1170
//
//  Created by ÂÞÃÎ on 15/2/28.
//  Copyright (c) 2015Äê ÂÞÃÎ. All rights reserved.
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

int a[3000010];

void solve() {
        int n = 0;
        while(scanf("%d", a + n), a[n++]);
        n--;
        sort(a, a + n);
        printf("%d ", a[0]);
        for(int i = 1; i < n; ++i) if(a[i] != a[i-1]) printf("%d ", a[i]);
}

int main() 
{
        return solve(), 0;
}
