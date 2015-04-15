/*
 * Author:  Plumrain
 * Created Time:  2014/8/16 15:44:28
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
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
const int maxn = 30005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int n, m;
int a[105][105], ans[maxn], num[maxn], use[maxn];

struct cmp{
    bool operator()(pii a, pii b){
        return a.y < b.y;
    }
};

void calc (int idx, pii &tmp){
    tmp.x = -1;
    int c = -1, cnt = 0;
    if (idx < n){
        rep (j, 0, m-1) if (a[idx][j] != -1){
            if (c == -1) c = a[idx][j], cnt = 1;
            else if (c != a[idx][j]) return;
            else ++ cnt;
        }
        if (c == -1 || cnt != num[c]) return;
        tmp.x = idx; tmp.y = c;
    }
    else{
        rep (i, 0, n-1) if (a[i][idx - n] != -1){
            if (c == -1) c = a[i][idx - n], cnt = 1;
            else if (c != a[i][idx - n]) return;
            else ++ cnt;
        }
        if (c == -1 || cnt != num[c]) return;
        tmp.x = idx; tmp.y = c;
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    while (scanf ("%d%d", &n, &m) != EOF){
        if (n + m == 0) break;
        clr (num, 0);
        rep (i, 0, n-1) rep (j, 0, m-1) scanf ("%d", &a[i][j]), ++ num[a[i][j]];

        pii tmp;
        clr (use, 0);
        priority_queue<pii, vii, cmp> q;
        rep (i, 0, n-1){
            //bool u = 1;
            //rep (j, 1, m-1) if (a[i][j] != a[i][j-1]) u = 0;
            //if (u) tmp.x = i, tmp.y = a[i][0], q.push (tmp);
            calc (i, tmp);
            if (tmp.x != -1 && !use[tmp.y]) q.push (tmp), use[tmp.y] = 1;
        }
        rep (i, 0, m-1){
            //bool u = 1;
            //rep (j, 1, n-1) if (a[j-1][i] != a[j][i]) u = 0;
            //if (u) tmp.x = i + n, tmp.y = a[0][i], q.push (tmp);
            calc (i + n, tmp);
            if (tmp.x != -1 && !use[tmp.y]) q.push (tmp), use[tmp.y] = 1;
        }

        int top = 0, idx, c;
        while (sz (q)){
            idx = q.top().x;
            ans[top++] = c = q.top().y;
            q.pop ();
            if (idx < n){
                rep (j, 0, m-1) a[idx][j] = -1;
                rep (j, 0, m-1){
                    calc (j + n, tmp); 
                    if (tmp.x != -1 && !use[tmp.y]) q.push (tmp), use[tmp.y] = 1;
                }
            }
            else{
                rep (i, 0, n-1) a[i][idx - n] = -1;
                rep (i, 0, n-1){
                    calc (i, tmp);
                    if (tmp.x != -1 && !use[tmp.y]) q.push (tmp), use[tmp.y] = 1;
                }
            }
        }

        int flag = 0;
        while (top --){
            if (flag) printf (" "); ++ flag;
            printf ("%d", ans[top]);
        }
        puts ("");
    }
    return 0;
}
