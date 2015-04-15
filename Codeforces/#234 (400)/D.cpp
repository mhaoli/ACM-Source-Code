/*
 * Author:  Plumrain
 * Created Time:  2014-03-06 00:51
 * File Name: D.cpp
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

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 100005;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

struct pat{
    int s, e, c;
};

pat an[maxn];
int num[505], f[maxn], d[505][505], kind[505];

int find(int x){
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int bin_sch(int key, int n){
    int l = 1, r = n, mid, ret = n;
    while (l <= r){
        mid = (l + r) >> 1;
        if (kind[mid] >= key){
            ret = mid; r = mid - 1;
        }
        else l = mid + 1;
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m, k;
    while (scanf ("%d%d%d", &n, &m, &k) != EOF){
        clr (kind, 0);
        repf (i, 1, k) scanf ("%d", &num[i]), kind[i] = kind[i-1] + num[i];

        //repf (i, 1, k) tst (i), printf ("%d\n", kind[i]);
       // 
        repf (i, 1, m) scanf ("%d%d%d", &an[i].s, &an[i].e, &an[i].c);
        
        repf (i, 1, n) f[i] = i;
        repf (i, 1, m) if (!an[i].c){
            int t1 = find(an[i].s), t2 = find(an[i].e);
            if (t1 != t2) f[t1] = t2;
        }

        bool ans = 1;
        int idx = 1;
        repf (i, 1, k){
            bool u = 1;
            int tf = find(idx);
            repf (j, 0, num[i]-1){
                if (tf != find(idx)){
                    u = 0; break;
                }
                ++ idx;
            }
            if (!u){
                ans = 0; break;
            }
        }
        if (!ans){
            printf ("No\n"); continue;
        }
        else printf ("Yes\n");

        repf (i, 1, k) repf (j, 1, k) d[i][j] = inf;
        repf (i, 1, k) d[i][i] = 0;

        //repf (i, 1, k){
            //repf (j, 1, k) cout << d[i][j] << " ";
            //cout << endl;
        //}
       // 
        repf (i, 1, m){  
            int t1 = bin_sch(an[i].e, k), t2 = bin_sch(an[i].s, k);
            checkmin (d[t1][t2], an[i].c);
            checkmin (d[t2][t1], an[i].c);
        }

        //repf (i, 1, k){
            //repf (j, 1, k) cout << d[i][j] << " ";
            //cout << endl;
        //}
//
        repf (i, 1, k) repf (j, 1, k) repf (t, 1, k){
            checkmin (d[j][t], d[j][i] + d[i][t]);
        }

        //repf (i, 1, k){
            //repf (j, 1, k) cout << d[i][j] << " ";
            //cout << endl;
        //}
//
        repf (i, 1, k){
            repf (j, 1, k){
                if (j > 1) printf (" ");
                printf ("%d", d[i][j] >= inf ? -1 : d[i][j]);
            }
            printf ("\n");
        }
    }
    return 0;
}
