/*
 * Author:  Plumrain
 * Created Time:  2014-02-15 16:48
 * File Name: F.cpp
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
const int N = 100005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

struct cmp{
    bool operator() (int a, int b){
        return a < b;
    }
};

int n, x, y, an[N];
int64 h1, h2, mh2;
priority_queue<int, vector<int>, cmp> q;

bool calc(int64 &ans)
{
    while (sz(q)) q.pop();
    for (int i = 0; i < n; ++ i){
        q.push (max(an[i], y));
        h1 -= an[i]; h2 -= x;

        if (h2 <= 0){
            ans = i + 1;
            return 1;
        }

        if (i == n-1){
            ans = ans > mh2 - h2 ? ans : mh2 - h2;
            return 0;
        }

        while (sz(q) && h1 <= 0){
            ans = (ans > mh2 - h2 ? ans : mh2 - h2);
            h2 += x;
            h1 += q.top();
            q.pop();
        }

        if (h1 <= 0){
            ans = (ans > mh2 - h2 ? ans : mh2 - h2);
            return 0;
        }
    }

    ans = max(ans, mh2 - (h2 - x));
    return 0;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (cin >> n >> x >> y >> h1 >> h2){
        mh2 = h2;
        for (int i = 0; i < n; ++ i) scanf ("%d", &an[i]);

        int64 ans = 0;
        bool u = calc(ans);
        if (u) printf ("Win");
        else printf ("Lose");
        cout << endl << ans << endl;
    }
    return 0;
}
