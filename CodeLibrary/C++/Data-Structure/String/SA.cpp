/*
 * Author:  Plumrain
 * Last Updated:  2015/12/31
 * Time: O(nlogn)
 */
#define clr(x,y) memset(x, y, sizeof(x))
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)

const int maxn = 20005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

//initial: init()

struct RMQ{
        int mx[Max_N][30], lg2[Max_N];
        void init (int n, int *a){ //a: 0...n-1
                for (int i = 0; i < n; ++ i){
                        mx[i][0] = a[i];
                        lg2[i] = (!i ? -1 : lg2[i>>1] + 1);
                }
                lg2[n] = lg2[n>>1] + 1;
                for (int j = 1, l = 2; l <= n; ++ j, l <<= 1){
                        for (int i = 0; i + l - 1 < n; ++ i)
                                mx[i][j] = std::min(mx[i][j-1], mx[i+(l>>1)][j-1]);
                }
        }
        int query(int a, int b) { //[a, b]
                int k = lg2[b - a + 1];
                return std::min(mx[a][k], mx[b-(1<<k)+1][k]);
        }
};

struct SA{
        //all array form 0 to n-1
        //r[i] != 0 should be guaranteed
        int n;
        int sa[Max_N];       //sa[i] = j: suffix(j)'s rank = i
        int rank[Max_N];     //rank[i] = j: suffix(i)'s rank = j
        int h[Max_N];        //hei[i] = LCP(suffix(sa[i-1], sa[i]))
        int wa[Max_N], wb[Max_N], wv[Max_N], wt[Max_N];

        RMQ rmq;

        int cmp(int *r, int a, int b, int l){
                return r[a]==r[b] && r[a+l]==r[b+l];
        }

        //1 <= r[i] < m, i from 0 to n-1
        void init(int *r, int n, int m)
        {
                r[n] = 0; this -> n = n ++;

                int i, j, p, *x=wa, *y=wb, *t;
                for (i = 0; i < m; ++ i) wt[i] = 0;
                for (i = 0; i < n; ++ i) wt[x[i]=r[i]] ++;
                for (i = 1; i < m; ++ i) wt[i] += wt[i-1];
                for (i = n-1; i >= 0; -- i) sa[--wt[x[i]]] = i;
                for(j = 1, p = 1; p < n; j *= 2, m = p)
                {
                        for (p = 0, i = n-j; i < n; i++) y[p++] = i;
                        for (i = 0; i < n; ++ i) if (sa[i] >= j) y[p++] = sa[i] - j;
                        for (i = 0; i < n; ++ i) wv[i] = x[y[i]];
                        for (i = 0; i < m; ++ i) wt[i] = 0;
                        for (i = 0; i < n; ++ i) wt[wv[i]] ++;
                        for (i = 1; i < m; ++ i) wt[i] += wt[i-1];
                        for (i = n-1; i >= 0; -- i) sa[--wt[wv[i]]] = y[i];
                        for (t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i < n; i++)
                                x[sa[i]] = cmp (y, sa[i-1], sa[i], j) ? p-1 : p++;
                }
                calhei(r);
                return;
        }

        void calhei(int *r){
                int i, j, k = 0;
                for (i = 1; i <= n; ++ i) rank[sa[i]] = i;
                for (i = 0; i < n; h[rank[i++]] = k)
                        for(k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);

                for(int i = 0; i < n; ++i) {
                        sa[i] = sa[i+1];
                        h[i] = h[i+1];
                        rank[i]--;
                }
                rmq.init(n, h);
                return;
        }

        int lcp(int a, int b){
                if(a == b) return n - a;
                a = rank[a]; b = rank[b];
                if(a > b) std::swap(a, b);
                return rmq.query(a+1, b);
        }
}gao;

