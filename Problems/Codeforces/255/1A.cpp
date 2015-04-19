/*
 * Author:  Plumrain
 * Created Time:  2014/7/31 19:30:59
 * File Name: A.cpp
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
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int an[maxn];
int d[maxn], f[maxn];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF){
        repf (i, 0, n-1) scanf ("%d", &an[i]);
        clr (d, 0); clr (f, 0);
        d[0] = f[n-1] = 1;
        repf (i, 1, n-1) d[i] = an[i] > an[i-1] ? d[i-1] + 1 : 1;
        repd (i, n-2, 0) f[i] = an[i] < an[i+1] ? f[i+1] + 1 : 1;

        if (n == 1){
            cout << 1 << endl; continue;
        }
        int ans = 1; chmax (ans, f[1]+1); chmax (ans, d[n-2]+1);
        repf (i, 1, n-2){
            if (an[i-1] + 1 < an[i+1]) chmax (ans, f[i+1] + 1 + d[i-1]);
            else chmax (ans, f[i+1] + 1), chmax (ans, d[i-1] + 1);
        }
        cout << ans << endl;
    }
    return 0;
}
