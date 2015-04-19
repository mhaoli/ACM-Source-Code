/*
 * Author:  Plumrain
 * Created Time:  2014/6/30 23:57:54
 * File Name: 148.cpp
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
const int maxn = 15005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int wn[maxn], ln[maxn], pn[maxn], num[maxn], idx[maxn], des[maxn];

int bin_search(int key, int l, int r){
    int ret = -1;
    while (l <= r){
        int m = (l + r) >> 1;
        if (num[m] > key) ret = m, l = m + 1;
        else r = m - 1;
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    repf (i, 0, n-1) scanf ("%d%d%d", wn+i, ln+i, pn+i);
    num[n] = 0;
    repd (i, n-1, 0) num[i] = num[i+1] + wn[i];
    repf (i, 0, n-1) idx[i] = bin_search (ln[i] + num[i+1], 0, n);

    int ans = inf, cnt = 0, ans_pos = 0;
    clr (des, 0);
    repd (i, n-1, 0){
        cnt += (wn[i] <= ln[i] ? pn[i] : 0);
        cnt -= des[i];
        if (ans > cnt) ans = cnt, ans_pos = i;
        if (idx[i] != -1) des[idx[i]] += pn[i];
    }

    repf (i, ans_pos, n-1) if (idx[i] < ans_pos) printf ("%d\n", i + 1);
    return 0;
}
