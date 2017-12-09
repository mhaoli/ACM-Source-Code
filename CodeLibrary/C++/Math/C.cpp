long long C(int n,int m){
    long long rs=1;
    if(m*2>n)m=n-m;
    for(int i=1,j=n;i<=m;++i,--j)rs=(rs*j%mod)*pow_mod(i,mod-2,mod)%mod;
    return rs;
}
