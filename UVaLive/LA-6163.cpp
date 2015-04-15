/*
 * Author:  Plumrain
 * Created Time:  2014/8/2 15:13:04
 * File Name: CC.cpp
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

char ss[100];
int siz[100];
set<int> has[100];

bool ok (){
    repf (i, 0, 15) has[i].clear();
    siz[0] = 0;
    repf (i, 1, 15){
        siz[i] = siz[i>>1] + (i & 1);
        if (siz[i] != 1) continue;
        repf (j, 0, 3) if (i & (1<<j)) has[i].insert (ss[j] - '0');
    }

    repf (i, 1, 15){
        if (siz[i] == 1) continue;
        for (int j = i & (i-1); j > 0; j = i & (j-1)){
            repeach (k, has[j]) repeach (t, has[i^j]){
                int t1 = *k, t2 = *t;
                has[i].insert (t1 + t2);
                has[i].insert (t1 - t2);
                has[i].insert (t2 - t1);
                has[i].insert (t1 * t2);
                if (t2) has[i].insert (t1 / t2);
                if (t1) has[i].insert (t2 / t1);
            }
        }
    }
    return has[15].count (10);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    while (scanf ("%d", &n) != EOF && n){
        bool ans = 1;
        repf (i, 0, n-1){
            scanf ("%s", ss);
            if (!ok ()) ans = 0;
        }
        if (!ans) puts ("BUSTED");
        else puts ("TRUE");
    }
    return 0;
}
