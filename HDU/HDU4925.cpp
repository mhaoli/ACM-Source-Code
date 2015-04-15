/*
 * Author:  Plumrain
 * Created Time:  2014/8/7 12:09:39
 * File Name: 1005.cpp
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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int n, m;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
int an[105][105];

bool ok (int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    return 1;
}

int calc (int x, int y){
    if (!an[x][y]) return 0;
    int ret = 1;
    repf (i, 0, 3){
        int t1 = x + dx[i], t2 = y + dy[i];
        if (ok (t1, t2) && !an[t1][t2]) ret <<= 1;
    }
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        cin >> n >> m;
        int c = 1, t1 = 0, t2 = 0, tc = 1;
        while (t1 < n){
            an[t1][t2] = c; c ^= 1;
            ++ t2;
            if (t2 >= m){
                t2 = 0; ++ t1;
                tc ^= 1; c = tc;
            }
        }
        
        int ans = 0;
        repf (i, 0, n-1) repf (j, 0, m-1) ans += calc (i, j);
        cout << ans << endl;
    }
    return 0;
}
