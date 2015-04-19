/*
 * Author:  Plumrain
 * Created Time:  2014/8/14 14:24:39
 * File Name: 1008.cpp
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
    int cas = 0;
    int64 x, k;
    while (scanf ("%I64d%I64d", &x, &k) != EOF){
        if (x + k <= 0) break;
        int cnt = 0, i;
        for (i = 1; i <= k; ++ i){
            x = 1LL * ceil ((x + 0.0) / i) * i;
            if (1LL * i * i >= x) ++ cnt;
            if (cnt >= 1000) break;
        }
        if (i < k){
            int64 dif = 1LL * ceil(x / (i+1.0)) * (i + 1) - x;
            x += (k - i) * dif;
        }
        printf ("Case #%d: %I64d\n", ++ cas, x);
    }
    return 0;
}
