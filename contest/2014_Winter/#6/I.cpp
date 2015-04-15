/*
 * Author:  Plumrain
 * Created Time:  2014-02-15 13:03
 * File Name: I.cpp
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

int n;
string s;

int gao()
{
    if (sz(s) < 4) return 0;

    s[0] = s[1];
    int ret = 0;
    for (int i = 3; i < sz(s); ++ i) if (i % n == 0){
        bool u = 1;
        for (int j = 1; j < 4; ++ j) if (s[i-1] != s[i-j]) u = 0;

        if (u) s[i] = s[i-1], ++ ret;
        else if (i < sz(s)) s[i] = s[i+1];
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (cin >> n){
        cin >> s;
        cout << gao() << endl;
    }
    return 0;
}
