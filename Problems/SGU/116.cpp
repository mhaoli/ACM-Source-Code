/*
 * Author:  Plumrain
 * Created Time:  2014/6/16 21:08:04
 * File Name: 116.cpp
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

int prm[10005], sprm[10005], d[10005], p[10005];
bool check[10005], svis[10005];

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

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    int tot = primes (n), stot = 0;
    
    clr (svis, 0);
    repf (i, 0, tot-1){
        if (prm[i] > tot) break;
        svis[prm[prm[i]-1]] = 1;
        sprm[stot++] = prm[prm[i]-1];
    }

    clr (d, 127);
    repf (i, 3, n){
        if (svis[i]){
            d[i] = 1; continue;
        }
        repf (j, 0, stot-1){
            if (sprm[j] > i) break;
            if (d[i - sprm[j]] + 1 < d[i]){
                d[i] = d[i-sprm[j]] + 1;
                p[i] = i - sprm[j];
            }
        }
    }

    if (d[n] >= inf) printf ("0\n");
    else{
        printf ("%d\n", d[n]); 
        vi ans;
        int pos = n;
        while (d[pos] != 1){
            ans.pb (pos - p[pos]);
            pos = p[pos];
        }
        ans.pb (pos);
        sort (all(ans), greater<int>() );
        repf (i, 0, sz(ans)-1){
            if (i) printf (" ");
            printf ("%d", ans[i]);
        }
        puts ("");
    }
    return 0;
}
