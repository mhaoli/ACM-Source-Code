/*
 * Author:  plum rain
 * Created Time:  2013-08-23 21:00
 * File Name: (good)-math-WF2008-LA-4119.cpp
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

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

struct P{
    int k, a, b;
    //k * n ^ a
    void clr(){
        k = 0; a = 0;
    }
};

P a[105];
int tot;
string s;
int mod;

int64 Mypow(int64 p, int64 n)
{
    int64 ret = 1;
    while (n > 0){
        if (n & 1)
            ret = (ret * p) % mod;
        n >>= 1;
        p = (p * p) % mod; 
    }
    return ret;
}

void init()
{
    int size = SZ (s);
    int pos = 1;
    for (int i = 0; i < 105; ++ i)
        a[i].clr();
    bool add = true;
    tot = -1;
    while (pos < size){
        if (s[pos] == '-')
            ++ pos, add = false;
        if (s[pos] == '+')
            ++ pos, add = true;

        if (s[pos] == 'n'){
            a[++tot].k = 1;
            a[tot].a = 1;
            ++ pos;
        }
        else{ 
            a[++tot].k = 0;
            while (s[pos] >= '0' && s[pos] <= '9'){
                a[tot].k = a[tot].k * 10 + s[pos] - '0';
                ++ pos;
            }
        }
        if (!add) a[tot].k *= -1;

        if (s[pos] == 'n'){
            a[tot].a = 1;
            ++ pos;
        }

        if (s[pos] == '^'){
            ++ pos;
            a[tot].a = 0;
            while (s[pos] >= '0' && s[pos] <= '9'){
                a[tot].a = a[tot].a * 10 + s[pos] - '0';
                ++ pos;
            }
        }

        if (s[pos] == ')'){
            pos += 2;
            break;
        }
    }
    ++ tot;

    mod = 0;
    while (pos < size){ 
        mod = mod * 10 + s[pos] - '0';
        ++ pos;
    }
}

bool is_int(int x)
{
    int64 tmp = 0;
    for (int i = 0; i < tot; ++ i){
        tmp = (tmp + (((int64)a[i].k * Mypow((int64)x, (int64)a[i].a)) % mod)) % mod;
    }
    if (!(tmp % mod)) return true;
    return false;
}

bool solve ()
{
    for (int i = 1; i <= a[0].a+1; ++ i)
        if (!is_int(i)) return false;
    return true;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    s.clear();
    int test = 0;
    while (cin >> s && s[0] != '.'){
        init ();

        cout << "Case " << ++test << ": ";
        if (solve()) cout << "Always an integer" << endl;
        else cout << "Not always an integer" << endl;
    }
    return 0;
}
