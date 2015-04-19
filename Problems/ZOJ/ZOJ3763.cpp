/*
 * Author:  Plumrain
 * Created Time:  2014/9/16 11:33:36
 * File Name: ZOJ3763.cpp
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

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
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
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

#define sqr(x) ((x) * (x))
#define y0 yy0
#define x0 xx0
typedef pair<double, double> pdd;

int x, y, c, tim;
int x0, y0, vx, vy;
double A, B, C;

bool calc (pdd t1){
    if (sgn(A) == 0){
        if ((t1.x * B + C) * (t1.y * B + C) <= 0) return 1;
        return 0;
    }

    double delta = sqr(B) - 4*A*C;
    if (delta < 0) return 0;
    else delta = sqrt (delta);
    pdd t2 = pdd ((-B - delta) / (2*A), (-B + delta) / (2*A));
    if (t2.x >= t1.x && t2.x <= t1.y) return 1;
    if (t2.y >= t1.x && t2.y <= t1.y) return 1;
    return 0;
}

bool ok (){
    A = 0.0 + sqr(vx) + sqr(vy) - sqr(c);
    B = 2.0 * ((x0 - x + 0.0) * vx + (y0 - y + 0.0) * vy);
    C = sqr (x0 - x + 0.0) + sqr (y0 - y + 0.0);
    if (calc (pdd (0.0, double(tim)))) return 1;

    B += 4.0 * sqr(c) * tim;
    C -= 4.0 * sqr(c) * sqr(tim);
    if (calc (pdd (double(tim), 2.0*tim))) return 1;
    return 0;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    while (scanf ("%d%d%d%d", &x, &y, &c, &tim) != EOF){
        int q, ans = 0;
        scanf ("%d", &q);
        while (q--){
            scanf ("%d%d%d%d", &x0, &y0, &vx, &vy);
            if (ok ()) ++ ans;
        }
        printf ("%d\n", ans);
    }
    return 0;
}
