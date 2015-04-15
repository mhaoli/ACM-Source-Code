#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
void Read(int &ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)1e6;
char str[Max_N], temp[] = "chef";
int cnt[16][Max_N], first[16][Max_N], map[2222], *head[4], *end[4], *pos[4], num[4], stk[Max_N], nxt[4][Max_N], tmp_num[4];
long long sum[16][Max_N];
int main() {
        for(int i = 0; i < 4; ++i) map[temp[i]] = i;

        scanf("%s", str);
        int n = strlen(str), nq;
        memset(head, -1, sizeof head);
        for(int i = 0; i < n; ++i) ++num[map[str[i]]];
        pos[0] = head[0] = stk; end[0] = stk + num[0];
        for(int i = 1; i < 4; ++i) {
                end[i] = (pos[i] = head[i] = end[i-1]) + num[i];
        }
        for(int i = 0; i < n; ++i) {
                *pos[map[str[i]]] = i;
                pos[map[str[i]]]++;
        }
        for(int i = 0; i < 4; ++i) nxt[i][n] = tmp_num[i] = num[i];
        for(int i = n-1, j; i >= 0; --i) {
                --tmp_num[map[str[i]]];
                for(j = 0; j < 4; ++j) nxt[j][i] = tmp_num[j];
        }

        memset(tmp_num, 0, sizeof tmp_num);
        for(int i = 0, j; i < n; ++i) {
                for(j = 0; j < 4; ++j) {
                        first[j*4+map[str[i]]][tmp_num[map[str[i]]]] = tmp_num[j] - 1;
                }
                ++tmp_num[map[str[i]]];
        }

        long long *sp;
        for(int i = 0, j, k, *p1, *p2, *cp, count, idx; i < 4; ++i) {
                for(j = 0; j < 4; ++j) if(j != i) {
                        count = num[j];
                        idx = i * 4 + j;
                        sp = &sum[idx][0];
                        cp = &cnt[idx][0];
                        for(p1 = head[i], p2 = head[j]; p1 != end[i]; ++p1) {
                                while(p2 != end[j] && *p2 < *p1) {
                                        ++p2; --count;
                                }
                                if(sp == sum[idx]) *sp = *cp = count;
                                else *sp = *(sp-1) + (*cp = count);
                                ++sp; ++cp;
                        }
                }
        }

        Read(nq);
        char cc[22];
        for(int t1, t2, l, r, idx, ansl, ans_cnt, ansr; nq--; ) {
                scanf("%s", cc); t1 = map[cc[0]];
                scanf("%s", cc); t2 = map[cc[0]];
                idx = t1 * 4 + t2;
                Read(l); Read(r); --l; --r;
                ansl = nxt[t1][l];
                ans_cnt = num[t2] - nxt[t2][r+1];
                if(nxt[t2][r+1] == 0) ansr = -1;
                else ansr = first[idx][nxt[t2][r+1]-1];
                if(ansl > ansr) puts("0");
                else printf("%lld\n", sum[idx][ansr] - sum[idx][ansl] + cnt[idx][ansl] - (long long)ans_cnt * (ansr - ansl + 1));
        }
        return 0;
}
