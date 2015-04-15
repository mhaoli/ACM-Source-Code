/*
 * Author:  Plumrain
 * Created Time:  2014-03-07 20:10
 * File Name: Trie-HDU-1251.cpp
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

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

struct Trie{
    const static int maxnod = 500000;
    const static int maxsiz = 26;

    int ch[maxnod][maxsiz];
    int num[maxnod];
    int tot;
    Trie(){ tot = 1; clr (ch[0], 0); num[0] = 0;}
    int idx (char c){ return c - 'a';}
     
    void insert (char *s){
        int u = 0, n = strlen(s);
        num[u] ++;
        repf (i, 0, n-1){
            int c = idx(s[i]);
            if (!ch[u][c]){
                clr (ch[tot], 0);
                num[tot] = 0;
                ch[u][c] = tot ++;
            }
            u = ch[u][c];
            num[u] ++;
        }
    }

    int find(char *s){
        int u = 0, n = strlen(s);
        repf (i, 0, n-1){
            int c = idx(s[i]);
            if (!ch[u][c]) return 0;
            u = ch[u][c];
        }
        return num[u];
    }
};

char s[20];
Trie trie;

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (1){
        clr (s, 0);
        gets(s);
        if (!strlen(s)) break;
        trie.insert (s);
    }

    while (scanf ("%s", s) != EOF)
        printf ("%d\n", trie.find(s));
    return 0;
}
