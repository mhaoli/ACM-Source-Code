/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: C.cpp
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define INF 999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 100005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int d[N];
char s[N];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, k, q;
    while (scanf ("%d%d%d", &n, &k, &q) != EOF){
        scanf ("%s", s + 1);
        //clr (d);
        for (int i = 1; i <= k; ++ i){
            if (s[i] == '1') d[i] = 0;
            else d[i] = 1;

            for (int j = 1; j < i; ++ j) if (s[j] == '1') ++ d[i];
        }

        for (int i = k + 1; i <= n; ++ i){
            if (s[i] == '1') d[i] = d[i-k];
            else d[i] = d[i-k] + 1;
            
            for (int j = i-k+1; j < i; ++ j)
                if (s[j] == '1') ++ d[i];
        }

        //for (int i = 0; i <= n; ++ i) tst (i), out (d[i]);
       // 
        while (q--){
            int t1, t2;
            scanf ("%d%d", &t1, &t2);
            printf ("%d\n", d[t2] - d[t1-1]);
        }
    }
    return 0;
}
