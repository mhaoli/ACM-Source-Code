/*
 * Author:  Plumrain
 * Created Time:  2014/8/21 13:40:30
 * File Name: 1002.cpp
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
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
//const int inf = 2139062143;
const int D[] = {1, 2, 3, -1, -2, -3};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

void R(int &ret){
    ret = 0;
    bool ok = 0;
    for( ; ;){
        int c = getchar();
        if (c >= '0' && c <= '9') ret = (ret << 3) + (ret << 1) + c - '0', ok = 1;
        else if (ok) return;
    }
}

bool ok (int p, int t){
    if (p >= 4){
        if (t == p) return 0;
        if (t >= p-3 && t <= p+3) return 1;
        return 0;
    }
    rep (i, 0, 5) if (abs (p-D[i]) == t) return 1;
    return 0;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        printf ("Case #%d: ", ++ cas);
        int n, p, t, mul = 2;
        R (n);
        if (n == 0){
            puts ("1"); continue;
        }
        bool ans = 1;
        int cnt = 0;
        R (p);
        rep (i, 0, n-2){
            R (t);
            //scanf ("%d", &t);
            if (!ok (p, t)) ans = 0;
            if (p == 2 && t == 1) ++ cnt;
            if (p == 1 && t == 2) ++ cnt;
            p = t;
        }
        if (t == 0) mul = 1;
        if (!ans) mul = 0;
        printf ("%d\n", mul * (cnt + 1));
    }
    return 0;
}
