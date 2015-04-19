/*
 * Author:  OpenRainbow
 * Created Time:  2014/8/19 14:59:24
 * File Name: 1001.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>

using namespace std;

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 5005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int a[maxn], c[maxn], idx[maxn];
int64 s1[maxn], s2[maxn];
int d[maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    while (~scanf ("%d", &n) && n){
        rep (i, 0, n-1) scanf ("%d", a+i);
        rep (i, 1, n) scanf ("%d", c+i);
        rep (i, 0, n-1) s1[i] = (i ? s1[i-1] + a[i] : a[i]);
        red (i, n-1, 0) s2[i] = (i == n-1 ? a[i] : s2[i+1] + a[i]);

        clr (idx, -1);
        rep (i, 0, n-1) red (j, n-1, i+1) if (s1[i] == s2[j]){
            idx[i] = j; break;
        }

        clr (d, 127);
        int ans = c[n];
        rep (i, 0, n-1) if (idx[i] != -1){
            chmin (d[i], c[i+1] + c[n-idx[i]]);
            rep (j, 0, i-1) if (idx[j] != -1){
                int tmp = d[j] + c[i-j];
                tmp += c[idx[j]-idx[i]];
                chmin (d[i], tmp);
            }
            chmin (ans, d[i] + c[idx[i] - i - 1]);
        }
        printf ("%d\n", ans);
    }
    return 0;
}
