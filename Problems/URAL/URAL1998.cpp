/*
 * Author:  Plumrain
 * Created Time:  2014/8/13 13:14:24
 * File Name: I.cpp
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
const int maxn = 100005;
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int sum[maxn];

int bin_search (int l, int r, int k){
    if (r < l) return 0;
    if (sum[r] <= k) return 0;
    int up = r, ret = -1;
    while (l <= r){
        int m = (l + r) >> 1;
        if (sum[up] - sum[m] > k) ret = m, l = m + 1;
        else r = m - 1;
    }
    return ret + 1;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m, k; scanf ("%d%d%d", &n, &m, &k);
    clr (sum, 0);
    repf (i, 0, n-1){
        int t; scanf ("%d", &t);
        sum[i] = (i ? sum[i-1] + t : t);
    }

    int tim = 0, pos = 0;
    repf (i, 0, m-1){
        int t; scanf ("%d", &t);
        if (t - tim > n - pos){
            tim = tim + n - pos;
            pos = n;
            break;
        }
        else{
            pos = pos + (t - tim - 1);
            pos = bin_search (0, pos-1, k);
        }
        tim = t;
    }
    if (pos != n) tim += n - pos;
    printf ("%d\n", tim);
    return 0;
}
