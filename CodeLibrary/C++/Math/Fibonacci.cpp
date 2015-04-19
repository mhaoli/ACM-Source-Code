/*
 * Author:  Plumrain
 * Created Time:  2014-06-09 00:14
 * File Name: Fibonacci.cpp
 */
#include <cstring>
#define clr(x,y) memset(x, y, sizeof(x))
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
typedef long long int64;
typedef int64 matrix[2][2];
const int maxn = 100005;
const int mod = 1000000007;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

struct Fibonacci{
    const static int mod = ;

    /* an: | f(cnt+1) f(cnt)  |
           | f(cnt)   f(cnt-1)|*/

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
};
