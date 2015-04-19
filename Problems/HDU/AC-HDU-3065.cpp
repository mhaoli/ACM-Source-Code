/*
 * Author:  Plumrain
 * Created Time:  2014-03-18 00:36
 * File Name: AC-HDU-3065.cpp
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
    const static int maxn = 50005;
    const static int maxs = 26;
    const static char st = 'A', en = 'Z';

    int ch[maxn][maxs];
    int last[maxn], f[maxn];
    char ss[3005][55];
    int idx[maxn], cnt[maxn];
    int tot, num;
    
    int id (char c){
        if (c >= st && c <= en) return c - st;
        return -1;
    }
    void clear(){
        tot = 1; clr (ch[0], 0); idx[0] = 0;
    }
    void insert (char *s, int v){
        int n = strlen(s), u = 0;
        repf (i, 0, n-1){
            int c = id(s[i]);
            if (!ch[u][c]){
                clr (ch[tot], 0);
                idx[tot] = 0;
                ch[u][c] = tot++;
            }
            u = ch[u][c];
        }
        idx[u] = v;
    }
    void fail(){
        queue<int> q;
        f[0] = last[0] = 0;
        repf (c, 0, maxs-1){
            int u = ch[0][c];
            if (u){
                f[u] = last[u] = 0; q.push (u);
            }
        }
        while (!q.empty()){
            int r = q.front(); q.pop();
            repf (c, 0, maxs-1){
                int &u = ch[r][c];
                if (!u){
                    u = ch[f[r]][c]; continue;
                }
                q.push (u);

                int v = f[r];
                while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                last[u] = idx[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
    void find (char *s){
        clr (cnt, 0);
        int n = strlen(s), u = 0;
        repf (i, 0, n-1){
            int c = id(s[i]);
            if (c < 0){
                u = 0; continue;
            }
            while (u && !ch[u][c]) u = f[u];
            u = ch[u][c];
            if (idx[u]) add (u);
            else if (last[u]) add (last[u]);
        }
        repf (i, 1, num) if (cnt[i])
            printf ("%s: %d\n", ss[i], cnt[i]);
    }
    void add (int x){
        if (x){
            cnt[idx[x]] ++; 
            add (last[x]);
        }
    }
};

char s[2000005];
AC ac;

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d", &ac.num) != EOF){
        ac.clear();
        repf (i, 1, ac.num) scanf ("%s", ac.ss[i]), ac.insert (ac.ss[i], i);
        ac.fail();
        clr (s, 0);
        gets (s); gets (s);
        ac.find(s);
    }
    return 0;
}
