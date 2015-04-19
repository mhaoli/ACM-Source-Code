/*
 * Author:  Plumrain
 * Created Time:  2014-03-13 08:08
 * File Name: AC-HDU-2222.cpp
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

struct AC{
    const static int maxn = 500010;
    const static int maxs = 26;
    
    int ch[maxn][maxs];
    int val[maxn], last[maxn], has[maxn], f[maxn];
    int tot;

    void clear(){
        tot = 1; val[maxn] = last[0] = 0;
        clr (ch[0], 0);
    }
    int idx(char c){
        return c - 'a';
    }
    void insert (char *s){
        int n = strlen(s), u = 0;
        repf (i, 0, n-1){
            int c = idx(s[i]);
            if (!ch[u][c]){
                    clr (ch[tot], 0);
                    val[tot] = 0;
                    ch[u][c] = tot ++;
            }
            u = ch[u][c];
        }
        ++ val[u];
    }
    void fail(){
        queue<int> q;
        f[0] = 0;
        repf (i, 0, maxs-1){
            int u = ch[0][i];
            f[u] = last[u] = 0;
            if (u) q.push(u);
        }
        while (!q.empty()){
            int r = q.front(); q.pop();
            repf (c, 0, maxs-1){
                int u = ch[r][c];
                if (!u) continue;
                q.push(u);

                int v = f[r];
                while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
    int find(char *s){
        clr (has, 0);
        int n = strlen(s), j = 0;
        repf (i, 0, n-1){
            int c = idx(s[i]);
            while (j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if (val[j]) print (j);
            else print (last[j]);
        }
        int ret = 0;
        repf (i, 0, tot-1) if (has[i]) ret += val[i];
        return ret;
    }
    void print(int t){
        if (t){
            has[t] = 1;
            print (last[t]);
        }
    }
};

AC an;
char s1[55], s2[1000005];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        an.clear();
        int n;
        scanf ("%d", &n);
        repf (i, 0, n-1){
            scanf ("%s", s1);
            an.insert (s1);
        }
        an.fail();
        scanf ("%s", s2);
        printf ("%d\n", an.find(s2));
    }
    return 0;
}
