/*
 * Author:  Plumrain
 * Created Time:  2014-03-07 17:42
 * File Name: Trie-POJ-3630.cpp
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 100005;
const int maxnod = maxn;
const int maxsiz = 26;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

struct Trie{
    int ch[maxnod][maxsiz];
    int val[maxnod];
    int tot;
    void clear (){tot = 1; clr (ch[0], 0); val[0] = 0;}
    int idx(char c){return c - '0';}

    bool insert(char *s, int v){
        int u = 0, n = strlen(s);
        repf (i, 0, n-1){
            int c = idx (s[i]);
            if (!ch[u][c]){
                clr (ch[tot], 0);
                val[tot] = 0;
                ch[u][c] = tot ++;
            }
            u = ch[u][c];
            if (val[u]) return 0;
        }
        val[u] = v;
        repf (i, 0, maxsiz-1) if (ch[u][i]) return 0;
        return 1;
    }
};

Trie trie;
char s[15];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T --){
        trie.clear();
        int n;
        scanf ("%d", &n);
        bool ans = 1;
        repf (i, 0, n-1){
            clr (s, 0);
            scanf ("%s", s);
            if (!ans) continue;
            if (!trie.insert (s, 1)) ans = 0;
        }
        if (!ans) printf ("NO\n");
        else printf ("YES\n");
    }
    return 0;
}
