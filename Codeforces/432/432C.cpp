/*
 * Author:  Plumrain
 * Created Time:  2014/7/20 16:18:48
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int an[maxn];
int prm[maxn], pre[maxn];
bool check[maxn];
pii ans[maxn*6];
int ans_cnt;

int primes (int n){
    clr (check, 0);
    int tot = 0;
    repf (i, 2, n){
        if (!check[i]) prm[tot++] = i;
        for (int j = 0; j < tot; ++ j){
            if (i * prm[j] > n) break;
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
    return tot;
}

void dfs (int t1, int t2){
    if (t1 == t2) return;
    if (t1 > t2) swap (t1, t2);
    int len = t2 - t1 + 1;

    ans[ans_cnt].x = t1;
    ans[ans_cnt++].y = t1+pre[len]-1;
    swap (an[t1], an[t1+pre[len]-1]);

    dfs (t1 + pre[len] - 1, t2);

    if (t1 + pre[len] - 1 != t2){
        ans[ans_cnt].x = t1;
        ans[ans_cnt++].y = t1 + pre[len] - 1;
        swap (an[t1], an[t1+pre[len]-1]);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    repf (i, 0, n-1) scanf ("%d", &an[i]), --an[i];

    int tot = primes (n), pre_prm;
    repf (i, 2, n){
        if (!check[i]) pre_prm = i;
        pre[i] = pre_prm;
    }

    ans_cnt = 0;
    repf (i, 0, n-1) while (an[i] != i){
        dfs (an[i], i); 
    }
    printf ("%d\n", ans_cnt);
    repf (i, 0, ans_cnt-1) printf ("%d %d\n", ans[i].x+1, ans[i].y+1);
    return 0;
}
