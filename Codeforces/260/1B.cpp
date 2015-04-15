/*
 * Author:  Plumrain
 * Created Time:  2014/8/9 0:26:31
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
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct Trie{
    const static int maxn = 200000;
    const static int maxs = 26;
    
    int ch[maxn][maxs];      //nod
    int num[maxn];           //state
    int tot;

    int idx(char c){
        return c - 'a';
    }
    Trie(){
        tot = 1; num[0] = 0; clr (ch[0], 0);
    }
    void insert (char *s, int v){
        int n = strlen (s), u = 0;
        repf (i, 0, n-1){
            int c = idx(s[i]);
            if (!ch[u][c]){
                clr (ch[tot], 0);
                num[tot] = 0;
                ch[u][c] = tot ++;
            }
            u = ch[u][c];
        }
        num[u] = v;
    }
    bool dfs (int x, bool flag){
        if (flag){
            repf (i, 0, 25){
                if (!ch[x][i]) continue;
                if (!dfs(ch[x][i], flag)) return 1;
            }
            return 0;
        }
        else{
            bool u = 0;
            repf (i, 0, 25){
                if (!ch[x][i]) continue;
                u = 1;
                if (dfs (ch[x][i], flag)) return 0;
            }
            if (u) return 1;
            return 0;
        }
    }
}gao;

char s[100005];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, k; scanf ("%d%d", &n, &k);
    repf (i, 0, n-1){
        scanf ("%s", s); gao.insert (s, 2);
    }
    bool tmp = gao.dfs (0, 1), ans = tmp;
    if (k % 2 == 0){
        if (!tmp) ans = 0;
        else{
            ans = 1 - gao.dfs (0, 0);
        }
    }
    if (ans) puts ("First");
    else puts ("Second");
    return 0;
}
