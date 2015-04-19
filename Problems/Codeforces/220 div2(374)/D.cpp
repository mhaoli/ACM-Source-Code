/*
 * Author:  Plumrain
 * Created Time:  2013-12-24 14:19
 * File Name: D.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define clr0(x) memset(x, 0, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
const int inf = 2147483647 / 2;
const int N = 1000005;
typedef vector<int> vi;

int n, m;
int opt[N];
int an[N], d[N], flag[N];

int bin_search(int x)
{
    int l = 0, r = m-1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (an[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF){
        clr0 (d); clr0 (flag);
        for (int i = 0; i < m; ++ i)
            scanf ("%d", &an[i]);
        int idx = 0, p = 1, num = 0;
        while (idx < m){
            if (!idx && p != an[0]) d[p] = inf;
            else{
                if (p == an[idx]){
                    d[p] = 1;
                    ++ num; ++ idx;
                }
                else d[p] = d[p-num] + 1;
            }
            ++ p;
        }
        for (int i = p; i <= 1000000; ++ i)
            d[i] = d[i-num] + 1;
        
        int len = 0;
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &opt[i]);
            if (opt[i] == -1) len -= 1 + bin_search(len);
            else flag[i] = d[++len];
        }
        vi v;
        int cnt = 0;
        for (int i = n-1; i >= 0; -- i){
            if (opt[i] == -1) ++ cnt;
            else if (flag[i] > cnt) v.pb (opt[i]);
        }

        if (!sz(v)) printf ("Poor stack!");
        else for (int i = sz(v)-1; i >= 0; -- i)
            printf ("%d", v[i]);
        printf ("\n");
    }
    return 0;
}
