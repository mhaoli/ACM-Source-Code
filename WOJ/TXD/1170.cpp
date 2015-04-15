/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/5 18:54:16
 * File Name: 1170.cpp
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
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
void Read(int&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
/*head*/

const int Max_N = 9 + (int)2e6;
int a[Max_N];
int main()
{
        int n = 0;
        for(int t; Read(t), t; a[n++]=t);
        sort(a, a + n);
        n = unique(a, a + n) - a;
        for(int i = 0; i < n; ++i) printf("%d%c", a[i], " \n"[i==n]);
        return 0;
}
