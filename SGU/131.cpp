/*
 * Author:  Plumrain
 * Created Time:  2014/6/22 12:29:24
 * File Name: 131.cpp
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

int n, m, cur, nxt;
int64 d[2][1<<10];

void dfs (int p, int s1, int s2, bool u1, bool u2){
    if (p >= m){
        //tst (s1); out (s2);
        if (!u1 && !u2) d[nxt][s2] += d[cur][s1]; return;
    }

    dfs (p+1, s1<<1|(!u1), s2<<1|u2, 0, 0);
    if (!u1){
        dfs (p+1, s1<<1, s2<<1|u2, 1, 0);
        dfs (p+1, s1<<1, s2<<1|u2, 1, 1);
    }
    if (!u2){
        dfs (p+1, s1<<1|(!u1), s2<<1|1, 1, 1);
    }
    if (!u1 && !u2){
        dfs (p+1, s1<<1, s2<<1|1, 0, 0);
        dfs (p+1, s1<<1, s2<<1|1, 0, 1);
        dfs (p+1, s1<<1, s2<<1|1, 1, 0);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (cin >> n >> m){
        if (n < m) swap (n, m);
        d[0][0] = 1;
        cur = 0; nxt = 1;
        repf (i, 1, n){
            clr (d[nxt], 0),
            dfs (0, 0, 0, 0, 0),
            swap (nxt, cur);
            //cout << " ----------- " << endl;
        }
        cout << d[cur][0] << endl;
    }
    return 0;
}
