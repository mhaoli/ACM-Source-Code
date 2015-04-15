/*
 * Author:  Plumrain
 * Created Time:  2014/6/19 18:32:03
 * File Name: 125.cpp
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
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
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
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi pat[15];
pii idx[105];
int tre[20], f[100], num[100], n, an[20][20];
int ans_f[105], ans[20][20];

//topo
int c[105];
int topo[105], pos;

void init(){
    repf (i, 0, n-1) repf (j, 0, n-1) f[i*n+j] = i*n + j;
    repf (j, 0, 9) pat[j].clear();
    clr (num, 0);
}

int find (int x){
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}

bool ok(){
    repf (i, 0, n-1) repf (j, 0, n-1) if (num[i*n+j] != an[i][j]) return 0;
    return 1;
}

bool dfs (int u){
    c[u] = -1;
    repf (i, 0, sz(pat[u])-1){
        int v = pat[u][i];
        if (c[v] < 0) return 0;
        if (!c[v] && !dfs(v)) return 0;
    }
    c[u] = 1; topo[--pos] = u;
    return 1;
}

bool toposort(){
    set<int> st;
    repf (i, 0, n*n-1) st.insert (find (i));

    pos = sz(st); 
    clr (topo, -1); clr (c, 0);
    repf (i, 0, n*n-1) if (st.count(i)) if (!c[i] && !dfs(i)) return 0;
    return 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    tre[0] = 1;
    repf (i, 1, 15) tre[i] = tre[i-1] * 3;
    
    int cnt = 0;
    scanf ("%d", &n);
    repf (i, 0, n-1) repf (j, 0, n-1) scanf ("%d", &an[i][j]);
    repf (i, 0, n-1) repf (j, 0, n-2){
        int t1 = i*n+j, t2 = i*n+j+1;
        idx[cnt++] = mp (t1, t2);
    }
    repf (i, 0, n-2) repf (j, 0, n-1){
        int t1 = i*n+j, t2 = i*n+j+n;
        idx[cnt++] = mp (t1, t2);
    }

    bool find_ans = 0;
    repf (i, 0, tre[cnt]-1){
        init();
        repf (j, 0, cnt-1){
            int tmp = i / tre[j]; tmp %= 3;
            int t1 = idx[j].x, t2 = idx[j].y;
            if (tmp == 0){
                int f1 = find(t1), f2 = find(t2);
                if (f1 != f2) f[f1] = f[f2];
            }
            else if (tmp == 1) pat[t1].pb (t2), num[t1]++;
            else pat[t2].pb (t1), num[t2] ++;
        }

        if (!ok ()) continue;

        repf (j, 0, n-1) repf (k, 0, n-1){
            int tmp = j * n + k;
            repf (t, 0, sz(pat[tmp])-1) pat[tmp][t] = find(pat[tmp][t]);
            if (tmp != find(tmp)){
                repf (t, 0, sz(pat[tmp])-1) pat[find(tmp)].pb (pat[tmp][t]);
                pat[tmp].clear();
            }
        }
        repf (j, 0, n-1) repf (k, 0, n-1){
            int tmp = j * n + k;
            sort (all (pat[tmp]));
            pat[tmp].erase (unique(all (pat[tmp])), pat[tmp].end());
        }

        if (!toposort()) continue;

        repf (j, 0, n*n-1) if (topo[j] != -1) ans_f[topo[j]] = j + 1;
        repf (j, 0, n-1) repf (k, 0, n-1) ans[j][k] = ans_f[find (j*n+k)];
        repf (j, 0, n-1){
            bool u = 0;
            repf (k, 0, n-1){
                if (u) printf (" "); ++ u;
                printf ("%d", ans[j][k]);
            }
            puts ("");
        }
        find_ans = 1; break;
    }
    if (find_ans == 0) puts ("NO SOLUTION");
    return 0;
}
