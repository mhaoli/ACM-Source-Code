#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const static int Max_N = 9 + (int)2e6;
struct SA{
    const static int maxn = 9 + (int)2e6;

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
        return;
    }
    void calhei(int *r){
        int i, j, k = 0;
        for (i = 1; i <= n; ++ i) rank[sa[i]] = i;
        for (i = 0; i < n; h[rank[i++]] = k)
            for(k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
        return;
    }
    //int lcp (int a, int b){
        //if (a == b) return n - a;
        //a = rank[a]; b = rank[b];
        //if (a > b) swap (a, b);
        //return h[rmq.calc (hei, a+1, b)];
    //}
}sa;
char Str[Max_N];
int str[Max_N];
int main() {
        int n, m;
        while(scanf("%d%d", &n, &m) != EOF) {
                scanf("%s", Str);
                for(int i = 0; i < n; ++i) str[i+n] = str[i] = Str[i] - '0';
                sa.build_sa(str, n<<1, 10);
                sa.calhei(str);
                //for(int i = 1; i <= (n<<1); ++i) printf("%d %d %d   %d\n", i, sa.sa[i], sa.h[i], sa.rank[i]);
                int cnt = 0, ans, tpos = 1, ti;
                for(int i = 1; i <= (n<<1) && cnt < m; ++i, ++tpos) {
                        if(sa.sa[i] < n) ++cnt;
                }

                --tpos;
                ti = tpos;
                ans = sa.sa[tpos];
                while(ti > 1 && sa.h[ti] >= n-1) {
                        ans = std::min(ans, sa.sa[ti]);
                        --ti;
                }
                ti = tpos + 1;
                while(ti <= (n<<1) && sa.h[ti] >= n-1) { 
                        ans = std::min(ans, sa.sa[ti]);
                        ++ti;
                }
                if(ans == 0) ans = n;
                printf("%d\n", ans);
        }
        return 0;
}
