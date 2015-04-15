/*
 * Author:  Plumrain
 * Created Time:  2014/7/12 19:04:15
 * File Name: 180.cpp
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

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define lowbit(x) ((x)&(-x))
#define all(t) t.begin(),t.end()
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 65550;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int c[maxn], an[maxn], bn[maxn];
map<int, int> has;

void add(int x, int d)
{
    while (x < maxn) c[x] += d, x += lowbit(x);
}

int sum(int x)
{
    int ret = 0;
    while (x > 0) ret += c[x], x -= lowbit(x);
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    repf (i, 0, n-1) scanf ("%d", an+i), bn[i] = an[i];

    sort (bn, bn+n);
    int idx = 1;
    has.clear(); has[bn[0]] = idx++;
    repf (i, 1, n-1) if (bn[i] != bn[i-1]) has[bn[i]] = idx ++;

    int64 ans = 0;
    repf (i, 0, n-1){
        int t = has[an[i]];
        ans += i - sum (t);
        add (t, 1);
    }
    cout << ans << endl;
    return 0;
}
