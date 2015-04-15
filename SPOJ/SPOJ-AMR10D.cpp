/*
 * Author:  Plumrain
 * Created Time:  2014/7/30 16:00:59
 * File Name: D.cpp
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
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int dig[100];
bool d[105][105][11];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T; scanf ("%d", &T);
    while (T--){
        clr (dig, 0);
        repf (i, 1, 9) scanf ("%d", &dig[i]);
        int cnt = 0;
        clr (d, 0); d[0][0][0] = 1;
        repf (i, 1, 9){
            while (dig[i]){
                -- dig[i];
                repf (j, 0, cnt) repf (k, 0, 10)
                    if (d[j][cnt-j][k]){
                        d[j+1][cnt-j][(k+i)%11] = 1;
                        d[j][cnt-j+1][(k+11-i)%11] = 1;
                    }
                ++ cnt;
            }
        }

        int ans = inf;
        repf (i, 0, cnt) if (d[i][cnt-i][0]){
            int tmp = max (2*(cnt-i), 2*i-1);
            chmin (ans, tmp);
        }
        printf ("%d\n", ans == inf ? -1 : ans);
    }
    return 0;
}
