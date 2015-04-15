/*
 * Author:  Plumrain
 * Created Time:  2014/6/16 13:47:48
 * File Name: 113.cpp
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
const int maxn = 40005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool check[maxn];
int prm[maxn], tot;

int primes(int n){
    clr (check, 0); 
    int ret = 0; 
    repf (i, 2, n){
        if (!check[i]) prm[ret++] = i;
        repf (j, 0, ret-1){
            if (i * prm[j] > n) break;
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
    return ret;
}

bool ok (int n){
    if (n <= 40000) return !check[n];
    repf (i, 0, tot-1){
        if (prm[i] * prm[i] > n) break;
        if (n % prm[i] == 0) return 0;
    }
    return 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    tot = primes(40000);
    int T;
    scanf ("%d", &T);
    while (T--){
        int n, ans = 0;
        scanf ("%d", &n);
        if (n <= 0) ans = 0;
        else repf (i, 0, tot-1){
            if (prm[i] * prm[i] > n) break;
            if (n % prm[i] == 0 && ok (n / prm[i])){
                ans = 1; break;
            }
        }
        if (ans) puts ("Yes");
        else puts ("No");
    }
    return 0;
}
