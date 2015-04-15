/*
 * Author:  Plumrain
 * Created Time:  2014/9/17 16:06:57
 * File Name: C.cpp
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

const int maxn = int(1e5) + 9;
vi an[maxn];
map<pii, int> has;
map<pii, int>::iterator it;

int solve (vi &a, vi &b){
    vector<int>::iterator p1 = a.begin(), p2 = b.begin();
    int ans = 0;
    for (; p1 != a.end (); ++ p1){
        vector<int>::iterator xt = lower_bound (p2, b.end(), *p1);
        p2 = xt;
        if (p1 != a.begin ()){
            if (p2 != b.begin () && *(p2-1) > *(p1-1)) ++ ans;
        } else if (p2 != b.begin ()) ++ ans;

        if (p2 == b.end ()) break;

        if (p1 + 1 != a.end ()){
            if (p2 != b.end () && *p2 < *(p1+1)) ++ ans;
        } else if (p2 != b.end ()) ++ ans;
    }
    return ans;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    while (scanf ("%d", &n) != EOF){
        rep (i, 0, n-1) an[i].clear ();
        int m;
        rep (i, 0, n-1){
            int t;
            scanf ("%d", &m);
            rep (j, 0, m-1){
                scanf ("%d", &t);
                an[i].pb (t);
            }
            sort (all (an[i]));
        }

        has.clear ();
        int q; scanf ("%d", &q);
        pii t;
        while (q--){
            scanf ("%d%d", &t.x, &t.y);
            -- t.x; -- t.y;
            if (sz (an[t.x]) > sz (an[t.y])) swap (t.x, t.y);
            it = has.find (t);
            if (it != has.end ()) printf ("%d\n", it->second);
            else{
                int ans = solve (an[t.x], an[t.y]);
                has[t] = ans;
                printf ("%d\n", ans);
            }
        }
    }
    return 0;
}
