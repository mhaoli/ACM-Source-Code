#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define x first
#define y second
#define bind binnnnd
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
using namespace std;
const int Max_N = 9 + (int)1e5;
const long long mod = 9 + (int)1e9;
typedef pair<int, int> pii;
map<pii, int> has;
map<pii, int>::iterator It;
int incnt[Max_N];
vector<int> to[Max_N], in[Max_N];
int dx[] = {-1, 0, 1}, dy[] = {-1, -1, -1};

map<int, int> bind;
map<int, int>::iterator It2;

bool use[Max_N], inq[Max_N];

set<int> snd;
set<int>::iterator si;
set<int, greater<int>> fst;
set<int, greater<int>>::iterator fi;

int stk[Max_N];

void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}

void add(int x) {
        fst.insert(x); snd.insert(x);
}
void remove(int x) {
        si = snd.find(x);
        if(si != snd.end()) snd.erase(si);
        fi = fst.find(x);
        if(fi != fst.end()) fst.erase(fi);
}

int main() {
        int n; scanf("%d", &n);
        pii tmp, tmp2;
        for(int i = 0; i < n; ++i) {
                scanf("%d%d", &tmp.x, &tmp.y);
                has[tmp] = i;
        }
        snuke(it, has) {
                tmp = it->first;
                for(int d = 0; d < 3; ++d) {
                        tmp2.x = tmp.x + dx[d]; tmp2.y = tmp.y + dy[d];
                        It = has.find(tmp2);
                        if(It != has.end()) {
                                to[It->second].push_back(it->second);
                                in[it->second].push_back(It->second);
                        }
                }
        }
        //for(int i = 0; i < n; ++i) {
                //printf("%d :\n", i);
                //snuke(it, in[i]) printf("%d ", *it);
                //puts("in");
                //snuke(it, to[i]) printf("%d ", *it);
                //puts("to");
                //puts("");
        //}

        for(int i = 0; i < n; ++i) {
                incnt[i] = in[i].size();
                if(incnt[i] == 1) {
                                bind[i] = in[i][0];
                                use[in[i][0]] = 1;
                }
        }

        for(int i = 0; i < n; ++i) {
                inq[i] = 1;
                if(!use[i]) add(i);
        }

        int top = 0, flag = 0, rev;
        bool can;
        while(top < n) {
                if(flag == 0) rev = *(fst.begin()), fst.erase(fst.begin()), snd.erase(rev);
                else rev = *(snd.begin()), snd.erase(snd.begin()), fst.erase(rev);

                inq[rev] = 0;
                stk[top++] = rev;

                snuke(it, to[rev]) {
                        if(inq[*it] && --incnt[*it] == 1) {
                                snuke(it2, in[*it]) if(inq[*it2]){
                                        bind[*it] = *it2;
                                        remove(*it2);
                                        break;
                                }
                        }
                }

                It2 = bind.find(rev);
                if(It2 != bind.end()) {
                        can = true;
                        snuke(it, to[It2->second]) {
                                if(inq[*it] && incnt[*it] == 1) can = 0;
                        }
                        if(can) add(It2->second);
                        bind.erase(It2);
                }
                
                flag ^= 1;
        }
        int ans = 0;
        for(long long i = 1; top--; i = i * n % mod) {
                add(ans, i * stk[top] % mod);
        }
        printf("%d\n", ans);
        return 0;
}
