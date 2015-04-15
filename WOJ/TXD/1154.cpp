/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/2/17 23:24:28
 * File Name: 1154.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/*head*/
char s[55];
void transform(char *s) {
        for(bool u = 0; s[0]; ++s, u ^= 1) {
                if(u) s[0] += 'A' - 'a';
        }
}
int main() {
        int cas = 0;
        while(scanf("%s", s) != EOF && s[0] != '#') {
                transform(s);
                printf("Case %d: %s\n", ++cas, s);
        }
        return 0;
}
