/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/2/17 22:55:30
 * File Name: 1046.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/*head*/
int a[3333];
int main() {
        int _; scanf("%d", &_);
        for(int n; _--; ) {
                scanf("%d", &n);
                for(int i = 0; i < n; ++i) scanf("%d", a + i);
                int ans = 0;
                for(int i = 0, j; i < n; ++i) {
                        for(j = i + 1; j < n; ++j) if(a[j] < a[i]) ++ans;
                }
                printf("%d\n", ans);
        }
        return 0;
}
