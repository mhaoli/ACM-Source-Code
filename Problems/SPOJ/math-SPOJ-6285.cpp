/*
 * Author:  Plumrain
 * Created Time:  2014-03-27 09:20
 * File Name: math-SPOJ-NGM2.cpp
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
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
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

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int64 num[20];

int64 lcm (int64 a, int64 b){
    return a / __gcd (a, b) * b;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int64 n, m;
    while (cin >> n >> m){
        repf (i, 0, m-1) cin >> num[i];
        int64 ans = 0;
        repf (i, 1, (1<<m)-1){
            int64 cnt = 1;
            int64 tmp = __builtin_popcount(i)&1 ? 1 : -1;
            repf (j, 0, m-1) if (i & (1<<j)) cnt = lcm (cnt, num[j]);
            ans += tmp * (n / cnt);
        }
        cout << n - ans << endl;
    }
    return 0;
}
