/*
 * Author:  Plumrain
 * Created Time:  2014-01-17 10:15
 * File Name: 21.cpp
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
const int N = 100005;
typedef vector<int> vi;
typedef long long int64;
int d[N];
int gao(int x)
{
    vi fac;
    for (int64 i = 2; i*i <= x; ++ i) if((x % i) == 0){
        fac.pb ((int)i);
        if (i*i != x) fac.pb (x/i);
    }
    int num = 1;
    for (int i = 0; i < sz(fac); ++ i) num += fac[i];
    return num;
}
int main()
{
    clr0 (d);
    for (int i = 2; i < N; ++ i) d[i] = gao(i);
    int num = 0;
    for (int i = 1; i < 10000; ++ i){
        int t = d[i];
        if (t > 100005) out (t);
        if (t != i && d[t] == i) num += i;
    }
    out (num);
    return 0;
}
