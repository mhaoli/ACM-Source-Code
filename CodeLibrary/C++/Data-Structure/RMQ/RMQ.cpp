/*
 * Author:  Plumrain
 * Created Time:  2014/5/8 13:43:17
 * Time: init-O(nlogn), calc-O(1)
 */
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)

struct RMQ{
        const static int maxn = ;

        int d[maxn][35];     //the position of the min value

        //an[i], from 1 to n
        void init(int *an, int n){
                repf (i, 1, n) d[i][0] = i;
                for (int j = 1; (1<<j) <= n; ++ j)
                        for (int i = 1; i + (1<<j) - 1 <= n; ++ i){
                                int t1 = d[i][j-1], t2 = d[i+(1<<(j-1))][j-1];
                                d[i][j] = (an[t1] <= an[t2] ? t1 : t2); 
                        }
        }

        //return the pos;
        int calc(int *an, int a, int b){
                int k = 0;
                while ((1<<(k+1)) <= b - a + 1) ++ k;

                int t1 = d[a][k], t2 = d[b-(1<<k)+1][k];
                return an[t1] <= an[t2] ? t1 : t2;
        }
};

struct RMQ{
        int gd[Max_N][30], lg2[Max_N];
        void build (int n, int *a){ //a: 0...n-1
                for (int i = 0; i < n; ++ i){
                        gd[i][0] = a[i];
                        lg2[i] = (!i ? -1 : lg2[i>>1] + 1);
                }
                lg2[n] = lg2[n>>1] + 1;
                for (int j = 1, l = 2; l <= n; ++ j, l <<= 1){
                        for (int i = 0; i + l - 1 < n; ++ i)
                                gd[i][j] = std::__gcd(gd[i][j-1], gd[i+(l>>1)][j-1]);
                }
        }
        int query(int a, int b) { //[a, b]
                int k = lg2[b - a + 1];
                return std::__gcd(gd[a][k], gd[b-(1<<k)+1][k]);
        }
}rmq;

