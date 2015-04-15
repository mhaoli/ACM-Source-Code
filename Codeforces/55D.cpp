/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: DP-CF-55D-2.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<cctype>
#include<ctime>
#include<utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define CLR1(x) memset(x, -1, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define INF 999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2147483647;
const int mod = 2520;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> pii;
typedef long long int64;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int dit[20], idx[mod+5];
int64 d[20][50][mod];

inline int lcm(int a, int b)
{
    if (!a || !b) return max(a, b);
    return a / __gcd(a, b) * b;
}

int64 rec(int p, int sum, int cnt)
{
    if (p < 0) return sum % cnt == 0;
    
    int64& ret = d[p][idx[cnt]][sum];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < 10; ++ i)
        ret += rec (p-1, (sum*10+i)%mod, lcm(cnt, i));
    return ret;
}

int64 gao(int64 x)
{
    if (x < 10) return x;

    int len = 0;
    while (x){
        dit[len++] = x % 10;
        x /= 10;
    }

    int sum = 0, cnt = 1;
    int64 ret = 0;
    for (int i = len-1; i >= 0; -- i){
        for (int t = 0; t < dit[i]; ++ t)
            ret += rec(i-1, (sum*10+t)%mod, lcm(cnt,t));

        cnt = lcm(cnt, dit[i]);
        sum = (sum*10 + dit[i]) % mod;
    }
    return ret;
}

void init()
{
    CLR1 (d);
    int all = 0;
    for (int i = 1; i <= mod; ++ i)
        if (mod % i == 0) idx[i] = all++;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    init();
    int T;
    scanf ("%d", &T);
    while (T--){
        int64 a, b;
        cin >> a >> b;
        cout << gao(b+1) - gao(a) << endl;
    }
    return 0;
}
