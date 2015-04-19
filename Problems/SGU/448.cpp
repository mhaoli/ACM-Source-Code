/*
 * Author:  Plumrain
 * Created Time:  2014/7/26 23:54:22
 * File Name: 448.cpp
 * one test case:
 *
 *5 5
 *0 0 1 0 1 
 *1 0 0 1 0 
 *0 1 0 0 1 
 *1 0 1 0 0 
 *0 1 0 1 0 
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi num;
int n, m, up;
vi pat[200];
int d[10][1<<16][20], siz[1<<16];

int dfs (int h, int v, int m){
    //tst (h), tst (v), out (m);
    if (siz[v] == 1) return 1;
    if ((1<<h) < siz[v]) return 0;

    int &ret = d[h][v][m];
    if (ret != -1) return ret; else ret = 0;

    for (int i = v & (v-1); i; i = v & (i-1)) if ((i>>m) & 1){
        int tv = i ^ v;
        repf (j, 0, sz(pat[m])-1) if ((tv>>pat[m][j]) & 1){
            ret += dfs (h-1, i, m) * dfs (h-1, tv, pat[m][j]);
        }
    }
    return ret;
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d%d", &n, &m) != EOF){ 
        -- m;
        repf (i, 0, n-1) pat[i].clear();
        repf (i, 0, n-1) repf (j, 0, n-1){
            int t; scanf ("%d", &t); 
            if (t) pat[i].pb (j);
        }

        repf (i, 0, (1<<n)-1) siz[i] = siz[i>>1] + (i & 1);

        int h = 0;
        while ((1<<h) < n) ++ h;
        clr (d, -1);
        cout << dfs (h, (1<<n)-1, m) << endl;
    }
    return 0;
}
