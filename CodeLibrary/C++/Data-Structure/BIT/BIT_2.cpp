//区间修改，单点查询

const int Maxn = 1000010;
int sum[Maxn], ans[Maxn];
int n, m;

int Lowbit(int x) {
        return x & (-x);
}
void Update(int pos, int val) {
        while (pos > 0) {
            sum[pos] += val;
            pos -= Lowbit(pos);
        }
}
int Query(int pos) {
        int ret = 0;
        while (pos <= n) {
            ret += sum[pos];
            pos += Lowbit(pos);
        }
        return ret;
}

void Add(int l, int r, int val) {
        Update(r, val);
        Update(l - 1, -val);
}



















