/*
 * Author:  Plumrain
 * Created Time:  2014/6/8 19:34:54
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
 
int num[100005], cnt;
int an[105], bn[105];
 
void init(int n, int cap){
    cnt = 0;
    repf (i, 0, n-1){
        int tmp = 1;
        while (tmp <= bn[i]){
            if (bn[i] - 2*tmp + 1 <= 0){
                if ((an[i]*(bn[i]-tmp+1)) <= cap) num[cnt++] = (an[i] * (bn[i] - tmp + 1)); break;
            }
            if (tmp * an[i] <= cap) num[cnt++] = (tmp * an[i]); tmp *= 2;
        }
    }
}
 
int d[100005];
 
int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, cas = 0; scanf ("%d", &T);
    while ( T-- ){
        int n, cap;
        scanf ("%d%d", &n, &cap);
        repf (i, 0, n-1) scanf ("%d", &an[i]);
        repf (i, 0, n-1) scanf ("%d", &bn[i]);
         
        init(n, cap);
 
        clr (d, 0); d[0] = 1;
        repf (i, 0, cnt-1) repd (j, cap-num[i], 0)
            if (d[j]) d[num[i] + j] = 1;

        int ans = 0;
        repf (i, 1, cap) if (d[i]) ++ ans;
        printf ("Case %d: %d\n", ++ cas, ans);
    }
    return 0;
}
