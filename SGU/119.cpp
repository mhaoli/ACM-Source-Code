/*
 * Author:  Plumrain
 * Created Time:  2014/6/17 13:49:56
 * File Name: 119.cpp
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
typedef vector<int64> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int64, int64> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

void ext_gcd (int64 a, int64 b, int64 &d, int64 &x, int64 &y){
    if (!b) d = a, x = 1, y = 0;
    else{
        ext_gcd (b, a%b, d, y, x);
        y -= x * (a / b);
    }
}

int64 inv (int64 a, int64 mod){
    int64 d, x, y;
    ext_gcd (a, mod, d, x, y);
    return d == 1 ? (x+mod)%mod : -1;
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("119.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int64 n, a0, b0;
    while (cin >> n >> a0 >> b0){
        vector<pii > ans;
        int64 gd = __gcd (n, __gcd (a0, b0));
        a0 /= gd; n /= gd; b0 /= gd;

        if (n != 1){
            int64 gd2 = __gcd (a0, n), nn = n;
            a0 /= gd2; n /= gd2;
            int64 _a = inv (a0, n) * b0 % n;
            repf (i, 0, n-1){
                int64 _b = _a * i % n;
                while (_b < nn) ans.pb (mp (gd*gd2*i, gd*_b)), _b += n;
            }
        }
        else ans.pb (mp (0LL, 0LL));
        sort (all (ans));
        ans.erase (unique (all (ans)), ans.end());
        cout << sz(ans) << endl;
        repf (i, 0, sz(ans)-1) cout << ans[i].x << " " << ans[i].y << endl;
    }
    return 0;
}
