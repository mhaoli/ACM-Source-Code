/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/1 21:55:42
 * File Name: 1422.cpp
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
#include <functional>
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
#include <complex>

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
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>2;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

vi a[2];
int dp[500][500][2];

int DP(int tot) {
        int n = sz(a[0]), m = sz(a[1]);
        clr(dp, 127);
        dp[0][0][0] = dp[0][0][1] = 0;
        for(int i = 0, j, k, t; i < n; ++i) {
                for(j = 0; j < m; ++j) {
                        for(k = 0; k < 2; ++k) if(dp[i][j][k] < inf){
                                for(t = 0; t < 2; ++t) if(i + (!t) < n && j + t < m){
                                        chmin(dp[i+(!t)][j+t][t], dp[i][j][k] + (tot - i - j) * (a[t][(t?j:i)+1] + (k==t?-1:1) * a[k][k?j:i]));
                                }
                        }
                }
        }
        int ans = dp[n-1][m-1][0]; chmin(ans, dp[n-1][m-1][1]);
        return ans;
}

int main()
{
        int _; scanf("%d", &_);
        for(int n; _--;) {
                scanf("%d", &n);
                for(int i = 0; i < 2; ++i) a[i].clear(), a[i].pb(0);
                for(int i = 0, t; i < n; ++i) {
                        scanf("%d", &t);
                        a[t<0].pb(abs(t));
                }
                sort(all(a[0]));
                sort(all(a[1]));
                printf("%d\n", DP(n));
        }
        return 0;
}
