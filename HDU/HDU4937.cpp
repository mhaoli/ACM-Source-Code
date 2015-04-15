/*
 * Author:  Plumrain
 * Created Time:  2014/8/12 15:21:50
 * File Name: 1003.cpp
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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int an[] = {3, 4, 5, 6};

int ok (int64 n){
    repf (i, 0, 3) if (an[i] == n) return 1;
    return 0;
}

int ok3 (int64 k, int64 n){
    if (k < 4) return 0;
    while (n){
        int64 t = n % k;
        if (t > 6 || t < 3) return 0;
        n /= k;
    }
    return 1;
}

int ok2 (int x, int y, int64 n){
    if ((n - x) % y) return 0;
    int64 k = (n - x) / y;
    if (k > inf) return ok3 (k, n);

    if (1LL * k * k <= n) return 0;
    if (k > n) return 0;

    return ok3 (k, n);
}

int ok4 (int x, int y, int z, int64 n){
    int64 l = 4, r = sqrt (n + 0.5);
    while (l <= r){
        int64 m = (l + r) >> 1;
        int64 tmp = x + y*m + z*m*m;
        if (tmp == n){
            if (m * m > n) return 0;
            if (m * m * m <= n) return 0;
            return ok3 (m, n);
        }
        if (tmp < n) l = m + 1;
        else r = m - 1;
    }
    return 0;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("my.out","w",stdout);
    repcase{
        printf ("Case #%d: ", ++ cas);

        int64 n; scanf ("%I64d", &n);
        if (ok (n)){
            puts ("-1"); continue;
        }
        int ans = 0;
        repf (i, 0, 3) repf (j, 0, 3) if (ok2 (an[i], an[j], n)) ++ ans; 
        repf (i, 0, 3) repf (j, 0, 3) repf (k, 0, 3) if (ok4 (an[i], an[j], an[k], n)) ++ ans;
        repf (k, 4, 2000000){
            if (1LL * k * k * k > n) break;
            if (ok3 (k, n)) ++ ans;
        }
        printf ("%d\n", ans);
    }
    return 0;
}
