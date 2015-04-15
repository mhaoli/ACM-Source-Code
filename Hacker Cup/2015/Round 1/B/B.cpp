#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)1e6;
char str[Max_N];
struct Node {
        Node*ch[26];
}mem[Max_N], *bat, *rt;
Node* newNode() {
        memset(bat->ch, 0, sizeof bat->ch);
        return bat++;
}
void init() {
        bat = mem; rt = newNode();
}
int insert(char*s) {
        int ret = 0, change = 1;
        for(Node*x = rt; s[0]; ++s) {
                ret += change;
                if(!x->ch[s[0]-'a']) {
                        change = 0;
                        x->ch[s[0]-'a'] = newNode();
                }
                x = x->ch[s[0]-'a'];
        }
        return ret;
}
int main() {
        freopen("autocomplete.txt","r",stdin);
        freopen("my.out","w",stdout);
        int _; scanf("%d", &_);
        for(int n, ans, cas = 0; _--; ) {
                scanf("%d", &n);
                ans = 0; init();
                for(; n--; ) {
                        scanf("%s", str);
                        ans += insert(str);
                }
                printf("Case #%d: %d\n", ++cas, ans);
        }
        return 0;
}
