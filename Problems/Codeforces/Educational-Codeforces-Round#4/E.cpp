#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
/****head****/
int _;
const int Max_N = 1 << 20;
int ans[Max_N], p[Max_N];
int cir[Max_N], cir_tmp[3][Max_N];
bool vis[Max_N];
int find_circle(int x, int*circle) {
        int top = 0, t = x;
        while(1) {
                vis[x] = true;
                circle[top++] = x;
                x = p[x];
                if(x == t) return top;
        }
}
void find_ans(int x, int top, int*circle) {
        for(int i = 0; i < top-1; ++i) {
                ans[circle[i]] = circle[i+1];
        }
        ans[circle[top-1]] = circle[0];
}
void make_circle(int x, int top, int*c1, int*c2) {
        int mid = top >> 1;
        int t = 0;
        for(int i = 0, j = mid + 1; j < top; ++i, ++j) {
                c2[t++] = c1[i];
                c2[t++] = c1[j];
        }
        c2[t++] = c1[mid];
}
void add(int x, int top, int *c1, int*c2, int*c3) {
        if(cir[top] != -1) {
                find_circle(cir[top], c2);

                for(int i = 0; i < top; ++i) {
                        //OUT(c1[i]);
                        //OUT(c2[i]);
                        c3[i<<1] = c1[i];
                        c3[i<<1|1] = c2[i];
                }

                find_ans(x, top<<1, cir_tmp[2]);
                
                cir[top] = -1;
        } else {
                cir[top] = x;
        }
}
int main() {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
                scanf("%d", p + i);
                --p[i];
        }
        memset(cir, -1, sizeof cir);
        for(int i = 0, t; i < n; ++i) if(!vis[i]) {
                t = find_circle(i, cir_tmp[0]);
                if(t & 1) {
                        make_circle(i, t, cir_tmp[0], cir_tmp[1]);
                        find_ans(i, t, cir_tmp[1]);
                } else {
                        add(i, t, cir_tmp[0], cir_tmp[1], cir_tmp[2]);
                }
        }
        for(int i = 1; i <= n; ++i) if(cir[i] != -1) {
                puts("-1"); return 0;
        }
        for(int i = 0; i < n; ++i) {
                printf("%d ", ans[i] + 1);
        }
        return 0;
}
