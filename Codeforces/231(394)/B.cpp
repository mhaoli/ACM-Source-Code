/*
 * Author:  Plumrain
 * Created Time:  2014-02-20 23:50
 * File Name: B.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>

using namespace std;

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
//#define out(x) cout<<#x<<":"<<(x)<<endl
//#define tst(a) cout<<a<<" "
//#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 1000005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

char s[N];
int n, p;
int stk[N], sn;
int ans[N], an;

void OUT()
{
    for (int i = sn-1; i; -- i) printf ("%d", ans[i]);
    printf ("\n");
}

bool gao(int x)
{
    sn = 0;
    stk[++sn] = x;
    int tmp = 0;
    while (sn <= n){
        //if (x == 7 && sn == 1) out (stk[1]);
        int cnt = stk[sn] * p + tmp;
        stk[++sn] = cnt % 10;
        tmp = cnt / 10;
    }

    //if (x == 7){
        //for (int i = sn; i; -- i) printf ("%d", stk[i]);
        //printf ("\n");
    //}
//
    if (!tmp && stk[sn] == stk[1] && stk[sn-1] != 0){
        bool u = 0;
        for (int i = sn-1; i; -- i){
            if (stk[i] > ans[i]) return 1;
            else if (stk[i] < ans[i]){
                u = 1; break;
            }
        }

        if (!u) return 1;
        for (int i = 1; i < sn; ++ i) ans[i] = stk[i];
        return 1;
    }
    return 0;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d%d", &n, &p) != EOF){
        for (int i = 0; i <= n+1; ++ i) ans[i] = 9;
        if (n == 1){
            if (p == 1) printf ("1\n");
            else printf ("Impossible\n");
        }
        else{
            bool u = 0;
            for (int i = 1; i < 10; ++ i) if (gao(i)) u = 1;
            if (!u) printf ("Impossible\n");
            else OUT ();
        }
    }
    return 0;
}
