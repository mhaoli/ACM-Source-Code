#include<bits/stdc++.h>
using namespace std;
map<int, long long> has;
map<int, long long>::iterator it;
long long dp(int x){
    it = has.find (x);
    if (it != has.end ()) return it->second;
    long long res = dp (x/2) + dp (x/3) + dp (x/4);
    if (res < x) res = x;
    return has[x] = res;
}
int main(){
    has[0] = 0;
    int n;
    while (scanf ("%d", &n) != EOF) printf ("%lld\n", dp (n));
    return 0;
}
