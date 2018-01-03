import time
def init_tn(n, mod):
    s0 = 290797
    sm = 50515093
    tn = [s0 % mod]
    while len(tn) < n:
        s0 = s0 * s0 % sm
        tn.append(s0 % mod)
    return tn
    
def calc(p, n, mod):
    tn = init_tn(n+1, p)
    ans = 0
    tmp = 0
    i = len(tn) - 1
    while i >= 1:
        tmp = (tmp * p + tn[i]) % mod
        ans = (ans + tmp) % mod
        i -= 1
    return ans

if __name__=='__main__':
    st = time.time()
    # print(calc(3,10000,3**20))
    print(calc(61,10**7,61**10))
    print("time = {}".format(time.time()-st))
