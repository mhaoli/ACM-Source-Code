#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
int s[N][N], a[N][N], up[N][N];
deque<pair<int, int> > q;
int get_sum (int x1, int y1, int x2, int y2){
    return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}
int main(){
    int _; scanf ("%d", &_);
    while (_--){
        int n, m, A, B, C, D;
        cin >> n >> m >> A >> B >> C >> D;
        for (int j, i = 1; i <= n; ++ i){
            for (j = 1; j <= m; ++ j){
                if (j == 1) scanf ("%d", &a[i][1]);
                else a[i][j] = (a[i][j-1] * 71 + 17) % 100 + 1;
            }
        }
        for (int i = 1, j; i <= n; ++ i)
            for (j = 1; j <= m; ++ j) s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];

        if (!C || !D){
            int ans = 0;
            for (int j, i = A; i <= n; ++ i){
                for (j = B; j <= m; ++ j) ans = max (ans, get_sum (i - A + 1, j - B + 1, i, j));
            }
            printf ("%d\n", ans);
            continue;
        }

        int sum, l = A - 2 - C + 1, ans = 0;
        for (int i, j = D; j <= m; ++ j){
            q.clear ();
            for (i = C; i <= n; ++ i){
                sum = get_sum (i - C + 1, j - D + 1, i, j);
                while (!q.empty() && q.back().first >= sum) q.pop_back ();
                q.push_back (make_pair (sum, i));
                while (!q.empty() && q.front().second <= i - l) q.pop_front ();
                up[i][j] = q.front().first;
            }
        }
        l = B - 2 - D + 1;
        for (int i = A-1, j; i < n; ++ i){
            q.clear ();
            for (j = D; j < m; ++ j){
                while (!q.empty() && q.back().first >= up[i][j]) q.pop_back ();
                q.push_back (make_pair (up[i][j], j));
                while (!q.empty() && q.front().second <= j - l) q.pop_front ();
                if (i >= A-1 && j >= B-1) ans = max (ans, get_sum (i-A+2, j-B+2, i+1, j+1) - q.front().first);
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}
