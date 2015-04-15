/*
 * Author:  Plumrain
 * Created Time:  2014/8/3 15:17:40
 * File Name: I.cpp
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
const int maxn = (int)1e5 + 5;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int L, R;
int64 sum;
double ans[maxn];
piii qn[maxn];
map<int, int> has;
int an[maxn], m, num[maxn], f[maxn], cnt;

bool cmp (piii a, piii b){
    int t1 = a.x.x / m, t2 = b.x.x / m;
    return t1 == t2 ? a.x.y < b.x.y : t1 < t2;
}

int find (int x){
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}

double calc (int l, int r, int flag){
    if (!flag){
        repf (i, l, r){
            int f1 = find (i);
            if (num[f1] == 0) sum += an[f1], ++ cnt;
            ++ num[f1];
        }
    }
    else{
        repf (i, l, L-1){
            int f1 = find (i);
            if (num[f1] == 0) sum += an[f1], ++ cnt;
            ++ num[f1];
        }
        repf (i, L, l-1){
            int f1 = find (i);
            if (num[f1] == 1) sum -= an[f1], -- cnt;
            -- num[f1];
        }
        repf (i, R+1, r){
            int f1 = find(i);
            if (num[f1] == 0) sum += an[f1], ++ cnt;
            ++ num[f1];
        }
        repf (i, r+1, R){
            int f1 = find(i);
            if (num[f1] == 1) sum -= an[f1], -- cnt;
            -- num[f1];
        }
    }
    L = l; R = r;
    return (sum + 0.0) / cnt;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout); 
    repcase{
        int n; scanf ("%d", &n);
        repf (i, 0, n-1) scanf ("%d", an+i);
        m = sqrt (n + 0.0);
        int q; scanf ("%d", &q);
        repf (i, 0, q-1){
            scanf ("%d%d", &qn[i].x.x, &qn[i].x.y); -- qn[i].x.x; -- qn[i].x.y;
            qn[i].y = i;
        }
        sort (qn, qn+q, cmp);

        repf (i, 0, n-1) f[i] = i;

        has.clear();
        repf (i, 0, n-1){
            if (!has.count (an[i])) has[an[i]] = i;
            int f1 = find (i), f2 = find (has[an[i]]);
            if (f1 != f2) f[f1] = f2;
        }

        clr (num, 0); sum = 0; cnt = 0;
        repf (i, 0, q-1) ans[qn[i].y] = calc (qn[i].x.x, qn[i].x.y, i);
        printf ("Case %d:\n", ++ cas);
        repf (i, 0, q-1) printf ("%.6f\n", ans[i]);
    }
    return 0;
}
