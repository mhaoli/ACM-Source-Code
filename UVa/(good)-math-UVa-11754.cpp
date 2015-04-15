/*
 * Author:  Plumrain
 * Created Time:  2013-09-04 13:10
 * File Name: math-UVa-117542.cpp
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define PB push_back
#define SZ(v) ((int)(v).size())

typedef long long int64;

const int Limit = 10000;

int n, m;
int64 a[10][105], x[10];
int64 pro;
set<int64> b[10];
vector<int64> ans;

int init(int64& tot)
{
    int ret = 0;
    pro = 1; tot = 1;
    for (int i = 0; i < n; ++ i){
        scanf ("%lld%lld", &x[i], &a[i][0]);
        pro *= x[i]; tot *= a[i][0];
        for (int j = 1; j <= a[i][0]; ++ j)
            scanf ("%lld", &a[i][j]);
        sort(a[i]+1, a[i]+a[i][0]+1);

        if ((double)(a[i][0] / x[i]) < (double)(a[ret][0] / x[ret]))
            ret = i;
    }
    return ret;
}

void gao1(int flag)
{
    for (int i = 0; i < n; ++ i) if (i != flag){
        b[i].clear();
        for (int j = 1; j <= a[i][0]; ++ j)
            b[i].insert(a[i][j]);
    }

    for (int t = 0; m != 0; ++ t)
        for (int i = 1; i <= a[flag][0]; ++ i){
            int64 tmp = t * x[flag] + a[flag][i];

            bool ok = true;
            for (int j = 0; j < n; ++ j) if (j != flag){
                if (!b[j].count(tmp % x[j])){
                    ok = false; break;
                }
            }

            if (ok){
                if (!tmp) continue;
                printf ("%lld\n", tmp);
                if (--m == 0) break;
            }
        }
}

void DFS(int d, int64 v)
{
    if (d == n){ 
        v %= pro;
        if (v < 0) v += pro;
        ans.PB(v);
        return ;
    }

    for (int i = 1; i <= a[d][0]; ++ i)
        DFS(d+1, (v + a[d][i]) % pro);
}

void ext_gcd(int64 a, int64 b, int64& d, int64 &x, int64& y)
{
    if (!b) d = a, x = 1, y = 0;
    else{
        ext_gcd(b, a%b, d, y, x);
        y -= x * (a / b);
    }
}

void gao2()
{
    for (int i = 0; i < n; ++ i){ 
        int64 w = pro / x[i];
        int64 d, xx, y;
        ext_gcd (x[i], w, d, xx, y);
        int64 tmp = (w * y) % pro;
        for (int j = 1; j <= a[i][0]; ++ j)
            a[i][j] = (a[i][j] * tmp) % pro;
    }

    ans.clear();
    DFS(0, 0);

    sort(ans.begin(), ans.end());
    if (ans[0] != 0)
        printf ("%lld\n", ans[0]), -- m;
    int64 tmp = ans[0], add = 0;
    int fla = 1, size = SZ (ans);
    while (m > 0){
        if (fla == size)
            fla = 0, add += pro;
        if (ans[fla] + add == tmp || ans[fla] + add == 0){
            ++ fla; continue;
        }

        tmp = ans[fla] + add;
        printf ("%lld\n", tmp);
        ++ fla; -- m;
    }
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF && n && m){    
        int64 tot;
        int flag = init (tot);

        if (tot > Limit) gao1 (flag); 
        else gao2 ();
        printf ("\n");
    }
    return 0;
}
