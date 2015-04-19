#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
const int N = 111;
struct nod{
    int x, y, z, v;
    void read (){
        scanf ("%d%d%d", &x, &y, &z);
        v = x * y * z;
    }
    bool operator<(const nod&t)const{
        return z == t.z ? v > t.v : z > t.z;
    }
}a[N];
int main(){
    int n;
    while (scanf ("%d", &n) != EOF && n){
        for (int i = 0; i < n; ++ i) a[i].read ();
        std::sort (a, a + n);
        printf ("%d\n", a[0].v);
    }
    return 0;
}
