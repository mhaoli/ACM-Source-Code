/*
 * Author:  Plumrain
 * Created Time:  2014/7/27 15:56:02
 * File Name: G.cpp
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
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool pat[20][20], nod[100], v[100], vpat[20][20];
int linx[] = {1, 4, 7, 1, 2, 3, 1, 3}, liny[] = {3, 6, 9, 7, 8, 9, 9, 7};

bool line (int x, int m, int y){
    repf (i, 0, 7){
        if (x == linx[i] && y == liny[i]) return 1;
        if (x == liny[i] && y == linx[i]) return 1;
    }
    return 0;
}

bool ok (string s){
    int pos = s[0] - '0';
    int n = sz(s);
    clr (v, 0); clr (vpat, 0);
    repf (i, 1, n-1){
        v[pos] = 1;
        int x = s[i] - '0';
        if (!pat[pos][x]){
            int mid = (pos + x) >> 1;
            if (line (pos, mid, x) && pat[x][mid] && pat[mid][pos]){
                if (!v[mid]) return 0;
                vpat[mid][pos] = 1; vpat[mid][x] = 1; 
                vpat[pos][mid] = 1; vpat[x][mid] = 1; 
            }
            else return 0;
        }
        vpat[x][pos] = 1; vpat[pos][x] = 1;
        pos = x;
    }

    //if (s == "5879"){
        //repf (i, 1, 9) repf (j, 1, 9) if (pat[i][j] && !vpat[i][j]) tst (i), out (j);
    //}
    repf (i, 1, 9) repf (j, 1, 9) if (pat[i][j] && !vpat[i][j]) return 0;
    return 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T; scanf ("%d", &T);
    while (T--){
        int m; scanf ("%d", &m);
        clr (pat, 0); clr (nod, 0);
        repf (i, 0, m-1){
            int t1, t2; scanf ("%d%d", &t1, &t2);
            pat[t1][t2] = 1; pat[t2][t1] = 1;
            nod[t1] = 1; nod[t2] = 1;
        }

        string s, ans = "IMPOSSIBLE";
        repf (i, 1, 9) if (nod[i]) s.pb (i + '0');
        do{
            if (ok (s)){
                ans = s; break;
            }
        }while (next_permutation(all (s)));

        if (ans != "IMPOSSIBLE"){
            string tmp = ans; ans.clear();
            repf (i, 0, sz(tmp)-1){
                //if (i) ans += " ";
                ans.pb (tmp[i]);
                ans += " ";
            }
        }
        cout << ans << endl;
    }
    return 0;
}
