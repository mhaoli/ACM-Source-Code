/*
 * Author:  Plumrain
 * Created Time:  2013-12-13 22:14
 * File Name: B.cpp
 */
#include <iostream>
#include <cstdio>
//#include <cstring>
//#include <string>
//#include <cmath>
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

//#define CLR(x) memset(x, 0, sizeof(x))
//#define PB push_back
//#define SZ(v) ((int)(v).size())
//#define INF 999999999999
//#define zero(x) (((x)>0?(x):-(x))<eps)
//#define out(x) cout<<#x<<":"<<(x)<<endl
//#define tst(a) cout<<#a<<endl
//#define CINBEQUICKER std::ios::sync_with_stdio(false)
//
//const double eps = 1e-8;
//const double PI = atan(1.0)*4;
//const int maxint = 2147483647;
//
//typedef vector<int> VI;
//typedef vector<string> VS;
//typedef vector<double> VD;
//typedef pair<int, int> pii;
typedef unsigned long long int64;
//
//inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}
//

int64 gao2(int64 x)
{
    int64 ret = 0;
    while (x){
        ++ ret;
        x /= 10;
    }
    return ret;
}

int64 Mypow(int64 p, int64 n)
{
    int64 ret = 1;
    while (n > 0){
        if (n & 1) ret *= p;
        n >>= 1;
        p *= p;
    }
    return ret;
}

int64 gao(int64 n, int64 t)
{
    int64 len = gao2(n);
    int64 ret = 0, tmp = Mypow((int64)10, len);
    while (t > 0){
        int64 xxx = tmp - n;
        if (xxx * len <= t){
            ret += xxx;
            t -= xxx*len;
            n = tmp;
            tmp *= 10;
            ++ len;
        }
        else
            return ret + t / len;
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int64 w, m, k;
    while (cin >> w >> m >> k){
        int64 t = w / k;
        cout << gao(m, t) << endl;
    }
    return 0;
}
