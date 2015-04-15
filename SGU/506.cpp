/*
 * Author:  plum rain
 * Created Time:  2013-08-17 20:17
 * File Name: J.cpp
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
const int N = 100005;
const int M = 105;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

char st1[N], st2[M];
int hash[N][30];
int tmp[30];
int an[N];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    CLR (st1); CLR (st2); 
    while (scanf("%s%s", st1, st2) != EOF){
        int len1 = strlen(st1), len2 = strlen(st2);
        CLR (hash);
        memset (tmp, -1, sizeof(tmp));
        for (int i = len1-1; i >= 0; -- i){  
            for (int j = 0; j <= 'z'-'a'; ++ j)
                hash[i][j] = tmp[j];
            tmp[st1[i]-'a'] = i;
        }

        for (int i = 0; i < len1; i ++)
            an[i] = len1;
        for (int i = 0; i < len1; ++ i){
            int x = 0, pos = i;
            bool flag = true;
            if (st1[i] != st2[0]) continue;
            while (x < len2-1){
                x ++;
                pos = hash[pos][st2[x]-'a'];
                if (pos == -1){
                    flag = false;
                    break;
                }
            }
            if (flag)
                an[i] = pos;
        }
        
        int64 ans = 0, cnt = 1;
        for (int i = 0; i < len1; ++ i){
            if (an[i] == len1) cnt ++;
            else{
                ans += cnt * (len1 - an[i]);
                cnt = 1;
            }
        }
        printf ("%lld\n", ans);
    }
    return 0;
}
