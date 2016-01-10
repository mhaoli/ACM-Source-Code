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
vector<string> split(char *s) {
        char div[] = ",;";
        vector<string> ret;
        string t;
        for(; s[0]; ++s) {
                if(s[0] == div[0] || s[0] == div[1] || s[0] == div[2]) {
                        ret.pb(t);
                        t.clear();
                } else t.pb(s[0]);
        }
        ret.pb(t);
        return ret;
}
bool digit(const string &it) {
        if(it.empty()) return 0;
        if(SZ(it) != 1 && it[0] == '0') return 0;

        for(char c : it) {
                if(!(c >= '0' && c <= '9')) return 0;
        }
        return 1;
}
void output(string s, bool t) {
        if(!t) puts("-");
        else cout << s << endl;
}
char s[1<<18];
int main() {
        while(scanf("%s", s) != EOF) {
                vector<string> vec = split(s);

                string t[2];
                t[0] = "\"";
                t[1] = "\"";
                bool vis[2] = {0,0};
                for(auto it : vec) {
                        int d = !digit(it);
                        if(vis[d]) t[d].push_back(',');
                        vis[d] = 1;
                        t[d] += it;
                }
                t[0] += "\"";
                t[1] += "\"";
                output(t[0], vis[0]);
                output(t[1], vis[1]);
        }
        return 0;
}
