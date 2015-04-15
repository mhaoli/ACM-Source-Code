/*
 * Author:  Plumrain
 * Created Time:  2014/9/3 0:20:57
 * File Name: D.cpp
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
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0U >> 1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = int(6e5) + 9;
char str[maxn], ss[10];
int has[maxn];
int tot, len[maxn];
vi start[maxn], ans[maxn];

int encode (char *s, const int &l){
    int ret = 0;
    red (i, l-1, 0) ret = ret * 27 + s[i] - 'a' + 1;
    return ret;
}

inline int ask_len (const int &s1, const int &l1, const int &s2, const int &l2){
    return max (s1 + l1, s2 + l2) - min (s1, s2);
}

int solve (int t1, int t2){
    if (sz (start[t1]) > sz (start[t2])) swap (t1, t2);
    int res = inf;
    vi &x1 = start[t1], &x2 = start[t2];

    for (auto i : x1){
        int p = lower_bound (all (x2), i) - x2.begin ();
        if (p != sz (x2)) chmin (res, ask_len (i, len[t1], x2[p], len[t2]));
        if (p) chmin (res, ask_len (i, len[t1], x2[p-1], len[t2]));
    }
    return res;
}

void init (int siz){
    rep (i, 0, tot-1) if (sz (start[i]) >= siz){
        rep (j, 0, tot-1) ans[i].pb (solve (i, j));
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    scanf ("%s", str);
    int L = strlen (str);
    int siz = sqrt (L * 4.0);
    tot = 0;
    clr (has, -1);
    rep (i, 1, 4){
        int temp = 1, tmp;
        rep (j, 0, i-2) temp *= 27;

        rep (j, 0, L - i){
            if (j){
                tmp /= 27; 
                tmp += temp * (str[j+i-1] - 'a' + 1);
            } else{
                tmp = encode (str, i);
            }

            if (has[tmp] == -1){
                len[tot] = i;
                start[tot].pb (j);
                has[tmp] = tot ++;
            } else{
                start[has[tmp]].pb (j);
            }
        }
    }

    init (siz);

    int q, t1, t2; scanf ("%d", &q);
    while (q--){
        scanf ("%s%s", str, ss);
        t1 = has[encode (str, strlen (str))];
        t2 = has[encode (ss, strlen (ss))];
        if (t1 == -1 || t2 == -1){
            puts ("-1"); continue;
        }

        if (sz (start[t1]) >= siz) printf ("%d\n", ans[t1][t2]); 
        else if (sz (start[t2]) >= siz) printf ("%d\n", ans[t2][t1]);
        else printf ("%d\n", solve (t1, t2));
    }
    return 0;
}
