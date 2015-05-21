#include<bits/stdc++.h>
using namespace std;
const int N = 3333;
int a[N], b[N];
vector<pair<int, int> > ans;
int main(){
        int n; scanf ("%d", &n);
        for (int i = 0; i < n; ++i){
                scanf ("%d", a + i);
                b[i] = a[i];
        }
        sort (b, b + n);
        for (int j, i = 0; i < n; ++i) if (a[i] != b[i]){
                for (j = i+1; j < n; ++j) if (a[j] == b[i]){
                        swap (a[i], a[j]);
                        ans.push_back (make_pair (i, j));
                        break;
                }
        }
        printf ("%d\n", ans.size());
        for (int i = 0; i < (int)ans.size(); ++i)
                printf ("%d %d\n", ans[i].first, ans[i].second);
        return 0;
}
