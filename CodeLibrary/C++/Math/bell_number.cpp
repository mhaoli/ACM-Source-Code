namespace bell{
    int dp[1005][1005];
    void calc(int n,int *bell){
        dp[1][1]=1;
        bell[1]=1;
        rep(i,2,n+1){
            bell[i]=dp[i][1]=dp[i-1][1];
            rep(j,2,i+1){
                dp[i][j]=(dp[i-1][j-1]+(1ll*dp[i-1][j]*j%mod))%mod;
                bell[i]=(bell[i]+dp[i][j])%mod;
            }
        }
        // rep(i,1,8)TST(i),OUT(bell[i]);
    }
}

