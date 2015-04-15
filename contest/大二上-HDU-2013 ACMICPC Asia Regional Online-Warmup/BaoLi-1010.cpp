/*
 * Author:  Plumrain
 * Created Time:  2013-09-08 12:53
 * File Name: BaoLi.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
//#include<string>
#include<cmath>
#include<algorithm>
//#include<vector>
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

#define CLR(x) memset(x, 0, sizeof(x))
//#define PB push_back
//#define SZ(v) ((int)(v).size())
//#define INF 999999999999
//#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
//#define CINBEQUICKER std::ios::sync_with_stdio(false)

//typedef vector<int> VI;
//typedef vector<string> VS;
//typedef vector<double> VD;
//typedef long long int64;
//
//const double eps = 1e-8;
//const double PI = atan(1.0)*4;
//const int maxint = 2139062143;
const int N = 200;

//inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}
//
bool vis[N+1];
int prm[N+1];

void sieve(int n)
{
    int m = (int)sqrt(n + 0.5);
    CLR (vis);
    for (int i = 2; i <= m; ++ i) if (!vis[i])
        for (int j = i*i; j <= n; j += i) vis[j] = 1;
}

int primes(int n)
{
    sieve(n);
    int ret = 0;
    for (int i = 2; i <= n; ++ i)
        if (!vis[i]) prm[ret++] = i;
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int all = primes(N);

    for (int i = 2; i < N; i += 2){
        printf ("%d = ", i);
        bool ok = false;
        for (int j = 0; j < all; ++ j){
            if (!ok && !vis[prm[j]+i]){
                printf ("%d - %d\n", prm[j]+i, prm[j]);
                ok = true;
            }
        }
        if (!ok) printf ("FAIL\n");
    }

    return 0;
}
