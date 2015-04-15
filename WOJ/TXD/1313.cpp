/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/6 19:11:11
 * File Name: 1313.cpp
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
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int dp[1111];
int main() {
        for(int K; scanf("%d", &K), K; ) {
                memset(dp, -1, sizeof dp);
                int t = 1, i = 0;
                while(t < 1000) ++i, t *= K;
                K %= 1000;
                for(t %= 1000; ; t = t * K % 1000, ++i) {
                        if(~dp[t]) {
                                printf("%d\n", dp[t] + i);
                                break;
                        } else dp[t] = i;
                }
        }
        return 0;
}
