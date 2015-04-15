/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/2/22 20:02:28
 * File Name: 1419.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/*head*/
int main() {
        int _; scanf("%d", &_);
        for(int n; _--; ) {
                scanf("%d", &n);
                int top = 0, stk[144], score[2] = {0,0};
                bool flag;
                for(int i = 0, t, j; i < n; ++i) {
                        scanf("%d", &t);
                        flag = 0;
                        for(j = top-1; j >= 0; --j) if(stk[j] == t) {
                                flag = 1; score[i&1] += top - j + 1; top = j; break;
                        }
                        if(!flag) stk[top++] = t;
                }
                puts(score[0] > score[1] ? "xay" : "amr");
        }
        return 0;
}
