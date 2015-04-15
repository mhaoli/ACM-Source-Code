/*
 * Author:  Plumrain
 * Created Time:  2014-02-09 15:51
 * File Name: H.cpp
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
#define clrs(x,y) memset(x, -1, sizeof(x))
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
const int maxn = 1000000;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int64 an[maxn + 5];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int64 k, b, n, t;
    while (cin >> k >> b >> n >> t){
        clr (an); an[0] = 1;
        int64 idx = n;
        for (int i = 1; i <= n; ++ i){
            an[i] = an[i-1] * k + b;
            if (an[i] > maxn){
                idx = i; break;
            }
        }
        int64 ans = 0;
        for (int i = 0; i <= idx; ++ i) if (t < an[i]){
            ans = n - i + 1; break;
        }
        cout << ans << endl;
    }
    return 0;
}
