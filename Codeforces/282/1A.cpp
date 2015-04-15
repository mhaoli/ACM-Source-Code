#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 9 + (int)1e5;
char s[Max_N];
int ans[Max_N];
int main() {
        scanf("%s", s);
        int n = strlen(s), t1 = 0, t2 = 0, last = n;
        for(int i = n-1; i >= 0; --i) if(s[i] == '#') {
                last = i; break;
        }
        for(int i = 0; i < n; ++i) {
                if(s[i] == '(') ++t1;
                else ++t2;
        }
        if(t1 < t2) return puts("-1"), 0;
        int cnt = 0, tot = 0;
        for(int i = 0; i < n; ++i) {
                if(s[i] == '(') ++cnt;
                else if(i == last) {
                        cnt -= 1 + t1 - t2;
                        ans[tot++] = 1 + t1 - t2;
                } else {
                        --cnt;
                        if(s[i] == '#') ans[tot++] = 1;
                }
                if(cnt < 0) return puts("-1"), 0;
        }
        for(int i = 0; i < tot; ++i)
                printf("%d\n", ans[i]);
        return 0;
}
