#include<bits/stdc++.h>
using namespace std;
const int N = 1111;
int n;
std::pair<int, int> a[N], b[N];
int main(){
    scanf ("%d", &n);
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++ i){
        scanf ("%d", &a[i].first);
        a[i].second = i;
        s1 += a[i].first;
    }
    for (int i = 0; i < n; ++ i){
        scanf ("%d", &b[i].first);
        b[i].second = i;
        s2 += b[i].first;
    }
    if (s1 <= s2){
        sort (a, a + n, greater<pair<int,int> > ());
        sort (b, b + n);
    } else{
        sort (b, b + n, greater<pair<int,int> > ());
        sort (a, a + n);
    }
    for (int i = 0; i < n; ++ i)
        printf ("%d %d\n", a[i].second + 1, b[i].second + 1);
    return 0;
}
