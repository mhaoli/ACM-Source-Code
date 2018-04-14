// Problem: http://codeforces.com/contest/960/problem/G
// code: http://codeforces.com/contest/960/submission/37248714
namespace ntt{
    const int N=::N;
    const long long mod=::mod,rt=3;
    // (mod-1, rt, mod) && mod < 1e9:
        // (5 << 25, 3, 167772161)
        // (7 << 26, 3, 469762049)
        // (119 << 23, 3, 998244353)
    // (mod-1, rt, mod) && 2^30 > mod > 1e9: 
        // (479 << 21, 3, 1004535809)
        // (483 << 21, 5, 1012924417)
    
    // typedef long long T;  // only support long long, or you should replace all a*b with 1ll*a*b
    
    // long long powmod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}

    ll G[55],iG[55],itwo[55];

    void add(int &a,int b){a+=b;if(a>=mod)a-=mod;}

    void init(){
        int now=(mod-1)/2,len=1,irt=powmod(rt,mod-2,mod);
        while(now%2==0){
            G[len]=powmod(rt,now,mod);
            iG[len]=powmod(irt,now,mod);
            itwo[len]=powmod(1<<len,mod-2,mod);
            now>>=1;len++;
        }
    }
    void dft(ll *x,int n,int fg=1){  // fg=1 for dft, fg=-1 for inverse dft
        for(int i=(n>>1),j=1,k;j<n;++j){
            if(i<j)swap(x[i],x[j]);
            for(k=(n>>1);k&i;i^=k,k>>=1);i^=k;
        }
        ll r,tr,u,v;
        for(int m=2,now=1;m<=n;m<<=1,now++){
            r = fg>0 ? G[now] : iG[now];
            for(int i=0,j;i<n;i+=m){
                tr=1,u,v;
                for(j=i;j<i+(m>>1);++j){
                    u=x[j];v=x[j+(m>>1)]*tr%mod;
                    x[j]=(u+v)%mod;
                    x[j+(m>>1)]=(u+mod-v)%mod;
                    tr=tr*r%mod;
                }
            }
        }
    }
    void brute(ll *a,ll *b,int n,int m){
        static ll c[N];
        for(int k=0,t;k<n+m-1;++k){
            t=0;
            for(int i=max(k-m+1,0);i<n && i<=k;++i){add(t,a[i]*b[k-i]%mod);
                // if(k==2&&i==1)OUT(a[i]),OUT(b[k-i]);
            }
            c[k]=t;
        }
        for(int k=0;k<n+m-1;++k)a[k]=c[k];
    }
    void mul(ll *a,ll *b,int n,int m){   // a: 0,1,2,...,n-1; b: 0,1,2,...,m-1
        if(n+m<=100){
            brute(a,b,n,m);
            return;
        }
        int nn=n+m-1;
        if(n==0||m==0){
            memset(a,0,nn*sizeof(a[0]));
            return;
        }
        int L,len;for(L=1,len=0;L<nn;++len,L<<=1);
        if(n<L)memset(a+n,0,(L-n)*sizeof(a[0]));
        if(m<L)memset(b+m,0,(L-m)*sizeof(b[0]));
        dft(a,L,1);dft(b,L,1);
        for(int i=0;i<L;++i)a[i]=a[i]*b[i]%mod;
        dft(a,L,-1);
        for(int i=0;i<L;++i)a[i]=a[i]*itwo[len]%mod;
    }
}
