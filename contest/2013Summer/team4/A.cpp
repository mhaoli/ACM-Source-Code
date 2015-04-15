/*
 * Author:  plum rain
 * Created Time:  2013-08-14 19:22
 * File Name: 
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

char s[5];
int hash[910000], now[910000], an[500005];

int toten()
{
    int len = strlen (s) - 1, pos = 0;
    int ret = 0;
    while (len >= 0){
        if (len == 2) ret += (s[pos]-33) * 10000;
        if (len == 1) ret += (s[pos]-33) * 100;
        if (len == 0) ret += s[pos] - 33;
        -- len;
        ++ pos;
    }
    return ret;
}

int main()
{
//    freopen("A.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    CLR (s); 
    CLR (hash);
    int tot = 0;
    char tmp;
    while (scanf ("%s", s) != EOF){
        int key = toten (); 
        hash[key] ++;
        tot ++;
        CLR (s);
        scanf ("%c", &tmp);
        if (tmp != ' ') break;
    }

    int pos = -1;
    while (scanf ("%s", s) != EOF){
        int key = toten();
        an[++pos] = key;
        scanf ("%c", &tmp);
        if (tmp != ' ') break;
    }

    int l = 0, r = -1, need = tot, ans = 0;
    CLR (now);
    while (r < pos){ 
        if (r == l + tot - 1){
            if (hash[an[l]] >= now[an[l]])
                ++ need;
            -- now[an[l]];
            ++ l; 
        }
        
        ++ r;
        ++ now[an[r]];
        if (hash[an[r]] >= now[an[r]])
            -- need;
        if (!need)
            ans ++;
    }
    printf ("%d\n", ans);
    return 0;
}
