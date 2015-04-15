/*
 * Author:  OpenRainbow
 * Created Time:  2014/8/19 14:23:23
 * File Name: 1009.cpp
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
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
const int DX[] = {8, 7, 6, 5, 4};
const int DY[] = {85, 80, 75, 70, 60};
const int DZ[] = {100, 84, 79, 74, 69};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int gpa[110];
int d[15][1010], g[15][1010];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    rep (i, 0, 4) rep (j, DY[i], DZ[i]) gpa[j] = DX[i];

    repcase{
        int s, n; scanf ("%d%d", &s, &n);
        clr (d, 127); clr (g, 0);
        rep (i, 60, 100) d[1][i] = g[1][i] = gpa[i];
        rep (i, 2, n) rep (j, 60*i, 100*i){
            rep (k, 60, 100) if (j >= k){
                chmin (d[i][j], d[i-1][j-k] + gpa[k]);
                chmax (g[i][j], g[i-1][j-k] + gpa[k]);
            }
        }
        printf ("%.4f %.4f\n", d[n][n*s] / (n * 2.0), g[n][n*s] / (n * 2.0));
    }
    return 0;
}
