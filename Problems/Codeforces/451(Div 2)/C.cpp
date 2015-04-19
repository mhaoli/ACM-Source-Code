/*
 * Author:  Plumrain
 * Created Time:  2014/7/24 23:39:41
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
typedef pair<pii, int> piii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 n, k, d1, d2;
int64 dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};

int64 calc (int64 t1, int64 t2){
    k = k - t1 - t2;
    if (k < 0 || (k % 3)) return n;
    int64 tmp = k / 3;
    int64 tt1 = tmp + t1, tt2 = tmp + t2;
    if (tt1 < 0 || tt2 < 0 || tmp < 0) return n;
    chmax (tmp, tt1); chmax (tmp, tt2);
    return tmp;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T; scanf ("%d", &T);
    while (T--){
        cin >> n >> k >> d1 >> d2;
        int64 kk = k;
        int64 ans = n;
        if (n % 3) puts ("no");
        else{
            repf (i, 0, 3) chmin (ans, calc (d1*dx[i], d2*dy[i])), k = kk;
            if (ans <= n / 3) puts ("yes");
            else puts ("no");
        }
    }
    
    return 0;
}
