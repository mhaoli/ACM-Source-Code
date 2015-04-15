/*
 * Author:  Plumrain
 * Created Time:  2014-02-11 13:10
 * File Name: B.cpp
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

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

string s;
int n;
int64 d[70][70];

int64 dp(int x, int y)
{
    if (x > y) return 1;
    if (x == y) return 2;
    
    int64 &ret = d[x][y];
    if (ret != -1) return ret;
    ret = 1;
    for (int i = x; i <= y; ++ i)
        for (int j = i; j <= y; ++ j)
            if (s[i] == s[j]) ret += dp (i + 1, j - 1);
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        cin >> s;
        n = sz(s);

        clrs (d, -1);
        int64 ans = 0;
        for (int i = 0; i < n; ++ i){
            for (int j = i; j < n; ++ j) {
                if (s[i] == s[j]) ans += dp (i + 1, j - 1);
                //tst (i), tst (j), out (ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
