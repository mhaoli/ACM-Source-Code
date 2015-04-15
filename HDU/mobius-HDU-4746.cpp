/*
 * Author:  Plumrain
 * Created Time:  2014-04-04 13:23
 * File Name: mobius-HDU-4746.cpp
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
const int maxn = 500005;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

bool check[maxn];
int prm[maxn], mu[maxn], g[maxn][25], sum[maxn][25];

void init(int n){
    clr (check, 0); clr (g, 0);
    check[1] = 1;
    g[1][0] = mu[1] = 1;
    int tot = 0;
    repf (i, 2, n){
        if (!check[i]){
            prm[tot++] = i;
            g[i][0] = mu[i] = -1;
            g[i][1] = 1;
        }
        repf (j, 0, tot-1){
            int tmp = prm[j] * i;
            if (tmp > n) break;
            check[tmp] = 1;
            if (i % prm[j]){ 
                mu[tmp] = -mu[i];
                g[tmp][0] = mu[tmp];
                repf (k, 1, 20) g[tmp][k] = g[i][k-1] - g[i][k];
            }
            else{
                mu[tmp] = 0; 
                g[tmp][0] = mu[tmp];
                repf (k, 1, 20) g[tmp][k] = g[i][k-1];
                break;
            }
        }
    }

    //repf (i, 0, 10){
        //out (i);
        //repf (j, 0, 20) tst (g[i][j]);
        //cout << endl;
    //}
//
    clr (sum, 0);
    repf (i, 1, maxn){
        sum[i][0] = g[i][0] + sum[i-1][0];
        repf (j, 1, 20) sum[i][j] += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + g[i][j];
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    init(maxn - 5);

    int T;
    scanf ("%d", &T);
    while (T--){
        int n, m, num;
        scanf ("%d%d%d", &n, &m, &num);
        checkmin (num, 20);
        int64 ans = 0;
        for (int i = 1, la = 0; i <= min(n, m); i = la + 1){
            la = min (n/(n/i), m/(m/i));
            ans += 1LL * (n / i) * (m / i) * (sum[la][num] - sum[i-1][num]);
        }
        cout << ans << endl;
    }
    return 0;
}
