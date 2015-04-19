/*
 * Author:  Plumrain
 * Created Time:  2014/8/15 17:00:00
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

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int k, n[3], v[3], mi[3];
    while (cin >> k){
        repf (i, 0, 2) cin >> n[i];
        repf (i, 0, 2) cin >> v[i];
        repf (i, 1, 2) v[i] += v[i-1];

        priority_queue<int, vi, greater<int> > q[3];
        repf (i, 0, 2) repf (j, 1, n[i]) q[i].push (0);
        while (k--){
            repf (i, 0, 2) mi[i] = q[i].top(), q[i].pop();
            int m = mi[0];
            repf (i, 1, 2) if (m + v[i-1] < mi[i]) m = mi[i] - v[i-1];
            repf (i, 0, 2) q[i].push (m + v[i]);
        }

        int ans;
        while (sz (q[2])) ans = q[2].top(), q[2].pop();
        printf ("%d\n", ans);
    }
    return 0;
}
