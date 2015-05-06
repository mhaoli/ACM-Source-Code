/*
 * Author:  Plumrain
 * Created Time:  2014-01-16 01:25
 * File Name: 3.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
//#include <string>
#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <cstdlib>
//#include <sstream>
//#include <fstream>
//#include <list>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <map>
//#include <set>
//#include <bitset>
//#include <cctype>
//#include <ctime>
//#include <utility>

using namespace std;

#define clr0(x) memset(x, 0, sizeof(x))
//#define clr1(x) memset(x, -1, sizeof(x))
//#define pb push_back
//#define sz(v) ((int)(v).size())
//#define all(t) t.begin(),t.end()
//#define INF 999999999999999999
//#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
//#define CINBEQUICKER std::ios::sync_with_stdio(false)
//
//const double eps = 1e-8;
//const double PI = atan(1.0)*4;
//const int inf = 2147483647 / 2;
//
//typedef vector<int> vi;
//typedef vector<string> vs;
//typedef vector<double> vd;
//typedef pair<int, int> pii;
typedef long long int64;
//
//inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}
//
const int N = 1000000;
bool v[N+1];

void sieve(int n)
{
    clr0 (v); v[0] = v[1] = 1;
    int64 m = (int)sqrt(n+0.5);
    for (int64 i = 2; i <= m; ++ i) if (!v[i])
        for (int64 j = i*i; j <= n; j += i) v[j] = 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    sieve(N);
    int64 x; cin >> x;
    int ans = 1;
    for (int64 i = 2; i*i <= x; ++ i) if (!v[i] && x % i == 0){
        ans = i;
        while (x % i == 0) x /= i;
    }
    if (x != 1) ans = x>ans ? x : ans;
    out (ans);
    return 0;
}
