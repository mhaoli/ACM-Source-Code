/*
 * Author:  Plumrain
 * Created Time:  2014/7/30 23:10:12
 * File Name: C.cpp
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
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi tmp;
vii ans;
int prm[maxn];
bool check[maxn], vis[maxn];

int primes(int n){
    clr (check, 0);
    int tot = 0;
    repf (i, 2, n){
        if (!check[i]) prm[tot++] = i;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
    return tot;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int tot = primes (100000), n;
    while (scanf ("%d", &n) != EOF){
        clr (vis, 0);
        ans.clear(); tmp.clear();
        repf (i, 1, tot-1){
            if (n / prm[i] < 2) break;

            int cnt = 0;
            repf (j, 1, n){
                if (j * prm[i] > n) break;
                if (!vis[j*prm[i]]) ++ cnt;
            }
            if (cnt & 1) tmp.pb (2 * prm[i]), vis[2*prm[i]] = 1;
            int tnum = 0;
            repf (j, 1, n){
                if (j * prm[i] > n) break;
                if (!vis[j*prm[i]]){
                    if (!tnum) tnum = j * prm[i];
                    else{
                        ans.pb (mp (tnum, j * prm[i]));
                        vis[tnum] = vis[j*prm[i]] = 1;
                        tnum = 0;
                    }
                }
            }
        }

        for (int i = 2; i <= n; i *= 2) tmp.pb (i);
        for (int i = 1; i < sz(tmp); i += 2) ans.pb (mp (tmp[i-1], tmp[i]));

        printf ("%d\n", sz (ans));
        repf (i, 0, sz(ans)-1) printf ("%d %d\n", ans[i].x, ans[i].y);
    }
    return 0;
}
