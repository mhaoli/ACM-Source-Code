/*
 * Author:  Plumrain
 * Created Time:  2014/9/18 13:37:59
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
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
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
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

int temp[10], n, p, len[111];
char str[55][55], stk[1111];

void add (char *s){
    while (s[0]){
        stk[p++] = s[0];
        ++ s;
    }
}

int calc (){
    //rep (i, 0, n-1) tst (temp[i]); cout << endl;
    int top = 0;
    rep (i, 0, n-1){
        p = top;
        int L = len[temp[i]];
        rep (j, max (top-L, 0), top-1){
            bool u = 1;
            for (int k = 0, t = j; t < top; ++ t, ++ k){
                if (!str[temp[i]][k]) break;
                if (str[temp[i]][k] != stk[t]){
                    u = 0; break;
                }
            }
            if (u){
                p = j; break;
            }
        }
        add (str[temp[i]]);
        chmax (top, p);
    }
    return top;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        scanf ("%d", &n);
        rep (i, 0, n-1){
            scanf ("%s", str[i]);
            len[i] = strlen (str[i]);
        }

        int ans = inf;
        rep (i, 0, n-1) temp[i] = i;
        do{
            chmin (ans, calc ());
        }while (next_permutation (temp, temp + n));
        printf ("Case %d: %d\n", ++ cas, ans);
    }
    return 0;
}
