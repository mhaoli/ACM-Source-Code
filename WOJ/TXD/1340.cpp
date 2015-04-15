/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/10 18:53:26
 * File Name: 1340.cpp
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
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
char s1[1111], s2[1111];
void transform(char *s) {
        for(; s[0]; ++s) if(s[0] <= 'Z') s[0] += 'a' - 'A';
}
int main() {
        int _; scanf("%d", &_);
        for(; _--; ) {
                scanf("%s%s", s1, s2);
                transform(s1); transform(s2);
                s1[0] += 'A' - 'a';
                s2[0] += 'A' - 'a';
                printf("%s %s\n", s2, s1);
        }
        return 0;
}
