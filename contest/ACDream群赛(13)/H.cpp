/*
 * Author:  Plumrain
 * Created Time:  2014/6/8 18:24:01
 * File Name: F_tst.cpp
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
const int maxn = 40000;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi num;
set<int> ans;

void init(){
    ans.clear(); ans.insert (1); ans.insert (3);
    num.clear(); num.pb (1); num.pb (3);
    priority_queue<int> q; q.push (1); q.push(3);
    while (sz(q)){
        int t = q.top(); q.pop();
        repf (i, 0, sz(num)-1){
            int tmp = (t + 2) * (num[i] + 2) - 2;
            if (tmp > maxn) continue;
            if (!ans.count(tmp)) ans.insert (tmp), num.pb (tmp), q.push (tmp);
        }
    }
    sort (all(num), greater<int>());
}

bool solve (int n){
    if ( !(n & 1) ) return 0;
    if (n <= maxn){
        if (ans.count (n)) return 1;
        return 0;
    }

    n += 2;
    repf (i, 0, sz(num)-1){
        if (n % (num[i] + 2)) continue;
        if (solve (n / (num[i] + 2) - 2)) return 1;
    }
    return 0;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    init(); 
    
    int n;
    while (scanf ("%d", &n) != EOF) 
        if (solve (n)) printf ("Yes\n");
        else printf ("No\n");
    return 0;
}
