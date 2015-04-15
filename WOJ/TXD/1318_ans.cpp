/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/2 14:04:31
 * File Name: 1318.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
typedef long long ll;
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
const int Max_N = 255;
bool check[Max_N+5];
int prm[Max_N+5];

int primes(int n){
    clr(check, 0);
    int tot = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[tot++] = i;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
    return tot;
}

int tot;
long long ans;
bool vis[255];
void dfs(int n, int p, long long res) {
        if(p == tot || prm[p] > n) {
                if(n != 1 || (vis[2] && vis[3])) chmax(ans, res); return;
        }
        dfs(n, p+1, res);
        for(int i = prm[p]; i <= n; i *= prm[p]) {
                if(i <= 250) vis[i] = 1;
                dfs(n - i, p+1, res * i);
                if(i <= 250) vis[i] = 0;
        }
}
long long res[255];
int main()
{
        freopen("my.out","w",stdout);
        tot = primes(Max_N - 2);
        for(int i = 2; i <= 250; ++i) {
                ans = i; dfs(i, 0, 1);
                res[i] = ans;
        }
        for(int i = 1; i <= 250; ++i) printf("%I64d,", res[i]);
        return 0;
}
