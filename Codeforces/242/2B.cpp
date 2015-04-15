/*
 * Author:  Plumrain
 * Created Time:  2014/4/25 15:42:12
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
const int maxn = 1000000;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct nod{
    int x, y, num;
}an[1005];

double dis (int x, int y){
    return sqrt (0.0 + x*x + y*y);
}

bool cmp (nod a, nod b){
    return dis (a.x, a.y) < dis (b.x, b.y);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, sum;
    while (cin >> n >> sum){
        repf (i, 0, n-1) scanf ("%d%d%d", &an[i].x, &an[i].y, &an[i].num);
        sort (an, an+n, cmp);
        double ans = 0;
        repf (i, 0, n-1){
            sum += an[i].num;
            chmax (ans, dis (an[i].x, an[i].y));
            if (sum >= maxn) break;
        }
        if (sum >= maxn) printf ("%.8f\n", ans);
        else cout << "-1" << endl;
    }
    return 0;
}
