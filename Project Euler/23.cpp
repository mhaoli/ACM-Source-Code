/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 23.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
//#include<string>
//#include<cmath>
//#include<algorithm>
#include<vector>
//#include<cstdlib>
//#include<sstream>
//#include<fstream>
//#include<list>
//#include<deque>
//#include<queue>
//#include<stack>
//#include<map>
//#include<set>
//#include<bitset>
//#include<cctype>
//#include<ctime>
//#include<utility>

using namespace std;

#define clr(x) memset(x, 0, sizeof(x))
//#define clrs(x, y) memset(x, y, sizeof(x))
#define pb push_back
//#define mp make_pair
#define sz(v) ((int)(v).size())
//#define INF 999999999999
//#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
//#define tst(a) cout<<#a<<endl
//#define CINBEQUICKER std::ios::sync_with_stdio(false)

//const double eps = 1e-8;
//const double PI = atan(1.0)*4;
//const int inf = 2147483647 / 2;
const int N = 28200;
//
typedef vector<int> vi;
//typedef vector<string> vs;
//typedef vector<double> vd;
typedef long long int64;
//typedef pair<int, int> pii;
//
//inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}
//
int v[N];
bool gao(int x)
{
    vi div; div.clear(); div.pb (1);
    for (int64 i = 2; i*i <= x; ++ i) if (x % i == 0){
        div.pb (i); if (i*i != x) div.pb (x/i);
    }
    int sum = 0;
    for (int i = 0; i < sz(div); ++ i){
        sum += div[i];
        if (sum > x) return 1;
    }
    return 0;
}
int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    clr (v);
    for (int i = 1; i < N; ++ i) if (gao(i)) v[i] = 1;
    int sum = 0;
    for (int i = 0; i < N; ++ i){
        bool u = 0;
        for (int j = 1; j < i; ++ j)
            if (v[j] && v[i-j]) u = 1;
        if (!u) sum += i;
        if (!u && i > 28120) out (i);
    }
    out (sum);
    return 0;
}
