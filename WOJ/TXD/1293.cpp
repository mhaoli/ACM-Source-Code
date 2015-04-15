/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/2/18 9:26:38
 * File Name: 1293.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/*head*/
std::vector<int> vec[222];
int main() {
        int n, m;
        while(scanf("%d%d", &m, &n) != EOF && n + m) {
                for(int i = 0; i < n; ++i) vec[i].clear();
                for(int j, i = n-1; i >= 0; --i) {
                        for(j = 0; j < n-i; ++j) {
                                vec[i+j].push_back(m++);
                        }
                }
                for(int i = 0; i < n; ++i) {
                        snuke(it, vec[i]) printf("%2d ", *it);
                        puts("");
                }
                puts("");
        }
        return 0;
}
