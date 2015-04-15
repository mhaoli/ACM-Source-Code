/*
 * Author:  Plumrain
 * Created Time:  2013-12-18 23:33
 * File Name: A.cpp
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

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define ALL(t) t.begin(),t.end()
#define INF 999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2147483647;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> pii;
typedef long long int64;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int n, m, x, y, a, b;
int gao(int x, int y, int ta, int tb)
{
    int da = abs(x - ta), db = abs(y - tb);
    if (da % a) return maxint;
    if (db % b) return maxint;
    
    int t1 = da / a, t2 = db / b;
    if (abs(t1-t2) & 1) return maxint;
    if (t1 == t2) return t1;
    if (t1 < t2){
        if (n < 2*a) return maxint;
        return t2;
    }
    else{
        if (m < 2*b) return maxint;
        return t1;
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (cin >> n >> m >> x >> y >> a >> b){
        int ans = min(gao(x, y, 1, 1), gao(x, y, 1, m));
        ans = min(ans, gao(x, y, n, m));
        ans = min(ans, gao(x, y, n, 1));
        if (ans == maxint) cout << "Poor Inna and pony!" << endl;
        else cout << ans << endl;
    }
    return 0;
}
