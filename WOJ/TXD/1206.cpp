/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/2 16:37:51
 * File Name: 1206.cpp
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
int main()
{
        int a, b, c;
        while(scanf("%d%d%d", &a, &b, &c) != EOF) {
                if(!a && !b) puts(c ? "Impossible!" : "Possible!");
                else {
                        int t = __gcd(a, b);
                        puts(abs(c)%t == 0 ? "Possible!" : "Impossible!");
                }
        }
        return 0;
}
