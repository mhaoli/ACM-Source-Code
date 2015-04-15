/*
 * Author:  Plumrain
 * Created Time:  2014-03-09 11:39
 * File Name: Trie-POJ-2513.cpp
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
    const static int maxn = 500010;
    const static int maxs = 26;
    
    int ch[maxn][maxs];
    int num[maxn], cnt[maxn];
    int f[maxn];
    int tot, ans, flag;
    
    int idx (int c){
        return c - 'a';
    }
    Trie(){
        tot = 1; num[0] = 0; ans = 0; flag = 1;
        clr (ch[0], 0);
    }
    int find (int x){
        if (x != f[x]) f[x] = find (f[x]);
        return f[x];
    }
    int insert (char *s, bool find){
        int n = strlen(s), u = 0;
        repf (i, 0, n-1){
            int c = idx (s[i]);
            if (!ch[u][c]){
                clr (ch[tot], 0);
                num[tot] = 0;
                ch[u][c] = tot ++;
            }
            u = ch[u][c];
        }

        if (find) return num[u];

        if (!num[u]){
            num[u] = flag ++; ++ ans; cnt[u] = 0;
        }
        else if (cnt[u]) -- ans;
        else ++ ans;
        cnt[u] ^= 1;
        return num[u];
    }
    void connect(char *s1, char *s2){
        int t1 = insert (s1, 1), t2 = insert (s2, 1);
        t1 = find (t1); t2 = find (t2);
        if (t1 != t2) f[t1] = t2;
    }
    bool ok(){
        int t = find (1);
        repf (i, 2, flag-1) if (find(i) != t) return 0;
        return 1;
    }
};

Trie trie;
char s1[250010][20], s2[250010][20];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int t = 0;
    while (scanf ("%s%s", s1[t], s2[t]) != EOF)
        trie.insert (s1[t], 0), trie.insert (s2[t], 0), t ++;

    if (trie.ans && trie.ans != 2)
        printf ("Impossible\n");
    else{
        repf (i, 0, trie.flag-1) trie.f[i] = i;
        repf (i, 0, t-1) trie.connect (s1[i], s2[i]);
        if (trie.ok()) printf ("Possible\n");
        else printf ("Impossible\n");
    }
    return 0;
}
