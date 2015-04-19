/*
 * Author:  Plumrain
 * Created Time:  2014/9/15 23:55:52
 * Algorithm: Calculate Determinant
 */
long long calc(long long a[15][15], int n){
    long long ans = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = i+1; j < n; ++ j){
            while (a[j][i] != 0){
                long long t = a[i][i] / a[j][i];
                for (int k = 0; k < n; ++ k){
                    a[i][k] -= a[j][k] * t;
                }
                for (int k = 0; k < n; ++ k){
                    swap (a[i][k], a[j][k]);
                }
                ans = -ans;
            }
        }
        ans *= a[i][i];
    }
    return ans;
}
