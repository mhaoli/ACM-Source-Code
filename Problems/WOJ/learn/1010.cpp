/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/7 19:53:16
 * File Name: 1010.cpp
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
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int pow_mod(int p,int n, int mod){int ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
const int mod = 2006;
int a[1111];
int main() {
        int n;
        for(int ans; scanf("%d", &n), n; ) {
                for(int i = 0; i < n; ++i) scanf("%d", a + i);
                sort(a, a + n, greater<int>());
                ans = a[0] * pow_mod(2, n-1, mod) % mod;
                if(ans < 0) ans += mod;
                printf("%d\n", ans);
        }
        return 0;
}
