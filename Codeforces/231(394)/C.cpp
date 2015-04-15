/*
 * Author:  Plumrain
 * Created Time:  2014-02-21 00:35
 * File Name: C.cpp
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
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int n, m, idx[20];
int an[1005][1005], num[10];
int ans[1005][1005];

void OUT (int x)
{
    if (x == 0) printf ("00");
    if (x == 1) printf ("01");
    if (x == 2) printf ("10");
    if (x == 3) printf ("11");
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    idx[0] = 0; idx[1] = 1; idx[10] = 2; idx[11] = 3;
    while (scanf ("%d%d", &n, &m) != EOF){
        clr (num);

        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j)
                scanf ("%d", &an[i][j]), an[i][j] = idx[an[i][j]], ++ num[an[i][j]];

        int tmp = num[1] + num[2];
        num[1] = tmp/2; num[2] = tmp - num[1];

        int tn = 0, tm = 0;
        clr (ans);
        int col = tmp / (2*m);
        for (int i = 0; i < 2*col; i += 2){
            for (int j = 0; j < m; ++ j) ans[i][j] = 2, -- num[2];
            for (int j = 0; j < m; ++ j) ans[i+1][j] = 1, -- num[1];
        }
        tn = 2 * col;

        if (num[1] || num[2]){
            tm = 0;
            while (tm < m){
                if (num[2] && num[1]){
                    ans[tn][tm] = 2; -- num[2];
                    ans[tn+1][tm] = 1, -- num[1];
                }
                else if (num[2] && !num[1]){
                    ans[tn][tm] = 2; -- num[2];

                    for (int i = tm+1; i < m && num[3] > 0; ++ i) ans[tn][i] = 3, -- num[3];
                    if (num[3]) for (int i = tm; i < m && num[3] > 0; ++ i) ans[tn+1][i] = 3, -- num[3];
                    tm = m - 1;
                }
                else{
                    for (int i = tm; i < m && num[3] > 0; ++ i) ans[tn][i] = 3, -- num[3];
                    if (num[3]) for (int i = tm; i < m && num[3] > 0; ++ i) ans[tn+1][i] = 3, -- num[3];
                    tm = m - 1;
                }

                ++ tm;
            }
            tn += 2;
        }

        tm = 0;
        while (tn < n && tm < m){
            if (num[3]) ans[tn][tm++] = 3, -- num[3];
            else break;

            if (tm == m) tm = 0, ++ tn;
        }

        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                if (j) printf (" ");
                OUT (ans[i][j]);
            }
            printf ("\n");
        }
    }
    return 0;
}
