#include<bits/stdc++.h>
int cmp(std::vector<int> &a, std::vector<int> &b) {
        int n = a.size(), m = b.size(), up = std::min(n, m);
        for(int i = 0; i < up; ++i) 
                if(a[i] > b[i]) return 1;
                else if(a[i] < b[i]) return -1;
        if(n == m) return 0;
        if(n > m) return 1;
        return -1;
}
int main() {
        int n;
        long long s1 = 0, s2 = 0;
        std::vector<int> a, b;
        bool fg = 0;
        scanf("%d", &n);
        for(int i = 0, t; i < n; ++i) {
                scanf("%d", &t);
                if(t > 0) a.push_back(t), s1 += t, fg = 0;
                else b.push_back(-t), s2 += -t, fg = 1;
        }
        bool u = 0;
        if(s1 > s2 || (s1 == s2 && cmp(a, b) == 1) || (s1 == s2 && cmp(a, b) == 0 && !fg)) u = 1;
        puts (u ? "first" : "second");
        return 0;
}
