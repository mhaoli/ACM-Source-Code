/*
 * Author:  Plumrain
 * Created Time:  2014/7/26 16:03:46
 * File Name: 445.cpp
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
#define sqr(x) ((x) * (x))
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
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;
typedef pair<double, double> pdd;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 1005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

pdd an[maxn];
vi pat[maxn];
double v1, v2, d[maxn];

double dis (pdd a, pdd b){
    return sqrt (sqr (a.x - b.x) + sqr (a.y - b.y));
}

pdd gao (pdd a, pdd b, double y){
    pdd ret; ret.y = y;
    ret.x = a.x + (y - a.y) * (b.x - a.x) / (b.y - a.y);
    return ret;
}

double calc (int s, int e){
    double ret = 0;
    if (an[s].y < an[e].y){
        pdd tmp = gao (an[s], an[s+1], an[e].y);
        ret = dis (tmp, an[s]) / v1 + (an[e].x - tmp.x) / v2;
    }
    else{
        pdd tmp = gao (an[e-1], an[e], an[s].y);
        ret = dis (tmp, an[e]) / v1 + (tmp.x - an[s].x) / v2;
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (cin >> n >> v1 >> v2){
        repf (i, 0, n-1) cin >> an[i].x >> an[i].y;

        repf (i, 0, n-1) pat[i].clear();
        repf (i, 1, n-1) if (an[i].y <= an[i-1].y){
            repd (j, i-1, 0) {
                if (an[j].y < an[i].y || !sgn (an[j].y - an[i].y)){
                    pat[j].pb (i); break;
                }
            }
        }
        repf (i, 0, n-2) if (an[i].y <= an[i+1].y){
            repf (j, i+1, n-1){
                if (an[j].y < an[i].y || !sgn(an[j].y - an[i].y)){
                    pat[i].pb (j); break;
                }
            }
        }

        repf (i, 0, n-1) sort (all (pat[i])), pat[i].erase (unique (all (pat[i])), pat[i].end());

        d[0] = 0;
        repf (i, 1, n-1) d[i] = inf + 0.0;
        repf (i, 0, n-2){
            chmin (d[i+1], d[i] + dis (an[i], an[i+1]) / v1);
            repf (j, 0, sz(pat[i])-1){
                int v = pat[i][j];
                chmin (d[v], d[i] + calc (i, v));
            }
        }
        printf ("%.8f\n", d[n-1]);
    }
    return 0;
}
