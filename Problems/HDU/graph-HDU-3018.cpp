/*
 * Author:  Plumrain
 * Created Time:  2014/6/1 13:44:47
 * File Name: graph-HDU-3018.cpp
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
const int maxn = 200005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int num[maxn], f[maxn], ans_num[maxn];

int find (int x){
    if (x != f[x]) f[x] = find (f[x]);
    return f[x];
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        int t1, t2;
        clr (num, 0);
        repf (i, 0, n-1) f[i] = i;
        repf (i, 0, m-1){
            scanf ("%d%d", &t1, &t2); -- t1; -- t2;
            ++ num[t1]; ++ num[t2];

            int f1 = find (t1), f2 = find (t2);
            if (f1 != f2) f[f1] = f2;
        }

        clr (ans_num, -1);
        repf (i, 0, n-1) if (num[i]){
            int tmp = find (i);
            if (ans_num[tmp] == -1) ans_num[tmp] = 0;
            if (num[i] & 1) ++ ans_num[tmp];
        }

        int ans = 0;
        repf (i, 0, n-1) if (ans_num[i] != -1) ans += max (ans_num[i]/2, 1);
        cout << ans << endl;
    }
    return 0;
}
