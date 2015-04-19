/*
 * Author:  Plumrain
 * Created Time:  2014/6/24 13:44:51
 * File Name: 137.cpp
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

int ans[1005];

void gcd(int64 a, int64 b, int64 &d, int64 &x, int64 &y){
    if (!b) d = a, x = 1, y = 0;
    else{
        gcd (b, a%b, d, y, x);
        y -= x * (a / b);
    }
}

int inv (int64 a, int mod){
    int64 d, x, y;
    gcd (a, mod, d, x, y);
    return d == 1 ? (x+mod)%mod : -1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, sum;
    cin >> n >> sum;
    int yu = sum % n, k = sum / n;
    repf (i, 1, n-1){
        int tmp = inv (i, n);
        if (tmp == -1) continue;
        if (tmp != yu) continue;
        int num = k, pos = 0;
        while (1){
            ans[pos] = num;
            pos += i; if (pos >= n) pos -= n;
            if (pos == n-1) ++ num;
            if (pos == 0) break;
        }
        repf (j, 0, n-1){
            if (j) printf (" ");
            printf ("%d", ans[j]);
        }
        puts ("");
        break;
    }
    return 0;
}