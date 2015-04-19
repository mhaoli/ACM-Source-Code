/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/2/18 9:39:53
 * File Name: 1314.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/*head*/
const int Max_N = 9 + (int)5e6;
//int dp[Max_N];
int dfs(int x) {
        if(x == 1) return 1;
        return dfs((x & 1) ? 3*x+1 : x/2) + 1;
}
int main() {
        //dp[1] = 1;
        int l, r, ans;
        while(scanf("%d%d", &l, &r) != EOF && l + r) {
                ans = 0;
                for(int i = l; i <= r; ++i) chmax(ans, dfs(i));
                printf("%d\n", ans);
        }
        return 0;
}
