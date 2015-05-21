/*
 * Author:  Plumrain
 * Created Time:  2014/7/30 20:04:47
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
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
//const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int64 inf = 1LL<<60;
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int n;
viii pat[maxn];
bool spe[maxn];
int64 d[maxn];

struct nod{
    int id;
    int64 d;
    bool operator<(const nod &a)const{
        return d > a.d;
    }
};

void dijskra (int s){
    clr (spe, 0);
    repf (i, 1, n-1) d[i] = inf; d[s] = 0;
    priority_queue<nod> q;
    nod tmp; tmp.id = s; tmp.d = 0; q.push (tmp);
    while (sz(q)){
        int id = q.top().id; 
        int64 dis = q.top().d;
        q.pop();
        if (dis > d[id]) continue;
        repf (i, 0, sz(pat[id])-1){
            int v = pat[id][i].x.x, len = pat[id][i].x.y, u = pat[id][i].y;
            if (d[v] > d[id] + len){
                d[v] = d[id] + len; tmp.id = v; tmp.d = d[id] + len; q.push (tmp);
                spe[v] = u;
            }
            if (d[v] == d[id] + len && !u) spe[v] = 0;
        }
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int m, k;
    while (cin >> n >> m >> k){
        repf (i, 0, n-1) pat[i].clear();
        repf (i, 0, m-1){
            int t1, t2, len;
            scanf ("%d%d%d", &t1, &t2, &len); -- t1; -- t2;
            pat[t1].pb (mp (mp(t2, len), 0));
            pat[t2].pb (mp (mp(t1, len), 0));
        }
        repf (i, 0, k-1){
            int t, len;
            scanf ("%d%d", &t, &len);
            pat[--t].pb (mp (mp (0, len), 1));
            pat[0].pb (mp (mp (t, len), 1));
        }

        dijskra (0);
        
        int cnt = 0;
        repf (i, 0, n-1) if (spe[i]) ++ cnt;
        cout << k - cnt << endl;
    }
    return 0;
}
