#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

//#define out(x) cout<<#x<<":"<<(x)<<endl
//#define tst(a) cout<<#a<<endl
const int mod = 1000000007;
typedef long long int64;

struct nod{
    int64 sum, sqr, num;
    void clr(){
        sum = 0; sqr = 0; num = 0;
    }
};

nod zero, one;
int64 dit[20];
int64 ten[20];
nod d[20][10][10];

nod rec(int len, int sum, int yu, bool U)
{
    if (len < 0){
        if (sum && yu) return zero;
        else return one;
    }

    if (!U && d[len][sum][yu].num != -1) return d[len][sum][yu];
    nod ret; ret.clr();
    int up = U ? dit[len] : 9;
    for (int i = 0; i <= up; ++ i) if (i != 7){
        int64 tflag = i*ten[len] % mod;
        nod tmp = rec(len-1, (sum + i)%7, (yu*10 + i)%7, U&&i==up);
        if (tmp.num == -1) continue;

        ret.sum = (ret.sum + tmp.num*tflag + tmp.sum) % mod;
        ret.sqr = (ret.sqr + tmp.num * (tflag*tflag % mod) % mod + 2*tflag*tmp.sum%mod + tmp.sqr) % mod;
        ret.num = (ret.num + tmp.num) % mod;
    }
    if (!U) d[len][sum][yu] = ret;
    return ret;
}

int64 gao(int64 x)
{
    int len = 0;
    while (x){
        dit[len++] = x % 10;
        x /= 10;
    }
    return rec(len-1, 0, 0, 1).sqr;
}

void init()
{
    one.clr(); one.num = -1;
    zero.clr(); zero.num = 1;

    for (int i = 0; i < 20; ++ i)
        for (int j = 0; j < 10; ++ j)
            for (int k = 0; k < 10; ++ k)
                d[i][j][k] = one;

    ten[0] = 1;
    for (int i = 1; i < 19; ++ i)
        ten[i] = ten[i-1] * 10 % mod;
}

int main()
{
    init();
    int T;
    scanf ("%d", &T);
    while (T--){
        int64 a, b;
        cin >> a >> b;
        cout << ((gao(b) - gao(a-1))%mod + mod) % mod << endl;
    }
    return 0;
}
