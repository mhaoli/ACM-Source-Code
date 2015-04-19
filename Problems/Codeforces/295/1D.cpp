#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)1e5;
struct Node;
std::vector<Node*> vec[Max_N], all[Max_N], tot;
struct Node {
        long long a, b;
        int id, t, x;
        void read() {
                scanf("%d%d%I64d", &t, &x, &a);
                b = 1;
                all[--x].push_back(this);
                if(t == 2) vec[x].push_back(this);
        }
}b[Max_N];
int a[Max_N];
bool cmp(const Node*a, const Node*b) {
        return a->a > b->a;
}
bool cmp2(const Node*a, const Node*b) {
        return (double)a->a / a->b > (double)b->a / b->b;
        //return a->a * b->b > a->b * b->a;
}
bool cmp3(const Node*a, const Node*b) {
        return a->t == b->t ? a->a > b->a : a->t < b->t;
}
int main() {
        int n, m, K;
        scanf("%d%d%d", &n, &m, &K);
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        for(int i = 0; i < m; ++i) {
                b[i].read(), b[i].id = i;
        }
        long long sum;
        bool flag;
        for(int i = 0; i < n; ++i) {
                std::sort(all[i].begin(), all[i].end(), cmp3);
                flag = 0;
                if(!all[i].empty() && all[i][0]->t == 1 && all[i][0]->a > a[i]) {
                        flag = 1;
                        all[i][0]->a -= a[i];
                        vec[all[i][0]->x].push_back(all[i][0]);
                }
                std::sort(vec[i].begin(), vec[i].end(), cmp);
                sum = a[i];
                snuke(it, vec[i]) {
                        (*it)->b = sum;
                        (*it)->a += sum;
                        sum = (*it)->a;
                }

                snuke(it, all[i]) {
                        if(it != all[i].begin() && (*it)->t == 1) continue;
                        if((*it)->t == 1 && !flag) continue;
                        if((*it)->t == 3) (*it)->b = 1;
                        tot.push_back(*it);
                }
        }
        std::sort(tot.begin(), tot.end(), cmp2);
        std::vector<Node*> ans(tot.begin(), tot.begin() + std::min(K, (int)tot.size()));
        std::sort(ans.begin(), ans.end(), cmp3);
        printf("%d\n", (int)ans.size());
        snuke(it, ans) printf("%d ", (*it)->id + 1);
        return 0;
}
