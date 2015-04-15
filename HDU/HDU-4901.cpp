/*
 * Author:  Plumrain
 * Created Time:  2014/7/31 12:51:01
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
#define repcase int T, cas = 1; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
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
const int mod = 1e9+7;
const int maxn = 2005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int an[maxn];
int f[2000][1<<11], tmp[2000][1<<11], d[2000][1<<11];

void add (int &a, int b){
    a += b;
    if (a >= mod) a -= mod;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T; scanf ("%d", &T);
    while (T--){
        int n; scanf ("%d", &n);
        repf (i, 0, n-1) scanf ("%d", &an[i]);

        clr (tmp, 0);
        tmp[0][an[0]] = 1;
        repf (i, 1, n-1){
            add (tmp[i][an[i]], 1);
            repf (j, 0, (1<<10)-1) if (tmp[i-1][j]){
                add (tmp[i][j^an[i]], tmp[i-1][j]);
                add (tmp[i][j], tmp[i-1][j]);
            }
        }

        clr (f, 0); clr (d, 0);
        d[n-1][an[n-1]] = f[n-1][an[n-1]] = 1;
        repd (i, n-2, 0){
            add (f[i][an[i]], 1); 
            add (d[i][an[i]], 1);
            repf (j, 0, (1<<10)-1) if (d[i+1][j]){
                add (f[i][an[i]&j], d[i+1][j]);
                add (d[i][an[i]&j], d[i+1][j]);
                add (d[i][j], d[i+1][j]);
                //add (f[i][j], f[i+1][j]);
            }
        }

        int ans = 0;
        repd (i, n-1, 1) repf (j, 0, (1<<10)-1) if (f[i][j]){
            int cnt = (1LL * f[i][j] * tmp[i-1][j]) % mod;
            add (ans, cnt);
        }

        cout << (ans + mod) % mod << endl;
    }
    return 0;
}
