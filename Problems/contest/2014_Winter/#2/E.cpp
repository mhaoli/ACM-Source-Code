/*
 * Author:  Plumrain
 * Created Time:  2014-02-11 19:00
 * File Name: E.cpp
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int mod = 1000000007;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int64, int64> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

vector<pii > vec;

bool is_prm(int x)
{
    for (int64 i = 2; i*i <= x; ++ i)
        if (x % i == 0) return 0;
    return 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, cas = 0;
    scanf ("%d", &T);
    while (T--){
        int64 n, k;
        scanf ("%lld%lld", &n, &k);

        vec.clear();
        for (int i = 2; i < n; ++ i) if (is_prm(i)){
            long long p = n;
            int64 cnt = 0;
            while (p){
                p /= i; cnt += p;
            }

            if (cnt < k) break;
            vec.pb (make_pair(i, cnt));
        }
        //out (sz(vec));
//
        //for (int i = 0; i < sz(vec); ++ i) tst (vec[i].first), tst (vec[i].second), cout << endl;

        int64 ans1 = 1, ans2 = 1;
        for (int i = 0; i < sz(vec); ++ i)
            ans1 = ans1 * (1 + vec[i].second / k) % mod;
        for (int i = 0; i < sz(vec); ++ i)
            ans2 = ans2 * (1 + vec[i].second / (k+1)) % mod;
        printf ("Case %d: %d\n", ++ cas, (int)(((ans1 - ans2) % mod + mod) % mod));
        //cout << endl;
    }
    return 0;
}
