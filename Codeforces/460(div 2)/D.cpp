/*
 * Author:  Plumrain
 * Created Time:  2014/8/22 19:16:47
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
#define two(x) (1<<(x))
#define twol(x) (1ll<<(x))
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define rep(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)
#define red(i, a, b) for(int64 i = (a); i >= (int64)(b); i --)
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
const int inf = 2147483647 / 2;
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct nod{
    int64 v;
    vi an;
    nod(){
        v = 0; an.clear();
    }
    void pb (int64 x){
        v ^= x; an.pb (x);
    }
    bool operator<(const nod &t)const{
        if (!sz (an)) return 0;
        if (!sz (t.an)) return 1;
        return v < t.v;
    }
    void calc (int64 l, int k){
        if (l & 1) ++ l;
        rep (i, l, l+k-1) pb (i);
    }
    void OUT(){
        cout << v << endl; cout << sz (an) << endl;
        rep (i, 0, sz (an)-1){
            if (i) cout << " ";
            cout << an[i];
        }
        cout << endl;
    }
};

nod ans;

int64 l, r, k;
bool vis[111];

void dfs (int64 p, int64 s, int cnt){
    if (p > r){
        if (!cnt || cnt > k) return;
        nod t;
        rep (i, l, r) if (vis[i-l]) t.pb (i);
        chmin (ans, t);
        return;
    }

    dfs (p+1, s, cnt);
    vis[p-l] = 1;
    dfs (p+1, s^p, cnt+1);
    vis[p-l] = 0;
}

int64 find (int64 t){
    int64 ret = 1;
    while ((ret<<1) <= t) ret <<= 1;
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    while (cin >> l >> r >> k){
        ans.an.clear();
        if (r - l + 1 <= 5) clr (vis, 0), dfs (l, 0, 0);
        else if (k == 1) ans.pb (l);
        else if (k == 2 || k >= 4) ans.calc (l, k > 4 ? 4 : k);
        else{
            int64 lp = find (l), mp = lp << 1, rp = find (r);
            if (mp == (rp<<1)) ans.calc (l, 2);
            else if (mp < rp){
                ans.pb (l); ans.pb (mp); ans.pb (l^mp);
            }
            else{
                if ((rp^lp) > r) ans.calc (l, 2);
                else{
                    ans.pb (rp-1); ans.pb (rp^lp); ans.pb ((rp^lp)-1);
                }
            }
        }
        ans.OUT ();
    }
    return 0;
}
