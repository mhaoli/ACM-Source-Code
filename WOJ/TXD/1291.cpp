/*
* Author:  Xiaodong Tang
* Created Time:  2015/1/8 21:35:12
* File Name: 1291.cpp
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;
#define pb push_back
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
const int Max_N = 100009;
char s[Max_N], ans[Max_N];
map<char, int> mp;
map<char, int>::iterator it;
void solve(char *s, int &t1, int &t2) {
        t1 = -1; t2 = 0;
        for(int i = 0, mx = -1, len = 1; s[0]; ++i, ++s) {
                it = mp.find(s[0]);
                if(it != mp.end()) chmax(mx, it->second);
                mp[s[0]] = i;
                if(i - mx > len) {
                        len = i - mx;
                        t1 = mx; t2 = i;
                }
        }
}
int main() {
        //freopen("tst.in","r",stdin);
        //freopen("my.out","w",stdout);
        for(int t1, t2, i, j; scanf("%s", s), s[0] != '#'; ) {
                mp.clear();
                solve(s, t1, t2);
                for(i = 0, j = t1+1; j <= t2; ++i, ++j)
                        ans[i] = s[j];
                ans[i] = 0;
                printf("%d ", t2 - t1); puts(ans);
        }
        return 0;
}
