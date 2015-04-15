/*
 * Author:  Plumrain
 * Created Time:  2014/7/19 22:40:14
 * File Name: 299.cpp
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

char ss[1005][505];
string s[1005];

void clear(int p){
    bool u = 0;
    repf (i, 0, sz(s[p])-1){
        if (!u && s[p][i] != '0') u = 1; 
        if (u) printf ("%c", s[p][i]);
    }
    if (!u) printf ("0");
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n; scanf ("%d", &n);
    repf (i, 0, n-1) scanf ("%s", ss[i]);
    int ma = 0;
    repf (i, 0, n-1) chmax (ma, (int)strlen(ss[i]));
    repf (i, 0, n-1){
        s[i].clear();
        int tlen = strlen (ss[i]);
        repf (j, 0, ma-tlen-1) s[i].pb ('0');
        repf (j, 0, tlen-1) s[i].pb (ss[i][j]);
    }
    sort (s, s+n);

    string tmp(ma, 0);
    repf (i, 2, n-1){
        int u = 0;
        repd (j, ma-1, 0){
            tmp[j] = s[i][j] - s[i-1][j] + '0' - u;
            u = 0;
            if (tmp[j] < '0') tmp[j] += 10, u = 1;
        }
        if (tmp < s[i-2]){
            clear (i-2); printf (" ");
            clear(i-1); printf (" ");
            clear (i); puts ("");
            return 0;
        }
    }
    puts ("0 0 0");
    return 0;
}
