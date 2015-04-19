/*
 * Author:  Plumrain
 * Created Time:  2014/8/2 17:04:56
 * File Name: JJ.cpp
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

void ext_gcd(int64 a, int64 b, int64& d, int64& x, int64& y)
{
    if (!b) d = a, x = 1, y = 0;
    else{
        ext_gcd (b, a%b, d, y, x);
        y -= x * (a / b);
    }
}

int64 inv(int64 a, int64 mod)
{
    int64 d, x, y;
    ext_gcd(a, mod, d, x, y);
    return d == 1 ? (x+mod)%mod : -1;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int64 x, y, sum;
    while (cin >> x >> y >> sum && (x + y + sum)){
        if (x + y == 0){
            puts ("Unquibable!"); continue;
        }
        if (x == 0){
            if (sum % y != 0) puts ("Unquibable!");
            else if ((sum / y) != 1) printf ("0 fooms and %lld foobs for a twob!\n", sum/y);
            else printf ("0 fooms and %lld foob for a twob!\n", sum/y);
            continue;
        }
        if (y == 0){
            if (sum % x != 0) puts ("Unquibable!");
            else if ((sum / x) != 1) printf ("%lld fooms and 0 foobs for a twob!\n", sum/x);
            else printf ("%lld foom and 0 foobs for a twob!\n", sum/x);
            continue;
        }

        int64 a, b, d;
        ext_gcd (x, y, d, a, b);
        if (sum % d != 0){
            puts ("Unquibable!"); continue;
        }

        sum /= d; x /= d; y /= d;
        int64 ty = inv (y, x);
        b = ((sum % x) * ty) % x;
        a = (sum - b * y) / x;

        //x *= d; y *= d;
        if (a < 0){
            int64 tmp = -1 * (a / y); a += tmp * y; b -= tmp * x;
            if (a < 0) a += y, b -= x;
            if (b < 0){ puts ("Unquibable!"); continue; }
        }
        if (b < 0){
            int64 tmp = -1 * (b / x); b += tmp * x; a -= tmp * y;
            if (b < 0) b += x, a -= y;
            if (a < 0){ puts ("Unquibable!"); continue; }
        }

        if (x > y){
            int64 tmp = b / x; b %= x; a += tmp * y;
        }
        else if (x < y){
            int64 tmp = a / y; a %= y; b += tmp * x;
        }

        printf ("%lld ", a);
        if (a == 1) printf ("foom");
        else printf ("fooms");
        printf (" and %lld ", b);
        if (b == 1) printf ("foob");
        else printf ("foobs");
        puts (" for a twob!");
    }
    return 0;
}
