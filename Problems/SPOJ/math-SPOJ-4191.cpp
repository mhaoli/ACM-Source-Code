/*
 * Author:  Plumrain
 * Created Time:  2014-03-27 13:58
 * File Name: math-SPOJ-4191.cpp
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
const int maxn = 10005;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int64 d[maxn+5], num[maxn+5], cnt[maxn+5], last[maxn+5];

int64 C(int64 n){
    return n * (n-1) * (n-2) * (n-3) / 24;
}

void init(){
    clr (cnt, 0); clr (last, 0);
    repf (i, 2, maxn){
        for (int j = 2; j*j <= i; ++ j) if (i % j == 0){
            if (last[i/j] == j) cnt[i] = -5, last[i] = j;
            else if (last[i/j] % j) cnt[i] = 1 + cnt[i/j], last[i] = j * last[i/j];
            else cnt[i] = -5, last[i] = last[i/j];
            break;
        }
        if (!cnt[i]) cnt[i] = 1, last[i] = i;
        if (cnt[i] < 0) cnt[i] = -5;
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    init();

    int n;
    while (scanf ("%d", &n) != EOF){
        clr (num, 0); clr (d, 0);
        int tmp;
        repf (i, 0, n-1) scanf ("%d", &tmp), ++ num[tmp];

        repf (i, 2, maxn) for (int64 j = i; j <= maxn; j += i) d[i] += num[j];

        int64 ans = 0;
        repf (i, 2, maxn) if (cnt[i] > 0) ans += (cnt[i]&1 ? 1 : -1) * C(d[i]);
        cout << C(n) - ans << endl;
    }
    return 0;
}


