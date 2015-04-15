/*
 * Author:  Plumrain
 * Created Time:  2014/6/21 1:05:56
 * File Name: 126.cpp
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
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int64 a, b;
    cin >> a >> b;
    if (!a || !b){
        puts ("0"); return 0;
    }
    int64 tt = a / __gcd (a,b) * b;
    int64 sum = tt / a + tt / b;
    if (__builtin_popcount(sum) > 1) puts ("-1");
    else{
        if (a > b) swap (a, b);
        int64 cnt = 0;
        while (a){
            a *= 2; b -= a / 2;
            if (a > b) swap (a, b);
            ++ cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}
