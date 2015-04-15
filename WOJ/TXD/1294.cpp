/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/2/18 9:35:04
 * File Name: 1294.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
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
int b[111];
int main() {
        int _; scanf("%d", &_);
        for(int n; _--; ) {
                b[0] = b[1] = 0;
                b[2] = b[3] = 2;
                scanf("%d", &n);
                int dble = n << 1, sum;
                for(int i = 4; i <= dble; ++i)
                        b[i] = b[i-1] + (b[i-2] << 1);
                sum = 3 * b[dble] / 2 + b[dble-1];
                printf("%d\n", sum);
        }
        return 0;
}
