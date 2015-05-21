/*
 * Author:  Plumrain
 * Created Time:  2014/7/24 23:49:06
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
typedef pair<pii, int> piii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int an[100005];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF){
        repf (i, 0, n-1) scanf ("%d", &an[i]);
        an[n] = inf;
        int cnt = 0, l = 0, r = 0;
        repf (i, 1, n-1) if (an[i] < an[i-1]){
            if (cnt){
                ++ cnt; break;
            }
            l = i - 1; ++ cnt;
            int pos = i;
            while (pos+1 < n && an[pos+1] < an[pos]) ++ pos;
            r = pos; i = pos;
        }
        if (cnt < 2){
            if (cnt == 1 && (an[l] >= an[r+1] || (l && an[r] <= an[l-1]))){
                puts ("no");
            }
            else printf ("yes\n%d %d\n", l+1, r+1);
        }
        else puts ("no");
    }
    return 0;
}
