/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/5 19:07:44
 * File Name: 1290.cpp
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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
void Read(int&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
/*head*/

const int Max_N = 9 + (int)1e5;
int a[Max_N];

int main()
{
        for(int n, i, j, ans; Read(n), n; ) {
                for(i = 0; i < n; ++i) Read(a[i]);
                ans = 0;
                for(i = 0; i < n; ++i) for(j = i+1; j < n; ++j) if(a[i]>a[j]) ++ans;
                printf("%d\n", ans);
        }
        return 0;
}
