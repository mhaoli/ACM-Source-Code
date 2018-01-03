// 未验证正确性
// 已验证正确性：
    // is_primitive
    // is_prime
    // init

typedef pair<int,int> pii;
namespace Factor{
    long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
    const int N=1010000;
    int tot,top,size;
    int prm[N],least_prm[N],_phi[N];
    int stk_p[111],stk_k[111];
    void prime_table(){
        int i,j,t1;
        tot=0;
        _phi[1]=1;
		for(i=1;i<=size;i++) least_prm[i]=i;
		for(i=2;i<=size;i++){
			if(least_prm[i]==i) prm[tot++]=i,_phi[i]=i-1;
			for(j=0;j<tot && (t1=prm[j]*i)<=size;j++){
				least_prm[t1]=prm[j];
				if(i%prm[j]==0){
                    _phi[i*prm[j]] = _phi[i]*prm[j]; break;
                }else{
                    _phi[i*prm[j]] = _phi[i]*(prm[j]-1);
                }
			}
		}
    }
    void _factor(int n){
        int i,t;
        for(i=0;i<tot && n>size && prm[i]*prm[i]<=n;++i){
            if(n%prm[i]==0){
                stk_k[top]=1;
                stk_p[top]=prm[i];
                while(n%prm[i]==0){
                    stk_k[top]++;
                    n/=prm[i];
                }
                ++top;
            }
        }
        if(n>size){
            stk_k[top]=1;
            stk_p[top++]=n;
            return;
        }
        while(n>1){
            t=least_prm[n];
            if(!top || stk_p[top-1]!=t){
                stk_k[top]=1;
                stk_p[top++]=t;
            }else ++stk_k[top-1];
            n/=t;
        }
    }
    bool is_prime(int p){
        if(p==1)return 0;
        if(p<=size)return least_prm[p]==p;
        for(int i=0;i<tot && p>size && prm[i]*prm[i]<=p;++i){
            if(p%prm[i]==0)return 0;
        }
        return 1;
    }
    /****************************************************/
    // return prime num
    int init(int n){
        size=n;
        prime_table();
        return tot;
    }
    vector<pii> factorG(int n){
        top=0;
        _factor(n);
        vector<pii> d;
        for(int i=0;i<top;++i)d.pb(pii(stk_p[i],stk_k[i]));
        return d;
    }
    int phi(int x){
        if(x<=size)return _phi[x];
        vector<pii> d=factorG(x);
        for(auto p:d) x=x/p.x*(p.x-1);
        return x;
    }
    bool is_primitive(int a,int p){
        if(a>=p)return 0;
        assert(is_prime(p));
        vector<pii> d=factorG(p-1);
        for(auto i:d) if(pow_mod(a,(p-1)/i.x,p)==1)return 0;
        return 1;
    }
}
