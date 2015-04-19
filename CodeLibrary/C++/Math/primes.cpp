//Eratosthenes法筛素数
//时间复杂度O(nloglogn),空间复杂度O(n)
//vis[i] = 0,则i为素数,vis[0] = vis[1] = 1

//头文件
#define clr(x,y) memset(x, y, sizeof(x))
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)

//1.LiuRuJia的版本
const int N = ;
bool vis[N+1];

void sieve(int n)
{
    int m = (int)sqrt(n+0.5);
    clr (vis, 0); vis[0] = vis[1] = 1;
    for (int i = 2; i <= m; ++ i) if (!vis[i])
        for (int j = i*i; j <= n; j += i) vis[j] = 1;
}

//2.贾志鹏论文版,筛素数+打表
const int maxn = ;
bool check[maxn+5];

int primes (int n){
    clr (check, 0);
    int tot = 0;
    repf (i, 2, n) if (!check[i]){
        prm[tot++] = i;
        for (int j = i*2; j <= n; j += i) check[j] = 1;
    }
}


//Euler筛法
//时间复杂度空间复杂度均为O(n)
const int maxn = ;
bool check[maxn+5];
int prm[maxn+5];

int primes(int n){
    //memset(check, 0, sizeof check);
    int tot = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[tot++] = i;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
    return tot;
}
