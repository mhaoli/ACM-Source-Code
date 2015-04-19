#include<bits/stdc++.h>
int solve (char *s, char *t, int l1, int l2){
    char *tmp;
    int i;
    for (i = 0; ; ++ i){
        if (l1 > l2){
            std::swap (l1, l2);
            tmp = s; s = t; t = tmp;
        }
        if (!s[0]) return i + l2;
        if (s[0] == 'L'){
            if (t[0] == 'L') ++ s, ++ t, -- l1, -- l2;
            else ++ t, -- l2;
        } else{
            if (t[0] == 'L') ++ s, -- l1;
            else ++ s, ++ t, -- l1, -- l2;
        }
    }
    return i;
}
char s[1111], t[1111];
int main(){
    scanf ("%s%s", s, t);
    printf ("%d\n", solve (s, t, strlen (s), strlen (t)));
    return 0;
}
