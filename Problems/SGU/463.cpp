/*
 * Author:  Plumrain
 * Created Time:  2014/8/10 13:38:03
 * File Name: K.cpp
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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
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

/*
   0
 3   1
   2
   */

int n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

char ss[2000];
bool vis[300][300];
int an[300][300];

int calc (int x, int y){
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    int tmp = an[x][y]; 
    if (vis[x][y]) tmp /= 2;
    vis[x][y] = 1;
    return tmp;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    cin >> n >> m;
    clr (an, 0); clr (vis, 0);
    repf (i, 0, n-1){
        scanf ("%s", ss);
        repf (j, 0, m-1){
            an[i<<1|1][j<<1|1] = ss[j] - '0';
        }
    }
    n = n << 1 | 1; m = m << 1 | 1;

    //repf (i, 0, n-1){
        //repf (j, 0, m-1) tst (an[i][j]);
        //cout << endl;
    //}
//
    string pat;
    cin >> pat;
    int px = 0, py = 0, dir = 1, ans = 0;
    repf (i, 0, sz(pat)-1){
        if (pat[i] == 'M'){
            int tx = px + 2*dx[dir], ty = py + 2*dy[dir];
            ans += calc ((tx+px)/2 + (1-abs(dx[dir])), (ty+py)/2 + (1-abs(dy[dir])));
            ans += calc ((tx+px)/2 - (1-abs(dx[dir])), (ty+py)/2 - (1-abs(dy[dir])));
            px = tx; py = ty;
        }
        else if (pat[i] == 'L') dir = (dir + 3) % 4;
        else dir = (dir + 1) % 4;
    }
    cout << ans << endl;
    return 0;
}
