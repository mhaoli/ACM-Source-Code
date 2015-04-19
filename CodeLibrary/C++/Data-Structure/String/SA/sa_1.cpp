/*
 * Author:  Plumrain
 * Created Time:  2014/5/7 2:23:53
 * Time: O(nlogn)
 */
#define clr(x,y) memset(x, y, sizeof(x))
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)

const int maxn = 20005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

//use: build_sa() and calhei()

struct SA{
    const static int maxn = ;

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

    int lcp (int a, int b){
        a = rank[a]; b = rank[b];
        if (a > b) swap (a, b);
        return hei[rmq.calc (hei, a+1, b)];
    }
};
