/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/2/17 23:21:16
 * File Name: 1143.cpp
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
int main() {
        int m, p, n;
        while(scanf("%d%d%d", &m, &p, &n) != EOF && m + p + n) printf("%d\n", std::max(m, p*n));
        return 0;
}
