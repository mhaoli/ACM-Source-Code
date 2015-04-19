/*
 * Author:  Plumrain
 * Created Time:  2014/8/26 14:58:07
 * File Name: H.cpp
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
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
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int tim;

struct line{
    int l, r, k;
};

vi vec[333];
line an[333];

void calc (const int &t, int &k){
    k = (t - tim - 1 + 300) / 300;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    priority_queue<int, vi, greater<int> > q;
    while (scanf ("%d", &n) && n){
        rep (i, 0, n-1){
            scanf ("%d%d", &an[i].l, &an[i].r);
            an[i].l = an[i].l * 60 + 1;
            an[i].r = an[i].r * 60 - 1;
        }

        int ans = 0;
        rep (i, 0, 299){
            tim = i;
            rep (j, 0, 205) vec[j].clear();
            rep (j, 0, n-1){
                calc (an[j].l, an[j].k);
                vec[an[j].k].pb (an[j].r);
            }

            while (sz (q)) q.pop ();
            int res = 0, ti = i;
            rep (j, 0, 205){
                rep (k, 0, sz (vec[j])-1) q.push (vec[j][k]);
                if (sz (q)){
                    int top = q.top(); q.pop ();
                    while (sz (q) && top < ti) top = q.top (), q.pop ();
                    if (top >= ti) ++ res;
                }
                ti += 300;
            }
            chmax (ans, res);
        }
        printf ("%d\n", ans);
    }
    return 0;
}

