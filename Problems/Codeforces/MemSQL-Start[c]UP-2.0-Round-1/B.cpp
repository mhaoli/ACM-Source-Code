/*
 * Author:  Plumrain
 * Created Time:  2014/8/15 9:47:03
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
#define sqr(x) ((x) * (x))
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

double dis (pii a, pii b){
    return sqrt (sqr (a.x - b.x) + sqr (a.y - b.y) + 0.0);
}

double calc (const vii &v){
    double ret = 0;
    repf (i, 1, 3) ret += dis (v[i], v[i-1]);
    return ret;
}

struct nod{
    vii v;
    bool operator<(const nod &t)const{
        return calc (v) < calc (t.v);
    }
    void init (int n, int m){
        v.resize (4); vii tmp; tmp.resize (4);
        tmp[0] = mp (0, 0); tmp[1] = mp (n, m); tmp[2] = mp (0, m); tmp[3] = mp (n, 0);
        if (m != 1){
            v[0] = mp(0, 1); v[1] =  mp(n, m); v[2] = mp(0, 0); v[3] = mp(n, m-1);
            if (calc (tmp) < calc (v)) tmp = v;
        }
        v = tmp;
    }
    void init2 (int n, int m){
        v.resize (4);
        vii tmp; tmp.resize (4);
        tmp[0] = mp (0, 0); tmp[1] = mp (n, m); tmp[2] = mp (n, 0); tmp[3] = mp (0, m);
        if (n != 1){
            v[0] = mp (n-1, m); v[1] = mp (0, 0); v[2] = mp (n, m); v[3] = mp (1, 0);
            if (calc (tmp) < calc (v)) tmp = v;
        }
        v = tmp;
    }
};

nod gao (int n, int m){
    nod ret, tmp; ret.init (n, m); tmp.v.resize (4);

    if (n > 1){
        tmp.v[0] = mp (1, 0); tmp.v[1] = mp (n, 0); tmp.v[2] = mp (0, 0); tmp.v[3] = mp (n-1, 0);
        if (!m) ret = tmp;
        else if (ret < tmp) ret = tmp;
    }
    if (m > 1){
        tmp.v[0] = mp (0, 1); tmp.v[1] = mp (0, m); tmp.v[2] = mp (0, 0); tmp.v[3] = mp (0, m-1);
        if (!n) ret = tmp;
        else if (ret < tmp) ret = tmp;
    }
    if (!m || !n) return ret;

    tmp.init (n, m);
    if (ret < tmp) ret = tmp;
    tmp.init2 (n, m); 
    if (ret < tmp) ret = tmp;
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m;
    while (cin >> n >> m){
        nod ans = gao (n, m);
        for (auto i : ans.v) printf ("%d %d\n", i.x, i.y);
    }
    return 0;
}
