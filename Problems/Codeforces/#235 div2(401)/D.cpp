/*
 * Author:  Plumrain
 * Created Time:  2014-03-11 00:23
 * File Name: D.cpp
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

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int64 mod;
vi num;
int cnt[20], tcnt[20];
map<vi, int64> st[20][105];

int64 dfs (int p, int yu, bool fir){
    if (p == -1) return !yu;
    vi tmp = num; sort (all(tmp));
    if (st[p][yu].count(tmp)) return st[p][yu][tmp];
    int64 ret = 0;
    for (int i = fir?1:0; i <= 9; ++ i) if (tcnt[i] < cnt[i]){
        ++ tcnt[i]; num.pb (i);
        ret += dfs (p-1, (yu*10 + i) % mod, 0);
        -- tcnt[i]; num.pop_back();
    }
    st[p][yu][tmp] = ret;
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int64 n, len;
    while (cin >> n >> mod){
        len = 0;
        clr (cnt, 0); clr (tcnt, 0);
        while (n){
            ++ cnt[n % 10];
            n /= 10;
            ++ len;
        }

        num.clear();
        repf (i, 0, mod) repf (j, 0, len) st[j][i].clear();
        cout << dfs (len-1, 0, 1) << endl;
    }
    return 0;
}
