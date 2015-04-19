/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/7 19:40:07
 * File Name: 1319.cpp
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
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
const int Max_N = 9 + (int)1e5;
int stk[Max_N];
int main() {
        int _; scanf("%d", &_);
        for(int n, top; _--; ) {
                scanf("%d", &n);
                top = 0;
                if(!n) puts("0");
                else {
                        for(int t; n; n /= 3) {
                                t = n % 3; if(t < 0) t += 3;
                                stk[top++] = t;
                                if(t == 2) ++n;
                                else if(t == 1) --n;
                        }
                        for(; top; --top) printf("%c", stk[top-1] == 2 ? '-' : stk[top-1] + '0');
                        puts("");
                }
        }
        return 0;
}
