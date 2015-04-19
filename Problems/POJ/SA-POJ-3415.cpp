/*
 * Author:  Plumrain
 * Created Time:  2014/5/9 16:25:10
 * File Name: SA-POJ-3415.cpp
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
typedef pair<int64, int64> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 200005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct SA{
    const static int maxn = 200010;

    int n;
    int sa[maxn];       //排第几的是谁, sa[i] = j, i from 1 to n, j from 0 to n-1
    int rank[maxn];     //你排第几, rank[i] = j, i from 0 to n-1, j from 1 to n
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

int an[maxn];
pii stk[maxn];
char s1[maxn], s2[maxn];

int64 calc (int ut, int k, int n, int n1){
    int64 stk_num = 0, sum = 0, ret = 0;
    repf (i, 1, n-1){
        int t = gao.sa[i] < n1;
        int64 num = (t == ut);
        if (t != ut) ret += sum;
        
        while (stk_num && stk[stk_num-1].x >= gao.h[i+1]){
            num += stk[--stk_num].y;
            sum -= 1LL * stk[stk_num].y * (stk[stk_num].x - k + 1);
        }
        if (num) stk[stk_num++] = mp (gao.h[i+1], num);
        sum += 1LL * num * (gao.h[i+1] - k + 1);

        if (gao.h[i+1] < k) stk_num = sum = 0;
    }
    return ret;
}

int main(){
    int k;
    while (scanf ("%d", &k) != EOF && k){
        scanf ("%s%s", s1, s2);
        int n1 = strlen (s1), n2 = strlen (s2), n = n1 + n2 + 1;
        repf (i, 0, n1-1) an[i] = s1[i]; an[n1] = 290;
        repf (i, n1+1, n-1) an[i] = s2[i - n1 - 1];

        gao.build_sa (an, n, 300);
        gao.calhei (an);

        cout << calc (0, k, n, n1) + calc (1, k, n, n1) << endl;
    }
    return 0;
}
