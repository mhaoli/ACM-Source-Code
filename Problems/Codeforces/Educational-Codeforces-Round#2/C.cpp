#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<class T> void RD(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
using namespace std;
/****head****/
int _;
char s[1<<18];
int c[100];
int main() {
        scanf("%s", s);
        int n = strlen(s), cnt = 0;
        for(int i = 0; i < n; ++i) {
                c[s[i]-'a']++;
        }
        for(int i = 0; i < 26; ++i) if(c[i] & 1) ++cnt;

        char tmp = 0;
        bool flag = 0;
        if(cnt & 1) flag = 1;
        cnt >>= 1;
        string ans;
        for(int i = 0; i < 26; ++i) {
                if(c[i] & 1) {
                        if(cnt > 0) {
                                --cnt; ++c[i];
                        } else {
                                --c[i];
                                if(!tmp) tmp = i + 'a';
                        }
                }
                c[i] >>= 1;
                while(c[i]--) ans.push_back(i + 'a');
        }
        string ans2 = ans; 
        reverse(ALL(ans2));
        if(flag) {
                ans.pb(tmp);
        }
        ans += ans2;
        cout << ans << endl;

        return 0;
}
