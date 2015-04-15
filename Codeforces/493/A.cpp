#include<bits/stdc++.h>
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
using namespace std;
string s[2];
int num[1111];
bool has[1111];
vector<pair<int, int> > ans;
int main() {
        for(int i = 0; i < 2; ++i) cin >> s[i];
        int n; scanf("%d", &n);
        char team[10], op[10];
        for(int i = 0, t, m; i < n; ++i) {
                scanf("%d%s%d%s", &t, team, &m, op);
                if(team[0] == 'a') m += 100;
                num[m] += op[0] == 'y' ? 1 : 2;
                if(num[m] >= 2 && !has[m]) ans.push_back(make_pair(m, t)), has[m] = 1;
        }
        snuke(it, ans) {
                cout << s[it->first >= 100] << " " << (it->first % 100) << " " << it->second << endl;
        }
        return 0;
}
