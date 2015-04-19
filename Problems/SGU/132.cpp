/*
 * Author:  Plumrain
 * Created Time:  2014/6/22 23:47:33
 * File Name: 132.cpp
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

int n, m, ln, cur, nxt, an[100], opt[1000], idx[1<<8], cnt;
int64 d[2][1<<8][1<<8];

void dfs_init(int p, int s, bool u){
    if (p == m){
        idx[s] = cnt; opt[cnt++] = s; return;
    }
    dfs_init(p+1, s<<1|1, 1);
    if (u) dfs_init (p+1, s<<1, 0);
}

void dfs (int p, int s1, int s2, int sta1, int sta2, int num){
    if (p >= m){
        if ((s2 & sta2) != 0) return;
        if (ln == 0){
            chmin (d[nxt][s2][sta1^an[ln]], d[cur][s1][(1<<m)-1] + num); 
            //if (d[cur][s1][(1<<m)-1] < inf) tst (s1), tst (s2), tst ((sta1^an[ln])), tst (num), out (d[cur][s1][(1<<m)-1]);
            return;
        }

        int tmp = (1<<m) - 1;
        repf (i, 0, cnt-1){
            if (((tmp^opt[i]) & (tmp^sta1)) != 0) continue;
            chmin (d[nxt][s2][sta1^an[ln]], d[cur][s1][opt[i]^an[ln-1]]+num); 
            //if (d[cur][s1][opt[i]^an[ln-1]] < inf) tst (s1), tst ((opt[i]^an[ln-1])), tst (s2), tst ((sta1^an[ln])), tst (num), out (d[cur][s1][opt[i]^an[ln-1]]);
        }
        return;
    }

    int tmp = 1 << (m - 1 - p);
    dfs (p+1, s1, s2, sta1, sta2, num);
    if ((s1 & tmp) != 0){
        if ((sta2 & tmp) == 0) dfs (p+1, s1^tmp, s2|tmp, sta1, sta2, num+1);
        if (p < m-1 && ((s1 & (tmp>>1)) != 0)) dfs (p+2, (s1^tmp)^(tmp>>1), s2, sta1, sta2, num+1);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (cin >> n >> m){
        cnt = 0; clr (idx, -1);
        dfs_init(0, 0, 1);

        char s[10];
        clr (an, 0);
        repf (i, 0, n-1){
            scanf ("%s", s);
            repf (j, 0, m-1) if (s[j] == '*') an[i] |= 1 << (m - 1 - j);
        }

        cur = 0; nxt = 1;
        clr (d, 127); d[0][0][(1<<m)-1] = 0;
        repf (i, 1, n){
            ln = i-1; clr (d[nxt], 127);
            //out (i);
            repf (j, 0, cnt-1) if ((opt[j] & an[i-1]) == an[i-1]){
                int s1 = opt[j] ^ an[i-1];
                dfs (0, s1, 0, opt[j], an[i], 0);
            }
            swap (cur, nxt);

            //repf (j, 0, (1<<m)-1) if (d[cur][j] > 0) tst (j);
            //cout << endl;
        }

        int64 ans = inf;
        repf (i, 0, cnt-1) if ((opt[i] & an[n-1]) == an[n-1]){
            int64 tmp = d[cur][0][opt[i]^an[n-1]];
            chmin (ans, tmp);
            //if (tmp < inf) ans += tmp;
        }
        cout << ans << endl;
    }
    return 0;
}
