/*
 * Author:  Plumrain
 * Created Time:  2014/6/26 13:39:51
 * File Name: 141.cpp
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

void gcd (int64 a, int64 b, int64 &d, int64 &x, int64 &y){
    if (!b) d = a, x = 1, y = 0;
    else{
        gcd (b, a%b, d, y, x);
        y -= x * (a / b);
    }
}

int64 inv(int64 a, int64 mod){
    int64 d, x, y;
    gcd (a, mod, d, x, y);
    return d == 1 ? (x+mod)%mod : -1;
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int64 x1, x2, p, k;
    cin >> x1 >> x2 >> p >> k;
    
    int64 a = x1, b = x2, c = p;
    int64 gd = __gcd(b,a);
    if (c % gd){
        puts ("NO"); return 0;
    }

    a /= gd; b /= gd; c /= gd;
    int64 ty = inv(b, a) * c % a;
    if (ty < 0) ty += a;
    int64 tx = (p - x2*ty) / x1;

    bool ans = 0;
    if (((abs(tx) + abs(ty)) & 1) == (abs(k) & 1)) ans = 1;
    else if (abs(a - b) & 1){
        tx -= b; ty += a; ans = 1;
    }

    if (abs(a-b) & 1) a *= 2, b *= 2;

    if (!ans){
        puts ("NO"); return 0;
    }

    while (abs(ty) + abs(tx) > abs(ty+a) + abs(tx-b)) ty += a, tx -= b;
    while (abs(ty) + abs(tx) > abs(ty-a) + abs(tx+b)) ty -= a, tx += b;

    if (abs(tx) + abs(ty) > k){
        puts ("NO"); return 0;
    }

    puts ("YES");
    int tk = (k - abs(tx) - abs(ty)) / 2;
    if (tx < 0){
        cout << tk << " " << tk - tx << " ";
        cout << (ty<0?0:ty) << " " << (ty<0?(-ty):0) << endl;
    }
    else{
        cout << tk+tx << " " << tk << " ";
        cout << (ty<0?0:ty) << " " << (ty<0?(-ty):0) << endl;
    }
    return 0;
}
