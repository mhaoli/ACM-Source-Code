/*
 * Author:  Plumrain
 * Created Time:  2013-10-22 13:39
 * File Name: math-POJ-1595.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
const int N = 1500;
typedef vector<int> VI;
bool vis[N+5];
int prm[N+5], all;

void sieve(int n)
{
    CLR (vis);
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= n; ++ i) if (!vis[i])
        for (int j = i*i; j <= n; j += i) vis[j] = 1;
}

int primes(int n)
{
    sieve(n);
    prm[0] = 1;
    int ret = 1;
    for (int i = 2; i <= n; ++ i)
        if (!vis[i]) prm[ret++] = i;
    return ret;
}

int bin_search(int n)
{
    int l = 0, r = all - 1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (prm[mid] < n) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main()
{
    all = primes(N);
    int n, c;
    while (scanf ("%d%d", &n, &c) != EOF){
        int pos = bin_search(n);
        while (prm[pos] > n) -- pos;
        VI cur; cur.clear();
        if (pos & 1){
            int l = pos / 2, r = pos / 2 + 1, t = 0;
            while (t < c){
                if (l >= 0) cur.PB(l); 
                if (r <= pos) cur.PB(r);
                -- l; ++ r; ++ t;
            }
        }
        else{
            int l = pos/2 - 1, r = pos/2 + 1, t = 1;
            cur.PB(pos/2);
            while (t < c){
                if (l >= 0) cur.PB (l);
                if (r <= pos) cur.PB (r);
                -- l; ++ r; ++ t;
            }
        }

        sort(cur.begin(), cur.end());
        printf ("%d %d:", n, c);
        for (int i = 0; i < cur.size(); ++ i)
            printf (" %d", prm[cur[i]]);
        printf ("\n\n");
    }
    return 0;
}
