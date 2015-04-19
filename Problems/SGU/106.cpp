/*
 * Author:  Plumrain
 * Created Time:  2014/6/11 21:14:28
 * File Name: 106.cpp
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

int64 Mod (int64 a, int64 b){
    a %= b; if (a < 0) a += b; return a;
}

void gcd (int64 a, int64 b, int64 &d, int64 &x, int64 &y){
    if (!b) d = a, x = 1, y = 0;
    else gcd (b, a%b, d, y, x), y -= x * (a / b);
}

int64 inv (int64 a, int64 n){
    int64 d, x, y;
    gcd (a, n, d, x, y);
    return d == 1 ? (x+n)%n : -1;
}

int64 ll_abs (int64 a){
    return a > 0 ? a : -a;
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int64 a, b, c, x1, x2, y1, y2;
    while (cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2){
        if (x2 < x1 || y2 < y1){
            cout << "0" << endl; continue;
        }
        if (!a || !b){
            if (!a && !b){
                if (!c) cout << (x2 - x1 + 1) * (y2 - y1 + 1) << endl;
                else cout << "0" << endl;
            }
            else{
                if (!b) swap (a, b), swap (x1, y1), swap (x2, y2);
                if (!c){
                    if (y1 <= 0 && y2 >= 0) cout << x2 - x1 + 1 << endl;
                    else cout << "0" << endl;
                }
                else if (c % b != 0) cout << "0" << endl;
                else{
                    int64 ty = -c / b;
                    if (y1 <= ty && ty <= y2) cout << x2 - x1 + 1 << endl;
                }
            }
            continue;
        }

        if (a < 0) a = -a, b = -b, c = -c;

        int64 gd = __gcd (a, __gcd (ll_abs(b), ll_abs(c)));
        a /= gd; b /= gd; c /= gd;

        //out (a); out (b); out (c);

        if (__gcd (ll_abs (b), ll_abs (a)) != 1){
            cout << "0" << endl; continue;
        }
        int64 bb = inv (b, a);
        bb = bb * (-c) % a; if (bb < 0) bb += a;

        //out (bb);

        int64 sy, ty, my1 = Mod (y1, a), my2 = Mod (y2, a);
        if (my1 <= bb) sy = y1 + (bb - my1);
        else sy = y1 + a - (my1 - bb);
        if (my2 >= bb) ty = y2 - (my2 - bb);
        else ty = y2 - (a - (bb - my2));

        //out (sy); out (ty);

        if (sy > ty){
            cout << "0" << endl; continue;
        }

        int64 sx = - (b*sy + c) / a, tx = - (b*ty + c) / a, dif = ll_abs (b);
        if (sx > tx) swap (sx, tx);
        while (sx < x1) sx += dif;
        while (tx > x2) tx -= dif;
        int64 ans_cnt = 0;
        chmax (ans_cnt, (tx - sx) / dif + 1);
        
        cout << ans_cnt << endl;
    }
    return 0;
}
