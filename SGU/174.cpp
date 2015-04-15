/*
 * Author:  Plumrain
 * Created Time:  2014/7/16 10:33:42
 * File Name: 174.cpp
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
const int maxn = 200005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

map<pii, int> has;
pii an[maxn];
int f[maxn*2], e[maxn*2], v[maxn*2];

int find (int x){
    return (f[x] == x) ? f[x] : f[x] = find(f[x]);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    pii t1, t2;
    int idx = 0; has.clear();
    repf (i, 0, n-1){
        scanf ("%d%d%d%d", &t1.x, &t1.y, &t2.x, &t2.y);
        if (!has.count (t1)) has[t1] = idx ++;
        if (!has.count (t2)) has[t2] = idx ++;
        an[i].x = has[t1]; an[i].y = has[t2];
    }

    clr (e, 0);
    repf (i, 0, idx-1) f[i] = i, v[i] = 1;
    repf (i, 0, n-1){
        int f1 = find (an[i].x), f2 = find (an[i].y);
        if (f1 == f2) ++ e[f1];
        else{
            f[f2] = f1;
            e[f1] += e[f2] + 1; v[f1] += v[f2];
            e[f2] = 0; v[f2] = 0;
        }

        if (e[f1] >= v[f1]){
            cout << i + 1 << endl; return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
