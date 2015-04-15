#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
std::vector<int> a, b;
std::vector<std::pair<int, int> > ans;
int main() {
        int n, t1 = 0, t2 = 0; scanf("%d", &n);
        int last;
        for(int i = 0, t; i < n; ++i) {
                scanf("%d", &t);
                if(t == 1) ++t1, a.push_back(i), last = 1;
                else ++t2, b.push_back(i), last = 2;
        }
        if(t1 != t2) {
                if(t1 > t2 && last == 1) ans.push_back(std::make_pair(t1, 1));
                if(t2 > t1 && last == 2) ans.push_back(std::make_pair(t2, 1));
        }
        for(int p1, p2, i = 2; i <= n; ++i) {
                t1 = t2 = p1 = p2 = 0;
                while(p1 < (int)a.size() || p2 < (int)b.size()) {
                        if(p1 + i > (int)a.size() && p2 + i > (int)b.size()) {
                                break;
                        } else if(p1 + i <= (int)a.size() && p2 + i <= (int)b.size()) {
                                if(a[p1+i-1] < b[p2+i-1]) {
                                        p2 = upper_bound(b.begin(), b.end(), a[p1+i-1]) - b.begin();
                                        ++t1; p1 += i; last = 1;
                                } else{
                                        p1 = upper_bound(a.begin(), a.end(), b[p2+i-1]) - a.begin();
                                        ++t2; p2 += i; last = 2;
                                }
                        } else if(p1 + i <= (int)a.size()) {
                                p2 = upper_bound(b.begin(), b.end(), a[p1+i-1]) - b.begin();
                                ++t1; p1 += i; last = 1;
                        } else {
                                p1 = upper_bound(a.begin(), a.end(), b[p2+i-1]) - a.begin();
                                ++t2; p2 += i; last = 2;

                        }
                }
                if(p1 == (int)a.size() && p2 == (int)b.size() && t1 != t2) {
                        if(t1 > t2 && last == 1) ans.push_back(std::make_pair(t1, i));
                        if(t2 > t1 && last == 2) ans.push_back(std::make_pair(t2, i));
                }
        }
        printf("%d\n", (int)ans.size());
        if(ans.size() > 0) std::sort(ans.begin(), ans.end());
        snuke(it, ans) printf("%d %d\n", it->first, it->second);
        return 0;
}
