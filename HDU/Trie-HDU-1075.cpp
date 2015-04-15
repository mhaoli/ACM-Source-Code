/*
 * Author:  Plumrain
 * Created Time:  2014-03-08 15:14
 * File Name: Trie-HDU-1075.cpp
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
    const static int maxn = 500000;
    const static int maxs = 26;
    
    int ch[maxn][maxs];
    int num[maxn];
    char ret[maxn][20];
    int tot;

    int idx (char c){
        return c - 'a';
    }
    Trie(){
        tot = 1; clr (ret[0], 0); clr (ch[0], 0); num[0] = 0;
    }
    void insert (char *res, char *s){
        int n = strlen(s), m = strlen(res), u = 0;
        repf (i, 0, n-1){
            int c = idx (s[i]);
            if (!ch[u][c]){
                clr (ch[tot], 0);
                clr (ret[tot], 0);
                num[tot] = 0;
                ch[u][c] = tot ++;
            }
            u = ch[u][c];
        }
        num[u] = 1;
        memcpy (ret[u], res, m);
    }
    bool find(char *s){
        int n = strlen(s), u = 0;
        repf (i, 0, n-1){
            int c = idx (s[i]);
            if (!ch[u][c]) return 0;
            u = ch[u][c];
        }
        if (!num[u]) return 0;
        printf ("%s", ret[u]);
        return 1;
    }
};

Trie trie;
char s1[4000], s2[4000];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    scanf ("%s", s1);
    while (scanf ("%s", s1) && strcmp (s1, "END")){
        scanf ("%s", s2); 
        trie.insert (s1, s2);
    }
    scanf ("%s", s1);
    gets (s1);
    while (gets (s1) && strcmp (s1, "END")){
        clr (s2, 0);
        int n = strlen (s1), idx = 0;
        repf (i, 0, n-1){
            if (s1[i] >= 'a' && s1[i] <= 'z') s2[idx++] = s1[i];
            else{
                s2[idx++] = '\0';
                bool u = trie.find (s2);
                if (!u) printf ("%s", s2);
                printf ("%c", s1[i]);
                idx = 0;
            }
        }
        printf ("\n");
    }
    return 0;
}
