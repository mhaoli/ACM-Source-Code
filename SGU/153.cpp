/*
 * Author:  Plumrain
 * Created Time:  2014/7/1 20:35:26
 * File Name: 153.cpp
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

int an[20], vis[1<<10];
bool f[100005];

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T; scanf ("%d", &T);
    while (T--){
        int n, m;
        scanf ("%d%d", &n, &m);
        an[0] = 1;
        repf (i, 1, m) scanf ("%d", an+i);
        sort (an, an + (++m));

        f[1] = 0;
        repf (i, 2, 9){
            f[i] = 0;
            repf (j, 0, m-1) if (i - an[j] > 0 && !f[i-an[j]]) f[i] = 1;
        }

        int start, K;
        clr (vis, -1);
        repf (i, 10, 1000){
            int sta = 0;
            repf (j, 0, 8) if (f[i-j-1]) sta |= (1 << j);
            if (vis[sta] == -1) vis[sta] = i;
            else{
                start = vis[sta]; K = i - start; break;
            }

            f[i] = 0;
            repf (j, 0, m-1) if (!f[i-an[j]]) f[i] = 1;
        }

        if (n < start) puts (f[n] ? "FIRST PLAYER MUST WIN" : "SECOND PLAYER MUST WIN");
        else{
            int tmp = (n - start) % K;
            puts (f[tmp + start] ? "FIRST PLAYER MUST WIN" : "SECOND PLAYER MUST WIN");
        }
    }
    return 0;
}
