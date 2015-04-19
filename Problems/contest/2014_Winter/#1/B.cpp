/*
 * Author:  Plumrain
 * Created Time:  2014-02-10 17:12
 * File Name: B.cpp
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, -1, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 100005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int64 n, m, k;
int64 an[N], bn[N];

int64 find(int64 x)
{
    int64 cnt = 0;
    for (int i = 0; i < n; ++ i){
        int64 l = 0, r = m-1;
        while (l <= r){
            int64 mid = (l + r) >> 1;
            if (an[i]*bn[mid] <= x) l = mid + 1;
            else r = mid - 1;
        }
        while (l < m && an[i]*bn[l] < x) ++ l;
        cnt += m - l;
    }
    return cnt;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%lld%lld%lld", &n, &m, &k) != EOF){
        for (int i = 0; i < n; ++ i) scanf ("%lld", &an[i]);
        for (int i = 0; i < m; ++ i) scanf ("%lld", &bn[i]);
        sort (an, an+n); sort (bn, bn+m);
        int64 l = 0, r = an[n-1] * bn[m-1];
        while (l <= r){
            int64 mid = (l + r) >> 1;
            if (find(mid) >= k) l = mid + 1;
            else r = mid - 1;
        }
        printf ("%lld\n", l);
    }
    return 0;
}
