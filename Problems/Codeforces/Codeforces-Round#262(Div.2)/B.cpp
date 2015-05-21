/*
 * Author:  Plumrain
 * Created Time:  2014/8/20 23:38:30
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
const int inf = (int)1e9;
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int a, b, c;

int ask_dig (int x){
    int ret = 0;
    while (x) ret += x % 10, x /= 10;
    return ret;
}

int calc (int x){
     int64 ret = 1;
     rep (i, 0, a-1) ret *= x;
     ret = ret * b + c;
     if (ret <= 0 || ret >= inf) return -1;
     return (int)ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    while (cin >> a >> b >> c){
        vi ans;
        rep (i, 1, 81){
            int x = calc (i);
            if (x == -1) continue;
            if (ask_dig ((int)x) == i) ans.pb (x);
        }
        cout << sz (ans) << endl;
        if (sz (ans)){
            rep (i, 0, sz(ans)-1){
                if (i) printf (" ");
                printf ("%d", ans[i]);
            }
            cout << endl;
        }
    }
    return 0;
}
