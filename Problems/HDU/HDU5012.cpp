/*
 * Author:  Plumrain
 * Created Time:  2014/9/14 13:13:44
 * File Name: 1006.cpp
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

int xt[6];

struct State{
    int a[6];
    int OUT (){
        int ret = 0;
        rep (i, 0, 5) ret = ret * 6 + a[i];
        return ret;
    }
    void IN (int x){
        red (i, 5, 0){
            a[i] = x % 6;
            x /= 6;
        }
    }
    void rot(int i){
        if (!i){ 
            xt[0] = a[3]; xt[1] = a[2];
            xt[2] = a[0]; xt[3] = a[1];
            xt[4] = a[4]; xt[5] = a[5];
        } else if (i == 1){
            xt[0] = a[2]; xt[1] = a[3];
            xt[2] = a[1]; xt[3] = a[0];
            xt[4] = a[4]; xt[5] = a[5];
        } else if (i == 2){
            xt[0] = a[5]; xt[1] = a[4];
            xt[2] = a[2]; xt[3] = a[3];
            xt[4] = a[0]; xt[5] = a[1];
        } else if (i == 3){
            xt[0] = a[4]; xt[1] = a[5];
            xt[2] = a[2]; xt[3] = a[3];
            xt[4] = a[1]; xt[5] = a[0];
        }
        rep (i, 0, 5) a[i] = xt[i];
    }
}A, B;

bool inq[99999];
int d[99999], target;

int bfs (){
    clr (d, 127);
    clr (inq, 0);
    int dig = A.OUT ();
    queue<int> q;
    q.push (dig); d[dig] = 0; inq[dig] = 1;

    State tmp, tt;
    while (sz (q)){
        int x = q.front (); q.pop();
        if (x == target) return d[x];

        //if (!inq[x]) continue;
        tmp.IN (x); inq[x] = 0;
        rep (i, 0, 3){
            tt = tmp; tt.rot (i);
            int y = tt.OUT ();
            if (d[y] > d[x] + 1){
                d[y] = d[x] + 1;
                if (!inq[y]) q.push (y), inq[y] = 1;
            }
        }
    }
    return -1;
}

int a[100];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    while (scanf ("%d", &a[0]) != EOF){
        rep (i, 1, 5) scanf ("%d", &a[i]);
        rep (i, 0, 5) A.a[i] = a[i] - 1;
        rep (i, 0, 5) scanf ("%d", &a[i]);
        rep (i, 0, 5) B.a[i] = a[i] - 1;

        target = B.OUT ();

        int ans = bfs ();
        printf ("%d\n", ans);
    }
    return 0;
}
