/*
 * Author:  Plumrain
 * Created Time:  2014-03-06 00:06
 * File Name: C.cpp
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
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)
#define repd(i, a, b) for(int64 i = (a); i >= (int64)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

void gao1 (int &x ,int &y, int &n, int &m){
    int ty = n - x + 1, tx = y;
    x = tx; y = ty;
    swap (n, m);
}

void gao2 (int &x, int &y, int &n, int &m){
    int ty = m - y + 1, tx = x;
    x = tx; y = ty;
}

void gao3 (int &x, int &y, int &n, int &m){
    int ty = x, tx = m - y + 1;
    x = tx; y = ty;
    swap (n, m);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    int t1, t2, t3, p;
    while (cin >> n >> m >> t1 >> t2 >> t3 >> p){
        int nn = n, mm = m;
        int x, y;
        repf (i, 0, p-1){
            m = mm; n = nn;
            scanf ("%d%d", &x, &y);
            repf (i, 0, (t1%4)-1) gao1 (x, y, n, m);
            repf (i, 0, (t2%2)-1) gao2 (x, y, n, m);
            repf (i, 0, (t3%4)-1) gao3 (x, y, n, m);
            printf ("%d %d\n", x, y);
        }
    }
    return 0;
}
