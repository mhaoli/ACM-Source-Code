/*
 * Author:  Plumrain
 * Created Time:  2014/7/31 9:44:36
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
const int maxn = 1000005;
const int mod = 1000000007;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int an[2*maxn];
int f[1<<22];
int two[1<<22], siz[1<<22];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    two[0] = 1; siz[0] = 0;
    repf (i, 1, (1<<20)-1) two[i] = (two[i-1] + two[i-1]) % mod;
    repf (i, 1, (1<<20)-1) siz[i] = siz[i>>1] ^ (i & 1);

    int n;
    while (cin >> n){
        clr (f, 0);
        repf (i, 0, n-1) scanf ("%d", &an[i]), ++f[an[i]];
        repf (i, 0, 20) repf (j, 0, (1<<20)-1) 
            if ((j >> i) & 1) f[j^(1<<i)] = (f[j^(1<<i)] + f[j]) % mod;

        int ans = 0;
        repf (i, 0, (1<<20)-1){
            if (siz[i]) ans += mod - two[f[i]] + 1;
            else ans += two[f[i]] - 1;
            if (ans >= mod) ans -= mod;
        }
        printf ("%d\n", ans);
    }
    return 0;
}
