/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/2/17 23:00:33
 * File Name: 1055.cpp
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
char s[11], e[11], c[222];
int main() {
        freopen("a.in","r",stdin);
        freopen("a.out","w",stdout);
        gets(s);
        while(!strcmp(s, "START")) {
                gets(c); gets(e);
                for(int i = 0; c[i]; ++i) {
                        if(c[i] >= 'A' && c[i] <= 'Z') {
                                c[i] = (((c[i] - 'A') - 5) + 5 * 26)% 26 + 'A';
                        }
                        printf("%c", c[i]);
                }
                puts("");
                gets(s);
        }
        return 0;
}
