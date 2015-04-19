/*
 * Author:  Plumrain
 * Created Time:  2014-03-08 16:24
 * File Name: Trie-POJ-2503.cpp
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
    const static int maxn = 2000000;
    const static int maxs = 26;

    int ch[maxn][maxs];
    int num[maxn];
    char ret[maxn][20];
    int tot;

    int idx (char c){
        return c - 'a';
    }
    Trie(){
        tot = 1; clr (ch[0], 0); num[0] = 0;
    }
    void insert (char *s1, char *s2){
        int n = strlen (s2), u = 0, m = strlen(s1);
        repf (i, 0, n-1){
            int c = idx (s2[i]);
            if (!ch[u][c]){
                clr (ch[tot], 0);
                num[tot] = 0;
                ch[u][c] = tot ++;
            }
            u = ch[u][c];
        }
        num[u] = 1;
        memcpy (ret[u], s1, m);
    }
    bool find(char *s){
        int n = strlen(s), u = 0;
        repf (i, 0, n-1){
            int c = idx (s[i]);
            if (!ch[u][c]) return 0;
            u = ch[u][c];
        }
        if (!num[u]) return 0;
        printf ("%s\n", ret[u]);
        return 1;
    }
};

Trie trie;
char s1[100], s2[100], s[100];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (1){
        gets (s);
        int n = strlen(s);
        if (!n) break;
        repf (i, 0, n-1) if (s[i] == ' '){
            memcpy (s1, s, i);
            memcpy (s2, s+i+1, n-i-1);
            break;
        }
        trie.insert (s1, s2);
    }

    while (scanf ("%s", s1) != EOF){
        bool u = trie.find (s1);
        if (!u) printf ("eh\n");
    }
    return 0;
}
