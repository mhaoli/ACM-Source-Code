/*
 * Author:  Plumrain
 * Created Time:  2014/5/8 1:07:22
 * File Name: SA-POJ-3261.cpp
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
const int maxn = 20005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct SA{
    const static int maxn = 20005;

    int n, m;
    int sa[maxn];       //排第几的是谁, sa[i] = j, i from 1 to n, j from 0 to n-1
    int rank[maxn];     //你排第几, rank[i] = j, i from 0 to n-1, j from 1 to n
    int hei[maxn];      //hei[i] = LCP(suffix(sa[i-1], sa[i])
    int x[maxn], y[maxn], wv[maxn], wt[maxn];

    int cmp(int *r, int a, int b, int l){
        return r[a]==r[b] && r[a+l]==r[b+l];
    }

    //r[], from 0 to n-1
    void build_sa(int *r, int n, int m){
        r[n] = 0; this -> n = n; ++ n;

        int i, j, p;
        for(i = 0; i < m; i++) wt[i] = 0;
        for(i = 0; i < n; i++) wt[x[i]=r[i]]++;
        for(i = 1; i < m; i++) wt[i] += wt[i-1];
        for(i = n-1; i >= 0; i--) sa[--wt[x[i]]] = i;

        for(j=1, p=1; p < n; j*=2, m=p){
            for(p=0, i=n-j; i<n; i++) y[p++] = i;
            for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;

            for(i = 0; i < n; i++) wv[i] = x[y[i]];
            for(i = 0; i < m; i++) wt[i] = 0;
            for(i = 0; i < n; i++) wt[wv[i]]++;
            for(i = 1; i < m; i++) wt[i] += wt[i-1];
            for(i = n-1; i >= 0; i--) sa[--wt[wv[i]]] = y[i];

            swap (x, y);
            for(p=1, x[sa[0]]=0, i=1; i < n; i++)
                x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
        }
        return;
    }

    void calhei(int *r){
        int i, j, k = 0;
        for(i = 1; i <= n; i++) rank[sa[i]] = i;
        for(i = 0; i < n; hei[rank[i++]] = k)
            for(k?k--:0, j=sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
        return;
    }
}gao;

int an[maxn];

bool calc (int len, int k, int n){
    int num = 0;
    repf (i, 1, n){
        if (gao.hei[i] < len){
            if (num + 1 >= k) return 1;
            num = 0;
        }
        else ++ num;
    }
    return num + 1 >= k;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, k;
    while (scanf ("%d%d", &n, &k) != EOF){
        repf (i, 0, n-1) scanf ("%d", &an[i]);

        int cnt = 1;
        map<int, int> has;
        repf (i, 0, n-1){
            if (!has.count(an[i])) has[an[i]] = cnt ++;
            an[i] = has[an[i]];
        }

        //repf (i, 0, n-1) tst (an[i]);
        //cout << endl;
//
        gao.build_sa (an, n, n+1);
        gao.calhei(an);

        int ans = 0, l = 1, r = n;
        while (l <= r){
            int m = (l + r) >> 1;
            if (calc (m, k, n)) ans = m, l = m + 1;
            else r = m - 1;
        }
        printf ("%d\n", ans);
    }
    return 0;
}
