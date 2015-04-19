/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/8 20:52:38
 * File Name: 1152.cpp
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
pair<int, int> a[5000009];
int main() {
        for(int n, K; scanf("%d%d", &n, &K) != EOF; ) {
                for(int i = 0; i < n; ++i) {
                        scanf("%d", &a[i].first);
                        a[i].second = i + 1;
                }
                sort(a, a + n);
                printf("%d\n", a[K-1].first);
        }
        return 0;
}
