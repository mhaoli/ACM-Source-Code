/*
 * Author:  Plumrain
 * Created Time:  2014/8/6 13:41:07
 * File Name: H.cpp
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

int n, tot;
int g[20][20];
string opt[1000];
map<string, int> has;
string rhas[1000];

bool ok (int x){
    repf (i, 0, tot-1){
        int t1 = 0, t2 = 0;
        while (t1 < n && t2 < n){
            if (g[opt[i][t1]-'0'][opt[x][t2]-'0']) ++ t2;
            else ++ t1;
        }
        if (t2 == n) return 0;
    }
    return 1;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        scanf ("%d", &n);
        has.clear();
        string s;
        repf (i, 0, n-1) cin >> rhas[i];
        sort (rhas, rhas+n);

        repf (i, 0, n-1) has[rhas[i]] = i;

        clr (g, 0);
        repf (i, 0, n-1){
            int t; scanf ("%d", &t);
            while (t--){
                cin >> s; g[i][has[s]] = 1;
            }
        }

        tot = 0;
        s.clear(); repf (i, 0, n-1) s.pb (i + '0');
        do{
            opt[tot++] = s;
        }while (next_permutation(all (s)));

        int idx = -1;
        bool ans = 0;
        repf (i, 0, tot-1){
            ans |= ok (i);
            if (ans){ idx = i; break;}
        }

        printf ("Case %d: ", ++ cas);
        if (!ans) puts ("No");
        else{
            puts ("Yes");
            repf (i, 0, n-1){
                if (i) printf (" ");
                cout << rhas[opt[idx][i]-'0'];
            }
            puts ("");
        }
    }
    return 0;
}
