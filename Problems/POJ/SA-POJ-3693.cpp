/*
 * Author:  Plumrain
 * Created Time:  2014/5/9 1:09:42
 * File Name: SA-POJ-3693.cpp
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
const int maxn =  200005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct RMQ{
    const static int maxn = 200010;
    
    int d[maxn][35];     //the position of the min value

    //an[i], from 1 to n
    void init(int *an, int n){
        repf (i, 1, n) d[i][0] = i;
        for (int j = 1; (1<<j) <= n; ++ j)
            for (int i = 1; i + j - 1 <= n; ++ i){
                int t1 = d[i][j-1], t2 = d[i+(1<<(j-1))][j-1];
                d[i][j] = (an[t1] <= an[t2] ? t1 : t2); 
            }
    }

    //return the pos;
    int calc(int *an, int a, int b){
        if (a > b) swap (a, b);
        int k = 0;
        while ((1<<(k+1)) <= b - a + 1) ++ k;

        int t1 = d[a][k], t2 = d[b-(1<<k)+1][k];
        return an[t1] <= an[t2] ? t1 : t2;
    }
}rmq;

struct SA{
    const static int maxn = 200010;

    int n, m;
    int sa[maxn];       //排第几的是谁, sa[i] = j, i from 1 to n, j from 0 to n-1
    int rank[maxn];     //你排第几, rank[i] = j, i from 0 to n-1, j from 1 to n
    int hei[maxn];      //hei[i] = LCP(suffix(sa[i-1], sa[i])
    int wa[maxn], wb[maxn], wv[maxn], wt[maxn];

    int cmp(int *r, int a, int b, int l){
        return r[a]==r[b] && r[a+l]==r[b+l];
    }

    //r[], from 0 to n-1
    void build_sa(int *r, int n, int m){
        r[n] = 0; this -> n = n ++;

        int i, j, p, *t, *x = wa, *y = wb;
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

            for(t=x,x=y,y=t, p=1, x[sa[0]]=0, i=1; i < n; i++)
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

    int lcp (int a, int b){
        a = rank[a]; b = rank[b];
        if (a > b) swap (a, b);
        return hei[rmq.calc (hei, a+1, b)];
    }
}gao;

RMQ rmq_rank;

int ran[maxn/2];
int an[maxn];
char s[maxn/2];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int cas = 0;
    while (scanf ("%s", s) != EOF && s[0] != '#'){
        int n = strlen(s);
        repf (i, 0, n-1) an[i] = s[i]; an[n] = 'z' + 100;
        for (int i = n+1, j = 2*n; i <= 2*n; ++ i, -- j) an[j] = an[i-n-1];

        gao.build_sa (an, 2*n+1, 300);
        gao.calhei (an);
        rmq.init (gao.hei, 2*n+1);

        repf (i, 1, n) ran[i] = gao.rank[i-1];
        rmq_rank.init (ran, n);

        int ans_num = 1, ans_pos = 0, ans_len = 1;
        repf (len, 1, n) for (int i = 0; i + len < n; i += len){
            int t1 = i, t2 = i + len;
            if (an[t1] != an[t2]) continue;

            int tmp1 = t2==n-1 ? 0 : gao.lcp (t1+1, t2+1);
            int tmp2 = t1 ? gao.lcp(2*n-t1+1, 2*n-t2+1) : 0;
            int tmp = 1 + tmp1 + tmp2;

            int tl = i - tmp2, tr = tl + (tmp % len);
            int sta = rmq_rank.calc (ran, tl + 1, tr + 1) - 1;
            int tmp_num = tmp / len + 1;

            if (tmp_num > ans_num) ans_num = tmp_num, ans_pos = sta, ans_len = len;
            else if (tmp_num == ans_num){
                int t1 = gao.rank[ans_pos], t2 = gao.rank[sta];
                if (t2 < t1) ans_pos = sta, ans_len = len;
            }
        }

        printf ("Case %d: ", ++ cas);
        if (ans_num == 1){
            int min_val = an[0];
            repf (i, 0, n-1) if (min_val > an[i]) min_val = an[i];
            printf ("%c", min_val);
        }
        else repf (i, 0, ans_num*ans_len-1) printf ("%c", an[ans_pos+i]);
        puts ("");
    }
    return 0;
}
