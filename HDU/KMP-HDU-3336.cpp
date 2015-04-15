/*
 * Author:  Plumrain
 * Created Time:  2014-03-10 13:49
 * File Name: KMP-HDU-3336.cpp
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
#define repf(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)
#define repd(i, a, b) for(int64 i = (a); i >= (int64)(b); i --)
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
const int maxn = 200005;
const int mod = 10007;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

char s[maxn];
int f[maxn], cnt[maxn];

void fail(char *s, int *f, int n){
    f[0] = f[1] = 0;
    repf (i, 1, n-1){
        int j = f[i];
        while (j && s[j] != s[i]) j = f[j];
        f[i+1] = s[i] == s[j] ? j+1 : 0;
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, n;
    scanf ("%d", &T);
    while (T--){
        scanf ("%d%s", &n, s);
        fail (s, f, n);
        cnt[0] = 1;
        repf (i, 1, n-1){
            int j = f[i];
            cnt[i] = 1;
            while (j && s[i] != s[f[i]]) j = f[j];
            if (s[j] == s[i]) cnt[i] = (cnt[i] + cnt[j]) % mod;
        }
        int ans = 0;
        repf (i, 0, n-1) ans = (ans + cnt[i]) % mod;
        printf ("%d\n", ans);
    }
    return 0;
}
