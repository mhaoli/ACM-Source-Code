/*
 * Author:  Plumrain
 * Created Time:  2014/8/7 15:10:59
 * File Name: 1003.cpp
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
const int maxn = 100005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool vis[maxn];
int an[maxn], nxt[maxn];
int num1[maxn], num2[maxn];

bool ok (int i, int j){
    //out (num1[j] + num2[j]);
    //out (num1[i]);
    //out (num2[j]);
    //out (num1[i] + num2[i]);
    //out (num1[i] * (num1[j] + num2[j]));
    //out (num2[j] * (num1[i] + num2[i]));
    if (1LL * num1[i] * (num1[j] + num2[j]) <= 1LL * num1[j] * (num1[i] + num2[i])) return 1;
    return 0;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        int n; scanf ("%d", &n);
        repf (i, 0, n-1) scanf ("%d", an+i);
        int s = 0, t = n - 1;
        while (s < n && an[s] == 0) ++ s;
        while (t >= 0 && an[t] == 1) -- t;

        an[++t] = 1;
        int cnt = 0, t1 = 0, t2 = 0, last = -1;
        repf (i, s, t){
            if (an[i] == 1){
                if (last == 0) num1[cnt] = t1, num2[cnt++] = t2, t1 = t2 = 0;
                ++ t1;
            }
            else ++ t2;
            last = an[i];
        }
        
        //repf (i, 0, n-1) tst (num1[i]), out (num2[i]);
//
        clr (vis, 0);
        repf (i, 0, cnt-1) nxt[i] = i + 1;
        bool u = 1;
        while (u){
            u = 0;
            int i = 0;
            while (i < cnt && nxt[i] < cnt){
                if (!ok (i, nxt[i])){
                    num1[i] += num1[nxt[i]]; 
                    num2[i] += num2[nxt[i]];
                    vis[nxt[i]] = 1;
                    int ti = i;
                    i = nxt[i];
                    while (i < cnt && vis[i]) i = nxt[i];
                    nxt[ti] = i;
                    u = 1;
                }
                else i = nxt[i];
            }
        }

        int i = 0;
        double ans = 0;
        while (i < cnt){
            ans += num1[i] / (num1[i] + num2[i] + 0.0) * num2[i];
            i = nxt[i];
            while (i < cnt && vis[i]) i = nxt[i];
        }
        printf ("%.6f\n", ans);
    }
    return 0;
}
