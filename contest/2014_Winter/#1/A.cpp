/*
 * Author:  Plumrain
 * Created Time:  2014-02-10 19:32
 * File Name: A.cpp
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, -1, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int an[4][4005], tot;
vi s1, s2;

int gao (int x)
{
    int l = 0, r = tot-1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (s2[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int gao1 (int x)
{
    int l = 0, r = tot-1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (s2[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, n;
    scanf ("%d", &T);
    while (T--){
        scanf ("%d", &n);
        for (int i = 0; i < n; ++ i)
            scanf ("%d%d%d%d", &an[0][i], &an[1][i], &an[2][i], &an[3][i]);

        s1.clear(); s2.clear();
        for (int i = 0; i < n; ++ i) for (int j = 0; j < n; ++ j) 
            s1.pb (an[0][i] + an[1][j]), s2.pb (an[2][i] + an[3][j]);
        sort (all(s1)); sort (all(s2));

        tot = n * n;
        int64 cnt = 0;
        for (int i = 0; i < tot; ++ i){
            int pos = gao (-1 * s1[i]);
            if (s2[pos] + s1[i] != 0) continue;
            cnt = cnt + gao1 (-1 * s1[i]) - pos + 1;
        }
        printf ("%lld\n", cnt);
        if(T > 0) puts("");
    }
    return 0;
}
