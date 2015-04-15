/*
 * Author:  plum rain
 * Created Time:  2013-08-17 14:02
 * File Name: C.cpp
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
const int maxx = 1000005;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

int hash[maxx];
int all, an[maxx], bn[maxx];

void inte_dev(int x)
{
    all = -1;
    for (int i = 2; i*i <= x;){
        if (!(x%i))
            an[++all] = i, bn[all] = 0;
        while (!(x%i)){
            bn[all] ++;
            x /= i;
        }
        if (i == 2) ++ i;
        else i += 2;
    }
    ++ all;
    if (x != 1)
        an[all] = x, bn[all++] = 1;
}

void DFS(int pos, int num)
{
    if (pos == all){
        ++ hash[num];
        return;
    }
    int cnt = 1;
    for (int i = 0; i <= bn[pos]; ++ i){
        DFS(pos+1, num*cnt);
        cnt *= an[pos];
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF){
        CLR (hash);
        for (int i = 0; i < n; ++ i){
            int x;
            scanf ("%d", &x);
            inte_dev(x); 
            DFS(0, 1);
        }
        for (int i = 1000000; i >= 1; -- i)
            if (hash[i] > 1){
                printf ("%d\n", i);
                break;
            }
    }
    return 0;
}
