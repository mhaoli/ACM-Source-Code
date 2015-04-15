/*
 * Author:  Plumrain
 * Created Time:  2014-03-10 23:47
 * File Name: C.cpp
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
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)
#define repd(i, a, b) for(int64 i = (a); i >= (int64)(b); i --)
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

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

bool gao(int n, int m){
    if (2 * (n+1) < m) return 0;
    if (m < n - 1) return 0;
    
    int t1 = 0, t2 = 0;
    if (n >= m){
        if (n-1 == m) printf ("0");
        while (t2 < m) printf ("10"), ++ t2;
        return 1;
    }

    int tmp = m - n - 1;
    if (tmp) printf ("11"), t2 += 2;
    else printf ("1"), t2 ++;
    repf (i, 0, tmp-2) printf ("011"), t1 ++, t2 += 2;
    while (t1 < n && t2 < m){
        printf ("01"); ++ t1; ++ t2;
    }
    return 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        bool u = gao(n, m);
        if (!u) printf ("-1");
        printf ("\n");
    }
    return 0;
}
