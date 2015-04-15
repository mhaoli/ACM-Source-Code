/*
 * Author:  Plumrain
 * Created Time:  2014/7/20 19:15:16
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
const int maxn = 30005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int num[maxn];
int ans[maxn];
vi pat[maxn];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        int n, m; scanf ("%d%d", &n, &m);
        clr (num, 0);
        repf (i, 0, n-1) pat[i].clear();

        int t1, t2;
        while (m--){
            scanf ("%d%d", &t1, &t2); -- t1; -- t2;
            pat[t2].pb (t1); ++ num[t1];
        }

        priority_queue<int> q;
        repf (i, 0, n-1) if (!num[i]) q.push (i);
        
        int ans_cnt = 0;
        while (sz (q)){
            int u = q.top(); q.pop();
            ans[ans_cnt++] = u;
            repf (i, 0, sz(pat[u])-1){
                -- num[pat[u][i]];
                if (!num[pat[u][i]]) q.push (pat[u][i]);
            }
        }
        
        repd (i, ans_cnt-1, 0){
            printf ("%d", ans[i]+1);
            if (i) printf (" ");
        }
        puts ("");
    }
    return 0;
}

