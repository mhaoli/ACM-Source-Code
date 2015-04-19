/*
 * Author:  Plumrain
 * Created Time:  2014-03-19 23:38
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

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int n, k;
vector<pii > an;
vi son[100005];

int calc(int cnt){
    if (cnt != 1) return -1;
    int last = -1, pos = 0;
    repf (i, 1, sz(an)-1){
        if (i==1 || an[i].first != an[i-1].first) last = pos, pos = i;

        pii t = an[last];
        if (t.first + 1 != an[i].first) return -1;
        son[t.second].pb (an[i].second);

        if (an[i].first == 1){
            while (last <= n && sz(son[an[last].second]) >= k) ++ last;
            if (sz(son[an[last].second]) >= k) return -1;
        }
        else {
            while (last <= n && sz(son[an[last].second]) >= k-1) ++ last;
            if (sz(son[an[last].second]) >= k-1) return -1;
        }
    }
    return n-1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (cin >> n >> k){
        int t, cnt = 0;
        an.clear();
        repf (i, 1, n){
            son[i].clear();

            scanf ("%d", &t);
            if (!t) ++ cnt;
            an.pb (mp (t, i));
        }
        sort (all(an));
//
        //repf (i, 0, sz(an)-1){
            //tst (an[i].first); out (an[i].second);
        //}

        int ans = calc(cnt);
        printf ("%d\n", ans);
        if (ans != -1){
            repf (i, 1, n) repf (j, 0, sz(son[i])-1) 
                printf ("%d %d\n", i, son[i][j]);
        }
    }
    return 0;
}
