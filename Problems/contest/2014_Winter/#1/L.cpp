/*
 * Author:  Plumrain
 * Created Time:  2014-02-10 15:14
 * File Name: L.cpp
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
#define clrs(x,y) memset(x, -1, sizeof(x))
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

int cnt[5][5];

void gao(int x, int y)
{
    for (int i = 0; i < 4; ++ i)
        cnt[x][i] ++, cnt[i][y] ++;
    cnt[x][y] --;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    string s;
    clr (cnt);
    for (int i = 0; i < 4; ++ i){
        cin >> s;
        for (int j = 0; j < 4; ++ j) 
            if (s[j] == '+') gao(i, j);
    }

    int ans = 0;
    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j){
            cnt[i][j] = cnt[i][j] & 1;
            if (cnt[i][j]) ++ ans;
        }
    printf ("%d\n", ans);
    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j)
            if (cnt[i][j]) printf ("%d %d\n", i + 1, j + 1);
    return 0;
}
