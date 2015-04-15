#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)1e5;
typedef std::pair<int, int> pii;
std::vector<pii > E[Max_N];
std::set<int> col[Max_N];
std::map<pii, int> que;
std::map<pii, int> ans_pos;
pii q[Max_N];
int ans[Max_N], f[Max_N], last[Max_N];
int find(int x) {
        return x == f[x] ? f[x] : f[x] = find(f[x]);
}
int stk[Max_N], stk_top;
std::vector<int> son[Max_N];
std::map<pii, int>::iterator pos;
void brute(int c) {
        std::vector<int> vec(col[c].begin(), col[c].end());
        snuke(it, vec) f[*it] = *it;
        int t1, t2;
        snuke(it, E[c]) {
                t1 = find(it->first); t2 = find(it->second);
                if(t1 != t2) f[t1] = t2;
        }
        stk_top = 0;
        snuke(it, vec) {
                son[find(*it)].clear();
                if(f[*it] == *it) stk[stk_top++] = *it;
        }
        snuke(it, vec) son[f[*it]].push_back(*it);
        int mi, mx;
        for(int it = 0; it < stk_top; ++it) {
                snuke(i, son[stk[it]])
                        for(std::vector<int>::iterator j = i+1; j != son[stk[it]].end(); ++j) {
                                mi = std::min(*i, *j);
                                mx = std::max(*i, *j);
                                pos = que.find(std::make_pair(mi, mx));
                                //if(!c) printf("%d %d\n", mi, mx), out(pos == que.end()), out(last[pos->second]), out(pos->second);
                                if(pos != que.end()) {
                                        if(last[pos->second] != c) ++ans[pos->second], last[pos->second] = c;
                                }
                        }
        }
}
void Snuke(int c) {
        std::vector<int> vec(col[c].begin(), col[c].end());
        memset(f, -1, sizeof f);
        snuke(it, vec) f[*it] = *it;
        int t1, t2;
        snuke(it, E[c]) {
                t1 = find(it->first); t2 = find(it->second);
                if(t1 != t2) f[t1] = t2;
        }
        snuke(it, que) if(f[it->first.first] != -1 && f[it->first.second] != -1){
                if(find(it->first.first) == find(it->first.second)) ++ans[it->second];
        }
}
int main() {
        int n, m; Read(n); Read(m);
        for(int i = 0, s, e, c; i < m; ++i) {
                Read(s); Read(e); Read(c); --e; --s; --c;
                col[c].insert(s); col[c].insert(e);
                E[c].push_back(std::make_pair(s, e));
        }
        int nq; Read(nq);
        pii tmp;
        for(int i = 0, u, v; i < nq; ++i) {
                Read(u); Read(v); --v; --u;
                if(u > v) std::swap(u, v);
                tmp = std::make_pair(u, v);
                q[i] = tmp;
                que[tmp] = i;
                ans_pos[tmp] = i;
        }
        int block = 2000;
        memset(last, -1, sizeof last);
        for(int i = 0; i < Max_N - 5; ++i) if(!col[i].empty()){
                if((int)col[i].size() < block) {
                        brute(i);
                } else {
                        Snuke(i);
                }
        }
        for(int i = 0; i < nq; ++i) printf("%d\n", ans[ans_pos[q[i]]]);
        return 0;
}
