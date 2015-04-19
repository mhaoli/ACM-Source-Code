/*
 * Author:  Plumrain
 * Created Time:  2013-12-26 12:49
 * File Name: D.cpp
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

#define clr0(x) memset(x, 0, sizeof(x))
#define clr1(x) memset(x, -1, sizeof(x))
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

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef long long int64;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int n, m;
int p[5005][5005], num[5005];
char v[5005][5005];

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d%d", &n, &m) != EOF){
        string s;
        for (int i = 0; i < n; ++ i)
            scanf ("%s", v[i]);
        for (int i = 0; i < n; ++ i){
            int tmp = m;
            for (int j = m-1; j >= 0; -- j){
                if (v[i][j] == '0') 
                    tmp = j, p[i][j] = j;
                else
                    p[i][j] = tmp;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++ i){
            clr0 (num);
            for (int j = 0; j < n; ++ j) num[p[j][i] - i] ++;
            int pos = 5000;
            while (pos && num[pos] == 0) -- pos;
            int cnt = 0;
            while (pos){
                if (num[pos]) cnt += num[pos];
                ans = max(cnt*pos, ans);
                -- pos;
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}
