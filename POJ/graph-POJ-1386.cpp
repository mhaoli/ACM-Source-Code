/*
 * Author:  Plumrain
 * Created Time:  2014/6/1 16:09:43
 * File Name: graph-POJ-1386.cpp
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int ru[100], chu[100], f[100];
char s[1005];

int find (int x){
    return x == f[x] ? f[x] : f[x] = find (f[x]);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while ( T-- ){
        int n;
        scanf ("%d", &n);
        clr (ru, 0); clr (chu, 0);
        repf (i, 0, 25) f[i] = i;

        repf (i, 0, n-1){
            scanf ("%s", s);
            int t1 = s[0] - 'a', t2 = s[strlen(s)-1] - 'a';
            ++ ru[t1]; ++ chu[t2];

            int f1 = find (t1), f2 = find (t2);
            if (f1 != f2) f[f1] = f2;
        }

        bool ans_tmp = 0;
        int fa = -1;
        repf (i, 0, 25) if (ru[i] || chu[i]){
            int tmp = find (i);
            if (fa == -1) fa = tmp;
            else if (fa != tmp) ans_tmp = 1;
        }

        if (ans_tmp){
            printf ("The door cannot be opened.\n"); continue;
        }

        vi tmp;
        bool ans_u = 1;
        repf (i, 0, 25) if (ru[i] != chu[i]) tmp.pb (i);
        if (sz(tmp) != 2) ans_u = 0;
        else if (abs (ru[tmp[0]] - chu[tmp[0]]) != 1) ans_u = 0;
        if (!sz(tmp)) ans_u = 1;
        if (ans_u) printf ("Ordering is possible.\n");
        else printf ("The door cannot be opened.\n");
    }
    return 0;
}
