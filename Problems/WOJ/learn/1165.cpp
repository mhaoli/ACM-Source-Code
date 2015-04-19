/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/8 21:15:48
 * File Name: 1165.cpp
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
vector<int> vec;
int calc(int n) {
        int ret = 0;
        for(; n; n /= 10) ret += n % 10;
        return ret;
}
int main() {
        for(int n; scanf("%d", &n), n; ) {
                vec.clear();
                int tmp = calc(n);
                bool u = 0;
                for(int i = 2; i * i <= n; ++i) {
                        while(n % i == 0) u = 1, n /= i, vec.push_back(i);
                }
                if(n != 1) vec.push_back(n);
                snuke(it, vec) tmp -= calc(*it);
                puts(!u || tmp ? "No" : "Yes");
        }
        return 0;
}
