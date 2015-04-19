/*
 * Author:  Plumrain
 * Created Time:  2014-06-09 00:14
 * File Name: 
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
#define INF 999999999999999999
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
typedef int64 matrix[2][2];

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 100005;
const int mod = 1000000007;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

struct SA{
    int n;
    int sa[maxn];       //ÅÅµÚ¼¸µÄÊÇË­, sa[i] = j, i from 1 to n, j from 0 to n-1
    int rank[maxn];     //ÄãÅÅµÚ¼¸, rank[i] = j, i from 0 to n-1, j from 1 to n
    int h[maxn];        //hei[i] = LCP(suffix(sa[i-1], sa[i]), i from 1 to n
    int wa[maxn], wb[maxn], wv[maxn], wt[maxn];

    int cmp(int *r, int a, int b, int l){
        return r[a]==r[b] && r[a+l]==r[b+l];
    }

    //r[], from 0 to n-1
    void build_sa(int *r, int n, int m)
    {
        r[n] = 0; this -> n = n ++;
        
        int i, j, p, *x=wa, *y=wb, *t;
        repf (i, 0, m-1) wt[i] = 0;
        repf (i, 0, n-1) wt[x[i]=r[i]] ++;
        repf (i, 1, m-1) wt[i] += wt[i-1];
        repd (i, n-1, 0) sa[--wt[x[i]]] = i;
        for(j = 1, p = 1; p < n; j *= 2, m = p)
        {
            for(p = 0, i = n-j; i < n; i++) y[p++] = i;
            repf (i, 0, n-1) if (sa[i] >= j) y[p++] = sa[i] - j;
            repf (i, 0, n-1) wv[i] = x[y[i]];
            repf (i, 0, m-1) wt[i] = 0;
            repf (i, 0, n-1) wt[wv[i]] ++;
            repf (i, 1, m-1) wt[i] += wt[i-1];
            repd (i, n-1, 0) sa[--wt[wv[i]]] = y[i];
            for(t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i < n; i++)
                x[sa[i]] = cmp (y, sa[i-1], sa[i], j) ? p-1 : p++;
        }
        return;
    }

    void calhei(int *r){
        int i, j, k = 0;
        repf (i, 1, n) rank[sa[i]] = i;
        for(i = 0; i < n; h[rank[i++]] = k)
            for(k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
        return;
    }
}gao;

struct Fibonacci{
    const static int mod = 1000000007;

    matrix sta, an;
    int64 cnt;
    int tot;
    void init(){
        cnt = 1; tot = 1;
        sta[0][0] = sta[0][1] = sta[1][0] = 1; sta[1][1] = 0;
        mtx_eql (an, sta);
    }

    void mtx_clear(matrix &a){
        clr (a, 0); repf (i, 0, tot) a[i][i] = 1;
    }
    void mtx_eql(matrix &an, matrix bn){
        repf (i, 0, tot) repf (j, 0, tot) an[i][j] = bn[i][j];
    }
    void mtx_mul (matrix &a, matrix b){
        matrix ret;
        repf (i, 0, tot) repf (j, 0, tot){
            ret[i][j] = 0;
            repf (k, 0, tot) ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
        }
        mtx_eql (a, ret);
    }
    void mtx_pow(matrix &p, int64 n){
        matrix ret; mtx_clear(ret);
        while (n){
            if (n & 1) mtx_mul (ret, p);
            n >>= 1;
            mtx_mul (p, p);
        }
        mtx_eql(p, ret);
    }
    int calc (int64 x){
        if (!x) return sta[1][1];
        if (x < cnt) cnt = 1, mtx_eql (an, sta);
        if (x == cnt) return an[0][1];

        matrix tmp; mtx_eql (tmp, sta);
        mtx_pow (tmp, x - cnt);
        mtx_mul (an, tmp); cnt = x;
        return an[0][1];
    }
}gao2;

int ss[maxn], num[maxn];
char s[maxn];

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("a2.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%s", s) != EOF){
        gao2.init();

        int n = strlen (s);
        repf (i, 0, n-1) ss[i] = s[i];
        gao.build_sa (ss, n, 500);
        gao.calhei (ss);

        int tmp = inf;
        int pos = gao.rank[0];
        repf (i, pos+1, n) chmin (tmp, gao.h[i]), num[gao.sa[i]] = tmp;
        tmp = inf;
        repd (i, pos, 2) chmin (tmp, gao.h[i]), num[gao.sa[i-1]] = tmp;
        num[0] = n;

        int64 cnt = 0;
        int ans = 0;
        repd (i, n-1, 0){
            cnt += num[i];
            ans = (ans + gao2.calc(cnt)) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}
