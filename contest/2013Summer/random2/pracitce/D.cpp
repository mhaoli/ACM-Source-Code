/*
 * Author:  plum rain
 * Created Time:  Wed 07 Aug 2013 02:36:35 PM CST
 * File Name: DD.cpp
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
const int N = 16;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

char s[11][11];
int an[11][11];
int opt[120];
int n, m;
int dp[1<<N];

void DP()
{
    for (int i = 0; i < 1<<N; i ++)
        dp[i] = maxint;
    dp[0] = 0;
    int ans = 0, ansn = maxint;
    for (int i = 0; i < 1<<N; i ++){
        for (int j = 1; j <= m; j ++)
            dp[i] = min (dp[i], dp[i - (i & opt[j])] + 1);
        if (dp[i] == maxint) continue;
        int num = 0;
        for (int j = 0;j < n; j ++)
            if (i & (1<<j)) num ++;
        if (num > ans){
            ans = num;
            ansn = dp[i];
            continue;
        }
        if (num == ans && ansn > dp[i])
            ansn = dp[i];
    }
    cout << ans << " " << ansn << endl;
}

int main()
{
    //freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        n = 0;
        for (int i = 1; i < 11; i ++){
            CLR(s[i]);
            scanf ("%s", s[i]+1); 
            for (int j = 1; j < 11; j ++)
                if (s[i][j] == 'e') an[i][j] = n ++;
        } 
        m = 0;
        for (int i = 1; i < 11; i ++){
            for (int j = 1; j < 11; j ++){
               int sta = 0; 
               bool flag = false;
               for (int a = i-1; a <= i+1; a ++)
                   for (int b = j-1; b <= j+1; b ++){
                       if (s[a][b] == 'g') flag = true;
                       if (s[a][b] == 'e') sta |= (1 << an[a][b]);
                   }
               if (!flag && sta) opt[++m] = sta;      
            }
        }
        DP();
    }
    return 0;
}

