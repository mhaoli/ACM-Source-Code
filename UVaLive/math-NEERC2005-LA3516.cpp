/*
 * Author:  plum rain
 * Created Time:  2013-08-18 20:02
 * File Name: math-LA-3516.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define INF 999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int mod = 1000000000;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

string s;
int64 d[305][305];

int64 f(int l, int r)
{
    if (s[l] != s[r]) return 0;
    if (l == r) return 1;
    if (d[l][r] != -1) return d[l][r];

    int64 ret = 0;
    for (int i = l+2; i <= r; ++ i)
        if (s[l] == s[i])
            ret = (ret + f(l+1, i-1) * f(i, r)) % mod; 
    d[l][r] = ret;
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    s.clear();
    while (cin >> s){
        memset (d, -1, sizeof (d));
        cout << f(0, SZ (s) - 1) << endl;
        s.clear();
    }
    return 0;
}
