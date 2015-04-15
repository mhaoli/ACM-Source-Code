#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 9 + (int)1e6;
char s[Max_N];
int n;
bool check(int R) {
        int pos = 0, mx = 0, mi = 0;
        for(int i = 0; i < n-1; ++i) {
                pos += s[i]=='L' ? -1 : 1;
                if(pos == R) --pos;
                if(pos < mi) mi = pos;
                if(pos > mx) mx = pos;
        }
        return pos == mi;
}
int calc() {
        if(s[n-1] != 'L') return 0;
        int l = 1, r = n, res = 0;
        for(int m; l <= r; ) {
                m = (l + r) >> 1;
                if(check(m)) res = m, l = m + 1;
                else r = m - 1;
        }
        return res;
}
int main() {
        scanf("%s", s);
        n = strlen(s);
        int pos = 0, mx = 0, mi = 0;
        for(int i = 0; i < n-1; ++i) {
                pos += s[i]=='L' ? -1 : 1;
                if(pos < mi) mi = pos;
                if(pos > mx) mx = pos;
        }
        if(s[n-1] == 'L') {
                if(pos == mi) return puts("1"), 0;
        } else if(pos == mx) return puts("1"), 0;

        int ans = calc();
        for(int i = 0; i < n; ++i)
                s[i] = s[i]=='L' ? 'R' : 'L';
        ans += calc();
        printf("%d\n", ans);
        return 0;
}
