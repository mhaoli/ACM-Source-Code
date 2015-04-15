/*
 * Author:  Plumrain
 * Created Time:  2014-03-17 00:45
 * File Name: B.cpp
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

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

vi prm;
int an[5005], gd[5005], cnt[5005];
set<int> bad;

int calc (int x){
    int ret = 0;
    for (int i = 2; i*i <= x; ++ i) if (x % i == 0){
        int cnt = 0;
        while (x % i == 0) x /= i, cnt ++;
        if (bad.count(i)) ret -= cnt;
        else ret += cnt;
    }
    if (x == 1) return ret;
    if (bad.count(x)) return ret - 1;
    return ret + 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        bad.clear(); prm.clear();
        repf (i, 0, n-1) scanf ("%d", &an[i]);
        int tmp;
        repf (i, 0, m-1) scanf ("%d", &tmp), bad.insert (tmp);

        gd[0] = an[0];
        repf (i, 1, n-1) gd[i] = __gcd (gd[i-1], an[i]);
        clr (cnt, 0);
        cnt[n-1] = calc (gd[n-1]);
        repd (i, n-2, 0) cnt[i] = cnt[i+1] + calc (gd[i]/gd[i+1]);

        int ans = 0;
        repf (i, 0, n-1) ans += calc (an[i]);

        int idx = 0;
        while (idx < n){
            int flag = idx;
            repf (i, idx, n-1) if (cnt[i] < cnt[flag]) flag = i;
            if (cnt[flag] >= 0) break;
            ans -= (flag - idx + 1) * cnt[flag];
            idx = flag + 1;
        }
        printf ("%d\n", ans);
    }
    return 0;
}
