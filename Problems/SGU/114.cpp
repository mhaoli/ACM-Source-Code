/*
 * Author:  Plumrain
 * Created Time:  2014/6/16 18:55:55
 * File Name: 114.cpp
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
const int maxn = 15005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

pii an[maxn], bn[maxn];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, tot = 0;
    scanf ("%d", &n);
    repf (i, 0, n-1){
        scanf ("%d%d", &an[i].x, &an[i].y);
        tot += an[i].y;
    }
    sort (an, an+n);

    repd (i, n-1, 1) if (an[i].x == an[i-1].x) an[i-1].y += an[i].y;
    bn[0] = an[0];
    int tj = 1;
    repf (i, 1, n-1) if (an[i].x != an[i-1].x) bn[tj++] = an[i];
    n = tj;

    int add = bn[0].y, ans = bn[0].x;
    int64 sum = 0, ans_sum;
    repf (i, 1, n-1) sum += 1LL * (bn[i].x - bn[0].x) * bn[i].y;
    ans_sum = sum;
    repf (i, 1, n-1){
        sum += 1LL * (2*add - tot) * (bn[i].x - bn[i-1].x);
        add += bn[i].y;
        if (sum < ans_sum) ans_sum = sum, ans = bn[i].x;
    }
    printf ("%d.00000\n", ans);
    return 0;
}
