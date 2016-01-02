struct BIT{
        //index from 1 to n

#define lowbit(x) ((x)&(-x))
        const static int Max_N = 500005;
        int c[Max_N], n;

        //an[x] += d;
        void add(int x, int d) {
                while(x <= n) c[x] += d, x += lowbit(x);
        }

        //return the sum of an[1], an[2]...an[x]
        int sum(int x) {
                int ret = 0;
                while(x > 0) ret += c[x], x -= lowbit(x);
                return ret;
        }

        int sum(int l, int r) {
                return l > r ? 0 : sum(r) - sum(l-1);
        }
}bit;

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
