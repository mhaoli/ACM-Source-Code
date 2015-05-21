#include<bits/stdc++.h> 
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
using namespace std;
map<int, int> has;
vector<pair<int, int> > vec;
void calc(int &n, int fg) {
        scanf("%d", &n);
        has.clear();
        for(int i = 0, t; i < n; ++i)
                scanf("%d", &t), has[t]++;
        snuke(it, has) vec.push_back(make_pair(it->first, fg * it->second));
}
int main() {
        int n, m, s1, s2;
        calc(n, 1);
        calc(m, -1);
        s1 = n * 3; s2 = m * 3;
        int t = 0, t1 = s1, t2 = s2;
        sort(vec.begin(), vec.end());
        snuke(it, vec) {
                if((it + 1) != vec.end() && it->first == (it+1)->first) t = -1 * it->second;
                else {
                        if(t > 0) {
                                t2 -= t;
                                t1 -= it->second;
                        } else {
                                if(it->second > 0) t1 -= it->second;
                                else t2 += it->second;
                        }
                        if(t1 - t2 > s1 - s2) s1 = t1, s2 = t2;
                        t = 0;
                }
        }
        printf("%d:%d\n", s1, s2);
        return 0;
}
