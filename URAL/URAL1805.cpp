/*
 * Author:  Plumrain
 * Created Time:  2014/8/9 17:17:21
 * File Name: F.cpp
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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 all;
int ans[20][20], vis[2222], cnt[2222];
int id[20][20], tot;

void init (int s, int l){
    int t = tot;
    repf (i, s, s+l-2) id[s][i] = tot++;
    tot = t;
    repf (i, s, s+l-2) id[i][s+l-1] = tot++;
    tot = t;
    repd (i, s+l-1, s+1) id[s+l-1][i] = tot++;
    tot = t;
    repd (i, s+l-1, s+1) id[i][s] = tot++;

    if (l > 2) init (s+1, l-2);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    int64 k;
    while (scanf ("%d%I64d", &n, &k) != EOF){
        tot = 0;
        init (0, n);
        //repf (i, 0, n-1){
            //repf (j, 0, n-1) tst (id[i][j]);
            //cout << endl;
        //}

        clr (vis, 0);
        repf (i, 0, tot-1) cnt[i] = 4;
        all = 1;
        repf (i, 0, tot-1) all *= cnt[i];
        repf (i, 0, n-1) repf (j, 0, n-1){
            int v = id[i][j];
            if (vis[v]){
                -- cnt[v]; ans[i][j] = 0; continue;
            }
            int64 tmp = all / cnt[v];
            tmp *= (cnt[v] - 1);
            if (k > tmp){
                -- cnt[v]; vis[v] = 1; ans[i][j] = 1; k -= tmp; all -= tmp;
            }
            else ans[i][j] = 0, all = tmp, -- cnt[v];
        }
        repf (i, 0, n-1){
            repf (j, 0, n-1) printf ("%d", ans[i][j]);
            puts ("");
        }
    }
    return 0;
}
