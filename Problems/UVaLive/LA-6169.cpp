/*
 * Author:  Plumrain
 * Created Time:  2014/8/2 14:20:49
 * File Name: I.cpp
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int ans;
int up[] = {20, 20, 20, 25, 25, 30, 30};
int cnt[100], d[10][500];
int num[100];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    while (1){
        int sum = 0;
        repf (i, 0, 6){
            scanf ("%d", cnt+i);
            sum += cnt[i];
        }
        if (!sum) break;

        clr (d, 127); d[0][cnt[0]] = 0;
        repf (i, 1, 6) repf (j, 0, 200) if (d[i-1][j] < inf){
            repf (k, 0, j){
                int tmp = ceil ((k + 0.0) / up[i-1]), tmp2 = ceil ((j - k + 0.0) / up[i-1]);
                int yu = tmp2 * up[i-1] - (j - k), mi = min (yu, cnt[i]);
                chmin (d[i][cnt[i]-mi], d[i-1][j] + tmp + tmp2);
            }
        }

        int ans = inf;
        repf (i, 0, 200) chmin (ans, d[6][i] + (int)ceil((i + 0.0) / up[6]));
        printf ("%d\n", ans);
    }
    return 0;
}
