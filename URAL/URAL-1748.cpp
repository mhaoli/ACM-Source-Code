/*
 * Author:  Plumrain
 * Created Time:  2014/7/23 13:42:06
 * File Name: G.cpp
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
typedef pair<pii, int> piii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 100005;
const int64 llinf = 9223372036854775807 / 3LL;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 ans_cnt, ans_num, n, tot;
bool check[maxn];
int prm[maxn];

void primes (int n){
    clr (check, 0);
    tot = 0;
    repf (i, 2, n){
        if (!check[i]) prm[tot++] = i;
        for (int j = 0; j < tot; ++ j){
            if (i*prm[j] > n) break;
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
}

void dfs (int64 x, int p, int64 num_pre, int64 maxx){
    if (x > n) return;
    if (num_pre > ans_cnt){
        ans_cnt = num_pre, ans_num = x;
        if (num_pre == ans_cnt) chmin (ans_num, x);
    }
    if (p >= tot) return;
    int64 tmp = x, cnt = 0;
    while (1){
        double t = (llinf + 0.0) / tmp;
        if (t < prm[p]) break;
        tmp *= prm[p];
        ++ cnt;
        if (tmp > n || cnt > maxx) break;
        if (num_pre * (cnt+1) > ans_cnt){
            ans_cnt = num_pre * (cnt+1);
            ans_num = tmp;
        }
        else if (num_pre * (cnt+1) == ans_cnt) chmin (ans_num, tmp);

        dfs (tmp, p+1, num_pre * (cnt+1), cnt);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    primes (1000);
    int T; cin >> T;
    while (T--){
        cin >> n;
        ans_num = 1LL; ans_cnt = 1LL;
        dfs (1LL, 0, 1LL, 10000LL);
        cout << ans_num << " " << ans_cnt << endl;
    }
    return 0;
}
