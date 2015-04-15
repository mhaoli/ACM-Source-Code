/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/2/17 22:50:59
 * File Name: 1040.cpp
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/*head*/
int a[9 + (int)1e4];
int main() {
        int _; scanf("%d", &_);
        for(int n; _--; ) {
                scanf("%d", &n);
                for(int i = 0; i < n; ++i) scanf("%d", a + i);
                std::sort(a, a + n);
                int cnt = 1, ans = 0;
                for(int i = 1; i < n; ++i) {
                        if(a[i] == a[i-1]) ++cnt;
                        else {
                                ans = std::max(ans, cnt);
                                cnt = 1;
                        }
                }
                printf("%d\n", std::max(ans, cnt));
        }
        return 0;
}
