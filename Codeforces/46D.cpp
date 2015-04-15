#include<bits/stdc++.h>
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
int len[111], pos[111];
std::vector<int> vec;
int main(){
        int L, pre, suf, n;
        std::cin >> L >> pre >> suf >> n;
        for (int i = 1, op, x; i <= n; ++i){
                scanf ("%d%d", &op, &x);
                if (op == 1){
                        len[i] = x; pos[i] = -1;
                        if (x > L){
                                puts ("-1"); continue;
                        }
                        snuke (it, vec){
                                if (it == vec.begin()){
                                        if (pos[*it] >= suf + x){
                                                pos[i] = 0;
                                                vec.insert (it, i);
                                        }
                                } else{
                                        if (pos[*(it-1)] + len[*(it-1)] + pre + x + suf <= pos[*it]){
                                                pos[i] = pos[*(it-1)] + pre + len[*(it-1)];
                                                vec.insert (it, i);
                                        }
                                }
                                if (pos[i] != -1) break;
                        }
                        if (pos[i] == -1){
                                if (vec.empty ()){
                                        pos[i] = 0, vec.push_back (i);
                                } else if (pos[vec.back()] + len[vec.back()] + pre + x <= L){
                                        pos[i] = pos[vec.back()] + len[vec.back()] + pre;
                                        vec.push_back (i);
                                }
                        }
                        printf ("%d\n", pos[i]);
                } else{
                        snuke (it, vec) if (*it == x){
                                vec.erase (it); break;
                        }
                }
        }
        return 0;
}
