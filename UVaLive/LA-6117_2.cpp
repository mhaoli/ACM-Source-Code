/*
 * Author:  Plumrain
 * Created Time:  2014/7/27 13:48:33
 * File Name: H.cpp
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

int siz[1<<20], now, nxt;
int64 d[2][1<<20][25];

void init(){
    repf (i, 0, (1<<20)-1) siz[i] = siz[i>>1] + (i & 1);

    int n = 20;
    clr (d, 0); 
    d[0][0][0] = 1;
    d[0][1][1] = 1;
    now = 0, nxt = 1;
    repd (i, 19, 1){
        clr (d[nxt], 0);
        int tn = 20 - i, up = (1<<tn) - 1;
        repf (j, 0, up) repf (t, 0, tn) if (d[now][j][t]){
            d[nxt][j<<1][t] += d[now][j][t];
            d[nxt][j<<1|1][t] += d[now][j][t] * siz[j];
            d[nxt][j<<1|1][t+1] += d[now][j][t];
        }
        swap (now, nxt);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    init();
    int T; scanf ("%d", &T);
    while (T--){
        int n, l, r; scanf ("%d%d%d", &n, &l, &r);
        int64 ans = 0;
        int maxx = (1 << (n-1)), up = maxx - 1;
        repf (i, 0, up){
            int tv = (up ^ i);
            ans += d[now][i][l-1] * d[now][tv][r-1];
        }
        cout << ans << endl;
    }
    return 0;
}
