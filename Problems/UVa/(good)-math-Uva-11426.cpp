/*
 * Author:  plum rain
 * Created Time:  2013-09-02 07:15
 * File Name: math-Uva-11426.cpp
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
const int N = 4000000;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

int64 s[N+1], f[N+1];
int64 phi[N+1];

void phi_table(int n)
{
    CLR(phi);
    phi[1] = 1;
    for (int i = 2; i <= n; ++ i)
        if (!phi[i]){
            for (int j = i; j <= n; j += i){
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i-1);
            }
        }
}

int main()
{
    phi_table(N);

    CLR (f);
    for (int i = 1; i <= N; ++ i)
        for (int j = i*2; j <= N; j += i)
            f[j] += i * phi[j / i];

    s[2] = f[2];
    for (int i = 3; i <= N; ++ i)
        s[i] = s[i-1] + f[i];
    
    int n;
    while (scanf ("%d", &n) == 1 && n)
        printf ("%lld\n", s[n]);

    return 0;
}
