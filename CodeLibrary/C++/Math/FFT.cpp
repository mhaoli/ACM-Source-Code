/*
 * Author:  Plumrain
 * Created Time:  2014/9/19 15:46:29
 * Algorithm: FFT
 */
typedef long long ll;
typedef complex<double> CD;
const double PI = atan(1.0)*4;
const int maxn = ;

//use: conv();

namespace FFT{
    const CD I(0, 1);
    CD a[maxn], b[maxn], tmp[maxn];
    void DFT (CD *a, int n, const int &rev){
        if (n == 1) return;
        for (int i = 0; i < n; ++ i){
            tmp[i] = a[i];
        }
        for (int i = 0; i < n; ++ i){
            if (i & 1) a[(n>>1) + (i>>1)] = tmp[i];
            else a[i >> 1] = tmp[i];
        }
        CD *a0 = a, *a1 = a + (n >> 1);
        DFT (a0, n >> 1, rev);
        DFT (a1, n >> 1, rev);
        CD cur(1, 0);
        double alpha = 2 * PI / n * rev;
        CD step = exp (I * alpha);
        for (int k = 0; k < (n>>1); ++ k){
            tmp[k] = a0[k] + cur * a1[k];
            tmp[k + (n>>1)] = a0[k] - cur * a1[k];
            cur *= step;
        }
        for (int i = 0; i < n; ++ i){
            a[i] = tmp[i];
        }
    }
    //c = a * b
    void conv (double *aa, double *bb, double *c, const int &n){
        if (n <= 500){
            for (int i = 0; i < 2*n; ++ i) c[i] = 0;
            for (int i = 0; i < n; ++ i)
                for (int j = 0; j < n; ++ j)
                    c[i+j] += aa[i] * bb[j];
            return ;
        }
        
        int N = 1;
        for (; N < n; N <<= 1); N <<= 1;
        for (int i = 0; i < N; ++ i){
            if (i < n) a[i] = aa[i], b[i] = bb[i];
            else a[i] = b[i] = 0.0;
        }
        DFT (a, N, 1);
        DFT (b, N, 1);
        for (int i = 0; i < N; ++ i){
            a[i] *= b[i];
        }
        DFT (a, N, -1);
        for (int i = 0; i < N; ++ i){
            c[i] = a[i].real() / N;
        }
    }
}
