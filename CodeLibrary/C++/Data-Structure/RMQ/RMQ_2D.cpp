struct RMQ_2D{
        static const int Max_N = 1000;
        static const int Max_M = 1000;
        int mx[Max_N+3][Max_M+3][11][11], lg[1005];
        void build(int n, int m, int a[1001][1001]){
                for(int i = 0, t = max(n, m); i <= t; ++i) {
                        lg[i] = (!i ? -1 : lg[i>>1] + 1);
                }
                for(int k = 0; (1<<k) <= n; ++k) {
                        for(int l = 0; (1<<l) <= m; ++l) {
                                for(int i = 0; i + (1<<k) - 1 < n; ++i) {
                                        for(int j = 0; j + (1<<l) - 1 < m; ++j) {
                                                if(!k && !l) mx[i][j][0][0] = a[i][j];
                                                else if(!k) {
                                                        mx[i][j][0][l] = max(mx[i][j][0][l-1], mx[i][j+(1<<(l-1))][0][l-1]);
                                                } else if(!l) {
                                                        mx[i][j][k][0] = max(mx[i][j][k-1][0], mx[i+(1<<(k-1))][j][k-1][0]);
                                                } else {
                                                        mx[i][j][k][l] = max(mx[i][j][k-1][l-1], mx[i+(1<<(k-1))][j][k-1][l-1]);
                                                        chmax(mx[i][j][k][l], mx[i][j+(1<<(l-1))][k-1][l-1]);
                                                        chmax(mx[i][j][k][l], mx[i+(1<<(k-1))][j+(1<<(l-1))][k-1][l-1]);
                                                }
                                        }
                                }
                        }
                }
        }
        int query(int x1, int y1, int x2, int y2) { //[x1, x2], [y1, y2]
                int k = lg[x2 - x1 + 1], l = lg[y2 - y1 + 1], ans = mx[x1][y1][k][l];
                chmax(ans, mx[x2-(1<<k)+1][y1][k][l]);
                chmax(ans, mx[x1][y2-(1<<l)+1][k][l]);
                chmax(ans, mx[x2-(1<<k)+1][y2-(1<<l)+1][k][l]);
                return ans;
        }
}rmq;
