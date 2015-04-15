/*
 * Author:  Plumrain
 * Created Time:  2014-04-04 01:49
 * File Name: euler-HYSBZ-2818.cpp
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
const int maxn = 10000000;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

bool check[maxn+5];
int phi[maxn+5], prm[maxn+5];
int64 sum[maxn+5];

int init(int n){
    clr (check, 0); check[1] = phi[1] = 1;
    int tot = 0;
    repf (i, 2, n){
        if (!check[i]){
            prm[tot++] = i; phi[i] = i - 1;
        }
        repf (j, 0, tot-1){
            int tmp = prm[j] * i;
            if (tmp > n) break;
            check[tmp] = 1;
            if (i % prm[j]) phi[tmp] = phi[i] * (prm[j] - 1);
            else{
                phi[tmp] = phi[i] * prm[j];
                break;
            }
        }
    }

    clr (sum, 0);
    repf (i, 1, n) sum[i] += sum[i-1] + phi[i];
    return tot;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, tot = init(maxn);
    while (scanf ("%d", &n) != EOF){
        int64 ans = 0;
        repf (i, 0, tot-1) if (n >= prm[i]) ans += 2 * sum[n/prm[i]] - 1;
        cout << ans << endl;
    }
    return 0;
}
