/*
 * Author:  Plumrain
 * Created Time:  2014/9/12 18:46:21
 * File Name: HDU3608.cpp
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

const int maxn = 110000 + 9;

char str[maxn];
int len[maxn*2];

int manacher (char *str, int *len, int n){
    for (int i = 0; i < 2*n; ++ i) len[i] = 0;
    int mx = 0;
    for (int i = 0, j = 0, k; i < 2*n; i += k, j = max (j-k, 0)){
        while (i - j >= 0 && i + j + 1 < 2*n && str[(i-j) / 2] == str[(i+j+1) / 2]) ++ j;
        len[i] = j;
        chmax (mx, j);
        for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] != j - k; ++ k){
            len[i+k] = min (len[i - k], j - k);
        }
    }
    return mx;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    while (scanf ("%s", str) != EOF){
        printf ("%d\n", manacher (str, len, strlen (str)));
    }
    return 0;
}
