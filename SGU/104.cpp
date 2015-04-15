/*
 * Author:  Plumrain
 * Created Time:  2014/6/11 17:13:42
 * File Name: 104.cpp
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

int an[105][105], p[105][105], stk[105], d[105][105];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    repf (i, 1, n) repf (j, 1, m) cin >> an[i][j];

    repf (i, 0, n) repf (j, 0, m) d[i][j] = -inf; 
    d[0][0] = 0;
    repf (i, 1, n) repf (j, 0, m) if (d[i-1][j] > -inf)
        repf (k, j+1, m) if (d[i][k] < d[i-1][j] + an[i][k]){
            p[i][k] = j; d[i][k] = d[i-1][j] + an[i][k];
        }

    int ans = -inf, idx = -1;
    repf (i, 1, m) if (ans < d[n][i]) idx = i, ans = d[n][i];

    cout << ans << endl;
    int cnt = 0, pos = n;
    while (pos >= 1) stk[cnt++] = idx, idx = p[pos--][idx];
    cout << stk[cnt-1];
    repd (i, cnt-2, 0) cout << " " << stk[i];
    cout << endl;
    return 0;
}
