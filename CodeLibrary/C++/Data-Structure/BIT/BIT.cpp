#define lowbit(x) ((x)&(-x))
int c[100005];

//单点修改，区间查询
//把点x的权值增大d
void add(int x, int d)
{
    while (x <= lim) c[x] += d, x += lowbit(x);
}

//查询1,2,3...x的权值和
int sum(int x)
{
    int ret = 0;
    while (x > 0) ret += c[x], x -= lowbit(x);
    return ret;
}

int c[1005][1005];

//点修改(x, y)
void add(int x, int y)
{
    int yy = y;
    while (x > 0){
        y = yy;
        while (y > 0){
            c[x][y] ^= 1;
            y -= lowbit(y);
        }
        x -= lowbit(x);
    }
}

//区间查询(1, 1) -> (x, y)
int sum(int x, int y)
{
    int ret = 0, yy = y;
    while (x <= n){
        y = yy;
        while (y <= n){
            ret ^= c[x][y];
            y += lowbit(y);
        }
        x += lowbit(x);
    }
    return ret;
}
