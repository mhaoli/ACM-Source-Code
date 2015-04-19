/*
 * Author:  Plumrain
 * Created Time:  2014/8/12 12:59:58
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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
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

template <class T> bool chmin(T& a, T b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, T b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 d[3][1505];

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    int T, cas = 0;
    for (scanf ("%d", &T); T; -- T){
        int n;
        int64 x, y, z, t;
        cin >> n >> x >> y >> z >> t;
        for (int i = 0; i < 2; ++ i) for (int j = 0; j <= n; ++ j) d[i][j] = -1;
        d[0][0] = 0;
        int now = 0, nxt = 1;
        int64 ans = 1LL * x * n * t;
        for (int i = 1; i <= n; ++ i){
            for (int j = 0; j <= i; ++ j) d[nxt][j] = -1;

            for (int j = 0; j < i; ++ j) if (d[now][j] != -1){
                int64 tmp = 1LL * (i - 1 - j) * y * (t + j*z);
                if (d[nxt][j] == -1) d[nxt][j] = 0;
                if (d[nxt][j] < d[now][j] + tmp) d[nxt][j] = d[now][j] + tmp;
                if (d[nxt][j+1] == -1) d[nxt][j+1] = 0;
                if (d[nxt][j+1] < d[now][j] + tmp) d[nxt][j+1] = d[now][j] + tmp;

                tmp = d[nxt][j] + 1LL * (t + j*z) * (n - i) * ((i-j) * y + x);
                if (ans < tmp) ans = tmp;
                tmp = d[nxt][j+1] + 1LL * (t + (j+1)*z) * (n - i) * ((i-j-1) * y + x);
                if (ans < tmp) ans = tmp;
            }
            swap (now, nxt);
        }
        printf ("Case #%d: ", ++ cas);
        cout << ans << endl;
    }
    return 0;
}
