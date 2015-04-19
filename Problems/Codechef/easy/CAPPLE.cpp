#include<bits/stdc++.h>
std::set<int> st;
int main() {
        int _; scanf("%d", &_);
        for(int n; _--; ) {
                scanf("%d", &n);
                st.clear();
                for(int i = 0, t; i < n; ++i)
                        scanf("%d", &t), st.insert(t);
                printf("%d\n", (int)st.size());
        }
        return 0;
}
