template<int sz> struct combo{
    const ll mod = ::mod;
    ll *fac, *ifac;
    ll mem_fac[sz+5],mem_ifac[sz+5];

    // long long powmod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}

    combo(ll *fa=0,ll *ifa=0){
        fac=fa?fa:mem_fac;
        ifac=ifa?ifa:mem_ifac;
        fac[0]=ifac[0]=1;
        for(int i=1;i<=sz;++i){
            fac[i]=i*fac[i-1]%mod;
            ifac[i]=powmod(fac[i],mod-2,mod);
        }
    }
    ll comb(ll n,ll m){  // n >= m
        if(n<m)return 0;
        return (fac[n]*ifac[m]%mod)*ifac[n-m]%mod;
    }
};

ll fac[N],fnv[N];
combo<100005> C(fac,fnv);
// cout<<C.comb(5,3)<<endl;


// old
long long C(int n,int m){
    long long rs=1;
    if(m*2>n)m=n-m;
    for(int i=1,j=n;i<=m;++i,--j)rs=(rs*j%mod)*pow_mod(i,mod-2,mod)%mod;
    return rs;
}
