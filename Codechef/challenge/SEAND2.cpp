//score : 0.713
#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n, long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
void add(int &a, int b, int mod) {
        a += b; if(a >= mod) a -= mod;
}
const int Max_Time = 3000;
char str[1111];
bool change;
int _, n, clk, m, tmp, sum1, sum2;
int a[111], dig[1111], sum[111];
long long ten[1111][111];
int ran(int start, int end) {
    return (rand()%(end-start)) + start;
}
void init() {
        int i, j;
        for(i = 0; i < n; ++i) {
                sum[i] = 0;
                for(j = 0; j < m; ++j) {
                        add(sum[i], ten[j][i] * dig[j] % a[i], a[i]);
                }
        }
}
int calc() {
        int ret = 0, i;
        for(i = 0; i < n; ++i) ret += sum[i];
        return ret;
}
void swap(int t1, int t2) {
        if(dig[t1] == dig[t2]) return;
        int i, mod;
        for(i = 0; i < n; ++i) {
                mod = a[i];
                add(sum[i], mod - (ten[t1][i] * dig[t1] % mod), mod);
                add(sum[i], mod - (ten[t2][i] * dig[t2] % mod), mod);
                add(sum[i], ten[t1][i] * dig[t2] % mod, mod);
                add(sum[i], ten[t2][i] * dig[t1] % mod, mod);
        }
        std::swap(dig[t1], dig[t2]);
}
std::vector<int> vec[11], have;
int main() {
        srand (192737);
        //freopen("a.in","r",stdin);
        //freopen("a.out","w",stdout);
        int i, j, t1, t2, cnt;
        Read(_);
        for(; _--; ) {
                scanf("%s", str);
                for(int i = 1; i < 10; ++i) vec[i].clear();
                for(m = 0; str[m]; ++m) {
                        dig[m] = str[m] - '0';
                        vec[dig[m]].push_back(m);
                }
                
                Read(n);
                for(i = 0; i < n; ++i) Read(a[i]);
                for(i = 0; i < m; ++i) 
                        for(j = 0; j < n; ++j) ten[i][j] = !i ? 1 : ten[i-1][j] * 10ll % a[j];
 
                init();
                sum1 = calc();
                for(change = i = clk = 0; clk < Max_Time; ++i, ++clk) {
                        if(!sum1) break;
                        if(i == m-1) {
                                if(!change) break;
                                change = 0; i = 0;
                        }
 
                        j = i+1;
                        while(dig[i] == dig[j]) {
                                if(j >= m-1) j = 0;
                                else ++j;
                                if(j == i) break;
                        }
                        swap(i, j);
                        sum2 = calc();
                        if(sum1 <= sum2) swap(i, j);
                        else change = 1, sum1 = sum2;
                }
 
                have.clear();
                for(i = 1, cnt = 0; i < 10; ++i) if(!vec[i].empty()) have.push_back(i);
 
                if(have.size() > 1) for(; clk < Max_Time; ++clk) {
                        j = i = ran(0, have.size());
                        j = ran(0, have.size());
                        if(i == j) continue;
                        i = have[i]; j = have[j];
                        t1 = ran(0, vec[i].size());
                        t2 = ran(0, vec[j].size());
                        swap(vec[i][t1], vec[j][t2]);
                        sum2 = calc();
                        if(sum1 <= sum2) swap(vec[i][t1], vec[j][t2]);
                        else sum1 = sum2;
                }
 
                for(i = 0; i < m; ++i) str[i] = dig[m-i-1] + '0'; str[m] = 0;
                puts(str);
        }
        return 0;
}
