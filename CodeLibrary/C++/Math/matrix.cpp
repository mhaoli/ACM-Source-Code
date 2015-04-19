//calculate matrix of size tot*tot

#define clr(x,y) memset(x, y, sizeof(x))
#define rep(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)
typedef int64 matrix[maxn][maxn];
const int tot = ;

void mtx_clear(matrix &a){
    clr (a, 0); rep (i, 0, tot) a[i][i] = 1;
}

void mtx_eql(matrix &an, matrix bn){
    rep (i, 0, tot) rep (j, 0, tot) an[i][j] = bn[i][j];
}

void mtx_mul (matrix &a, matrix b){
    matrix ret;
    rep (i, 0, tot) rep (j, 0, tot){
        ret[i][j] = 0;
        rep (k, 0, tot) ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
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

void mtx_out(matrix a){
    rep (i, 0, tot){
        rep (j, 0, tot) tst (a[i][j]);
        cout << endl;
    }
}
