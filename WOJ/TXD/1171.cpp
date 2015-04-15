/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/8 21:23:46
 * File Name: 1171.cpp
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
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
bool vis[22][22][22];
int dp[22][22][22];
int calc(int a, int b, int c) {
        if(a <= 0 || b <= 0 || c <= 0) return 1;
        if(a > 20 || b > 20 || c > 20) return calc(20, 20, 20);
        int &ret = dp[a][b][c];
        if(vis[a][b][c]) return ret;
        vis[a][b][c] = 1;
        if(a < b && b < c) {
                ret = calc(a, b, c-1) + calc(a, b-1, c-1) - calc(a, b-1, c);
                return ret;
        } else {
                ret = calc(a-1, b, c) + calc(a-1, b-1, c) + calc(a-1, b, c-1) - calc(a-1, b-1, c-1);
                return ret;
        }
}
int main() {
        int _; scanf("%d", &_);
        for(int a, b, c; _--; ) {
                scanf("%d%d%d", &a, &b, &c);
                printf("W(%d, %d, %d) = %d\n", a, b, c, calc(a, b, c));
        }
        return 0;
}
