/*
 * Author:  Plumrain
 * Created Time:  2014-03-05 23:48
 * File Name: A.cpp
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

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)
#define repd(i, a, b) for(int64 i = (a); i >= (int64)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

char s[100];
vector<pii > ans;

bool gao(int tmp){
    if (12 % tmp) return 0;
    int x = 12 / tmp;
    repf (i, 0, x-1){
        bool u = 1;
        for (int j = i; j < 12; j += x)
            if (s[j] != 'X'){
                u = 0; break;
            }
        if (u) return 1;
    }
    return 0;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        scanf ("%s", s);
        ans.clear();
        repf (i, 1, 12){
            if (!gao(i)) continue;
            ans.pb (mp (i, 12/i));
        }

        printf ("%d", sz(ans));
        repf (i, 0, sz(ans)-1)
            printf (" %dx%d", ans[i].first, ans[i].second);
        printf ("\n");
    }
    return 0;
}
