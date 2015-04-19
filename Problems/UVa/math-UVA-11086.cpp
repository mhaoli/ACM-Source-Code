/*
 * Author:  Plumrain
 * Created Time:  2014-03-27 20:27
 * File Name: math-UVA-11086.cpp
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
const int mod = 1000007;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int64 C[505][505];

void C_init(int n){
    clr (C, 0); C[0][0] = 1;
    repf (i, 1, n){
        C[i][i] = C[i][0] = 1;
        repf (j, 1, i-1) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    C_init(500);
    int T, cas = 0;
    scanf ("%d", &T);
    while (T--){
        int64 n, m, k;
        cin >> n >> m >> k;

        int64 ans = 0;
        repf (i, 1, (1<<4)-1){
            int64 r = n, c = m, cnt = 0;
            if (i & 1) -- r, ++ cnt;
            if (i & 2) -- r, ++ cnt;
            if (i & 4) -- c, ++ cnt;
            if (i & 8) -- c, ++ cnt;
            ans += (cnt&1 ? 1 : -1) * C[r*c][k];
            ans %= mod;
        }
        ans = (C[n*m][k] - ans) % mod;
        if (ans < 0) ans += mod;
        printf ("Case %d: %lld\n", ++ cas, ans);
    }
    return 0;
}
