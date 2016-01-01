#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/****head****/
using namespace std;
int _;
const int Max_N = (int)2e5 + 9;
int n;
int an[Max_N];
vector<int> vec;
multiset<int, greater<int> > st;
int bn[10];
bool init() {
        int a, b, c;
        std::cin >> n >> a >> b >> c;

        for(int i = 0; i < n; ++i) {
                scanf("%d", &an[i]);
                st.insert(an[i]);
                if(an[i] > a + b + c) return false;
        }

        bn[0] = a; bn[1] = b; bn[2] = c;
        sort(bn, bn + 3);

        vec.push_back(a + b);
        vec.push_back(a + c);
        vec.push_back(c + b);
        sort(vec.begin(), vec.end());
        return true;
}
multiset<int>::iterator it;
int calc() {
        int ans = 0;
        while(!st.empty()) {
                int c = *st.begin();
                st.erase(st.begin());
                if(c > bn[1] + bn[2]) {
                } else if(c <= bn[2]) {
                        it = st.lower_bound(bn[1]);
                        if(it == st.end()) {
                                it = st.lower_bound(bn[0] + bn[1]);
                                if(it != st.end()) {
                                        st.erase(it);
                                }
                        } else {
                                st.erase(it);
                                it = st.lower_bound(bn[0]);
                                if(it != st.end()) {
                                        st.erase(it);
                                }
                        }
                } else {
                        int tmp = (int)1e9 + 7;
                        for(int i = 0; i < 3; ++i) {
                                if(vec[i] >= c) {
                                        tmp = vec[i]; break;
                                }
                        }
                        it = st.lower_bound(bn[0] + bn[1] + bn[2] - tmp);
                        if(it != st.end()) {
                                st.erase(it);
                        }
                }

                ++ans;
        }
        return ans;
}
int main() {
        int ans;
        if(!init()) ans = -1;
        else ans = calc();
        printf("%d\n", ans);
        return 0;
}
