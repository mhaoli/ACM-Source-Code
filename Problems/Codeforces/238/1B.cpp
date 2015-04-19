/*
 * Author:  Plumrain
 * Created Time:  2014-03-23 00:29
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

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 1000005;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int an[maxn];
vi ans;
bool v[maxn];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, s = maxn - 5;
    while (scanf ("%d", &n) != EOF){
        clr (v, 0);
        repf (i, 0, n-1) scanf ("%d", &an[i]), v[an[i]] = 1;
        int cnt = 0;
        ans.clear();
        repf (i, 0, n-1){
            if (v[s-an[i]+1]) ++ cnt;
            else{
                int tmp = s - an[i] + 1;
                ans.pb (tmp); v[tmp] = 1;
            }
        }
        cnt /= 2;
        repf (i, 1, s) if (cnt){
            if (v[i] || v[s-i+1]) continue;
            v[i] = v[s-i+1] = 1;
            -- cnt;
            ans.pb (i); ans.pb (s-i+1);
        }
        printf ("%d\n", sz(ans));
        repf (i, 0, sz(ans)-1){
            if (i) printf (" ");
            printf ("%d", ans[i]);
        }
        printf ("\n");
    }
    return 0;
}
