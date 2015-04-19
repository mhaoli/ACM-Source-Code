/*
 * Author:  Plumrain
 * Created Time:  2014/6/28 0:01:30
 * File Name: 140.cpp
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

int64 an[105], gd[105], ans_num[105];

void gcd (int64 a, int64 b, int64 &d, int64 &x, int64 &y){
    if (!b) d = a, x = 1, y = 0;
    else{
        gcd (b, a%b, d, y, x);
        y -= x * (a / b);
    }
}

int64 inv (int64 a, int64 mod){
    int64 d, x, y;
    gcd (a, mod, d, x, y);
    return d == 1 ? (x+mod)%mod : -1;
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int64 n, mod, yu;
    cin >> n >> mod >> yu;
    repf (i, 0, n-1){
        cin >> an[i];
        an[i] %= mod;
        gd[i] = i ? __gcd(an[i],gd[i-1]) : an[0];
    }

    repd (i, n-1, 1){
        int64 d, x, y;
        gcd (gd[i-1], an[i], d, x, y);
        if (y < 0) y += mod; if (x < 0) x += mod; 

        int64 tmod = mod, tgd = __gcd(mod, d), tyu = yu, td = d;
        if (yu % tgd){
            puts ("NO"); return 0;
        }
        tmod /= tgd; tyu /= tgd; td /= tgd;
        int64 tmp = (inv(td, tmod) * tyu % mod) % mod;
        ans_num[i] = y * tmp % mod;

        if (i == 1) ans_num[0] = x * tmp % mod;

        yu = (yu - ans_num[i] * an[i]) % mod;
        if (yu < 0) yu += mod;
    }
    
    if (n == 1){
        int64 tgd = __gcd (an[0], mod);
        if (yu % tgd){
            puts ("NO"); return 0;
        }
        ans_num[0] = (inv (an[0]/tgd, mod/tgd) * (yu/tgd) % (mod/tgd)) % mod;
    }
    
    puts ("YES");
    repf (i, 0, n-1){
        if (i) printf (" ");
        cout << ans_num[i];
    }
    puts ("");
    return 0;
}
