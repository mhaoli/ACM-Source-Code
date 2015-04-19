/*
 * Author:  Plumrain
 * Created Time:  2014/9/14 12:09:24
 * File Name: 1001.cpp
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

string temp[] = {"Apple", "iPhone", "iPod", "iPad", "Sony"};
char ans[10][111] = {"MAI MAI MAI!", "MAI MAI MAI!", "MAI MAI MAI!", "MAI MAI MAI!", "SONY DAFA IS GOOD!"};
const int maxn = int(1e5) + 9;
char str[maxn];
//char ans[10][111];

bool ok (int t1, int t2){
    rep (i, 0, sz (temp[t2])-1){
        if (str[t1+i] != temp[t2][i]) return 0;
    }
    return 1;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    //clr (ans, 0);
    //rep (i, 0, 4){
        //rep (j, 0, sz (tt[i])-1) ans[i][j] = tt[i][j];
        //ans[i][sz(tt[i])] = '\0';
    //}

    //rep (i, 0, 4) printf ("%s\n", ans[i]);
//
    while (scanf ("%s", str) != EOF){
        int L = strlen (str);
        rep (i, 0, L-1) rep (j, 0, 4){
            if (ok (i, j)) printf ("%s\n", ans[j]);
        }
    }
    return 0;
}
