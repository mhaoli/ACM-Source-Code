/*
 * Author:  Plumrain
 * Created Time:  2014/6/15 17:15:07
 * File Name: 108_3.cpp
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool vis[100];
int num[1000005];

int digit (int x){
    int ret = 0;
    while (x) ret += x % 10, x /= 10;
    return ret;
}

int init(int n){
    clr (vis, 0);
    int ret = 0, t = 0, mod = 63;
    repf (i, 1, n){
        t = (t + mod + 1) % mod;
        if (!vis[t]) num[ret++] = i;
        vis[t] = 0;
        int tmp = digit(i);
        vis[(t+tmp)%mod] = 1;
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, k, t;
    cin >> n >> k;
    int cnt = init(n);
    cout << cnt << endl;
    repf (i, 0, k-1){
        scanf ("%d", &t);
        if (i) printf (" ");
        printf ("%d", num[t-1]);
    }
    puts ("");
    return 0;
}
