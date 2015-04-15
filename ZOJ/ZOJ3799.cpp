/*
 * Author:  Plumrain
 * Created Time:  2014/9/10 23:03:59
 * File Name: B.cpp
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

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int64> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = int(1e6) + 9;
const int64 inf = 1LL<<50;
int64 a[maxn];
int64 stk[maxn], pos[maxn];

inline void Read(int64 &ret){
    ret = 0;
    bool ok = 0, u = 0;
	for( ; ;){
		int c = getchar();
		if (c >= '0' && c <= '9') ret = (ret << 3) + (ret << 1) + c - '0', ok = 1;
        else if (c == '-') u = 1;
		else if (ok){
            if (u) ret *= -1;
            return ;
        }
	}
}

void calc (vi &v, vi &num){
    int n = sz (v), top = 0, move = 0, pos_top = 0;
    int64 len = 0;
    pos[pos_top++] = 0;
    rep (i, 0, n-1){
        if (v[i] > 0){
            ++ move;
            if (pos[pos_top-1] < len){
                if (!top && len >= v[i]) chmax (num[move], len + v[i]);
                else if (len - pos[pos_top-1] < v[i]){
                    stk[top++] = 2*v[i] - (len - pos[pos_top-1]) + len;
                    pos[pos_top++] = len + v[i];
                } else{
                    while (top >= 1 && len+v[i] >= stk[top-1]){
                        -- top; -- pos_top;
                    }
                    if (!top) num[move] = len + v[i];
                }
            } else{
                stk[top++] = len + 2 * v[i];
                pos[pos_top++] = len + v[i];
            }
            len = len + v[i];
        } else{
            len = len - v[i];
            while (top >= 1 && len >= stk[top-1]){
                -- top;
                -- pos_top;
            }
            if (top == 0){
                num[move] = len;
            }
        }
    }
    rep (i, 1, n-1) chmax (num[i], num[i-1]);
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    repcase{
        int n, m; scanf ("%d%d", &n, &m);
        rep (i, 1, n){
            Read (a[i]);
        }

        a[0] = a[n+1] = -inf;

        vi vL(m), vR(n + 1 - m);
        red (i, m-1, 0) vL[m-i-1] = a[i];
        rep (i, m+1, n+1) vR[i-m-1] = a[i];

        vi pL(m, 0), pR(n + 1 - m, 0);
        calc (vL, pL); calc (vR, pR);

        int ans = n - 1;
        for (int p1 = 0, p2 = sz (pR)-1; p1 < sz (pL); ++ p1){
            while (p2 >= 1 && pR[p2-1] + pL[p1] >= a[m]) -- p2;
            chmin (ans, p1 + p2);
        }
        printf ("%d\n", ans + 1);
    }
    return 0;
}
