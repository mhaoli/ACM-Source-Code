/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/2 15:57:57
 * File Name: 1315.cpp
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
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int calc(long long p, int n, int mod) {
        long long ret = 1;
        for(; n; n >>= 1) {
                if(n & 1) ret = ret * p % mod;
                p = p * p % mod;
        }
        return ret;
}
int main()
{
        for(int a, b, c; scanf("%d%d%d", &a, &b, &c); ) {
                if(a + b + c == 0) break;
                printf("%d\n", calc(a, b, c));
        }
        return 0;
}
